#include <string.h>

// Element w BST
struct BstNode
{
	// Wartosc wierzcholka
	int key;
	// Wskaznik na lewego potomka
	struct BstNode *left;
	// Wskaznik na prawego potomka
	struct BstNode *right;
	// Wskaznik na rodzica
	struct BstNode *parent;
};

// Korzen drzewa
struct BstNode *root = NULL;
struct BstNode **pointerToRoot = &root;

// Liczba wezlow
int count = 0;

int readUserInput();

// Odczytuje do drzewa, dane z pliku
void readFromFile(char filename[20]);

//Konstruktor dla struktury
extern struct BstNode *constructorINT(int value, struct BstNode* parent, int* count);

//Ustawia rodzica dla nowego elementu
extern void setParentForElement(struct BstNode** root, struct BstNode* parent, struct BstNode* newElement);

// Znajduje wskaznik na dany element
extern struct BstNode *findPointerToElement(int value, struct BstNode* root);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNode *findParentForElement(int value, struct BstNode* root);

void addElement(int value);

//Wyszukuje nastepnik przy usuwaniu
extern struct BstNode *findNextElement(struct BstNode** next, struct BstNode* deleteNode);

//Zwraca wskaznik na jedyne dziecko elementu
extern struct BstNode *returnOnlyChild(struct BstNode* deleteNode);

//Zmienia wskaznik na dziecko w rodzicu nastepnika, przy usuwaniu
extern void changeKidOfSuccessorsParent(struct BstNode** pointerToRoot, struct BstNode* child, struct BstNode** next);

// Usuwa wybrany element
void deleteElement(int value);

// Wyswietla zawartosc BST
void showElements();

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value);

// Rownowazenie drzewa metoda DSW
void dswBalance();

// Rotacja w lewo na wybranym elemencie
void rotateLeft(int value);

// Rotacja w lewo na wybranym elemencie
int rotateNodeLeft(struct BstNode *node);

// Rotacja w prawo na wybranym elemencie
void rotateRight(int value);

// Rotacja w prawo na wybranym elemencie
int rotateNodeRight(struct BstNode *node);

void print(char prefix[], char childrenPrefix[], struct BstNode *node);

// Znajduje nastepnik elementu
extern struct BstNode *findSuccessor(struct BstNode *element);

// Zwraca najmniejszy klucz zaczynajac od danego elementu
extern struct BstNode *findMinKey(struct BstNode *element);

// Usuwa cale drzewo
void dropTree(struct BstNode *element);

int main()
{
	while (1)
	{
		// Wyswietlenie opcji w menu
		printf("\nWybierz opcje:\n");
		printf("1. Odczytaj dane z pliku\n");
		printf("2. Dodaj element do drzewa\n");
		printf("3. Usun wybrany element\n");
		printf("4. Wyswietl wszystkie wartosci\n");
		printf("5. Znajdz wartosc w drzewie\n");
		printf("6. Wykonaj rownowazenie algorytmem DSW\n");
		printf("7. Wykonaj rotacje w prawo dla wybranego elementu\n");
		printf("8. Wykonaj rotacje w lewo dla wybranego elementu\n");
		printf("0. Cofnij do menu glownego\n");
		printf("Podaj odpowiednia liczbe\n");

		// Odczyt wyboru uzytkownika
		int userInput;
		userInput = readUserInput();

		// Uruchomienie odpowiedniej funkcji w zaleznosci od wyboru
		switch (userInput)
		{
		case 2:
		{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			addElement(userInput);
		}; break;
		case 3:
		{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			deleteElement(userInput);
		}; break;
		case 4:
			showElements(); break;
		case 0:
			return;
		default:
			printf("Nie ma takiej opcji\n");
			break;
		}
	}
}

// Funkcja odczytujaca i sprawdzajaca dane wprowadzone przez uzytkownika
int readUserInput()
{
	// Odczyt wyboru uzytkownika
	int userInput;
	scanf("%d", &userInput);
	return userInput;
};

// Dodaje element do drzewa
void addElement(int value)
{
	// Sprawdzenie czy nie probujemy dodac duplikatu
	if (findPointerToElement(value, root) != NULL)
	{
		printf("Istnieje element o takim kluczu, dodawanie duplikatow jest zabronione\n");
		return;
	}

	// Wyszukanie rodzica dla nowego elementu
	struct BstNode *parent = findParentForElement(value, root);

	// Tworzenie nowego elementu
	struct BstNode *newElement = constructorINT(value, parent, &count);

	//Ustawienie nowego elementu w rodzicu 
	setParentForElement(pointerToRoot, parent, newElement);
}

//Usuwa wybrany element
void deleteElement(int value) {
	//Wyszukanie wskaznika na usuwany element
	struct BstNode* deleteNode = findPointerToElement(value, root);
	if (deleteNode != NULL) {
		struct BstNode* next;
		struct BstNode* child;
		//Sprawdzenie czy element ma potomka
		next = findNextElement(&next, deleteNode);

		//Odczyt jedynego potomka nastepnika
		child = returnOnlyChild(next);

		//Sprawdzenie czy nastepnik ma jakiegos potomka
		if (child != NULL) {
			//Dodanie do dziecka rodzica nastepnika, 
			child->parent = next->parent;
		}

		//Zmiana wskaznikow na dzieci w rodzicu nastepnika
		changeKidOfSuccessorsParent(pointerToRoot, child, &next);

		//Sprawdzenie czy trzeba zamieniac pozycje nastepnika i usuwanego elementu
		if (deleteNode != next) {
			deleteNode->key = next->key;
			//Zwolnienie pamieci
			free(next);
		}
		else {
			//Zwolnienie pamieci
			free(deleteNode);
		}
		count--;
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}

// Wyswietla zawartosc BST
void showElements()
{
	printf("\n");

	print("","", root);
}

// Funkcja wypisujaca potomkow danego elementu
void print(char* prefix, char* childrenPrefix, struct BstNode *node)
{
	if (node != NULL)
	{
		printf(" %s[%d]\n", prefix, node->key);
		struct BstNode *next;
		if (node->left != NULL)
		{
			next = node->left;
			if (node->right != NULL)
			{
				char *addToPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToPrefix, childrenPrefix);
				strcat(addToPrefix, " L--");
				char *addToChildrenPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToChildrenPrefix, childrenPrefix);
				strcat(addToChildrenPrefix, " |   ");
				print(addToPrefix, addToChildrenPrefix, node->left);
			}
			else
			{
				char *addToPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToPrefix, childrenPrefix);
				strcat(addToPrefix, " L--");
				char *addToChildrenPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToChildrenPrefix, childrenPrefix);
				strcat(addToChildrenPrefix, "      ");
				print(addToPrefix, addToChildrenPrefix, node->left);
			}
		}
		if (node->right != NULL)
		{
			char *addToPrefix = (char*) malloc((strlen(childrenPrefix)*sizeof(char))+6);
			strcpy(addToPrefix, childrenPrefix);
			strcat(addToPrefix, " P--");
			char *addToChildrenPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
			strcpy(addToChildrenPrefix, childrenPrefix);
			strcat(addToChildrenPrefix, "      ");
			print(addToPrefix, addToChildrenPrefix, node->right);
		}
	}
}
