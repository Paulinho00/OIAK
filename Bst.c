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

// Liczba wezlow
int count;

// Odczytuje do drzewa, dane z pliku
void readFromFile(char filename[20]);

// Znajduje wskaznik na dany element
extern struct BstNode *findPointerToElement(int value, struct BstNode* root);

int readUserInput();

void addElement(int value);

// Usuwa wybrany element
void deleteElement(int value);

// Wyswietla zawartosc BST
void showElements();

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value);

// Generowanie okreslonej liczby wartosci w strukturze
void fillBst(int amount);

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
struct BstNode *findSuccessor(struct BstNode *element);

// Zwraca najmniejszy klucz zaczynajac od danego elementu
struct BstNode *findMinKey(struct BstNode *element);

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
		printf("6. Wygeneruj wartosci losowe\n");
		printf("7. Wykonaj rownowazenie algorytmem DSW\n");
		printf("8. Wykonaj rotacje w prawo dla wybranego elementu\n");
		printf("9. Wykonaj rotacje w lewo dla wybranego elementu\n");
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

	struct BstNode *parent = NULL;
	struct BstNode *currentNode = root;
	// Wyszukanie rodzica dla nowego elementu
	while (currentNode != NULL)
	{
		parent = currentNode;
		if (value > currentNode->key)
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}

	// Tworzenie nowego elementu
	struct BstNode *newElement = (struct BstNode*) malloc(sizeof(struct BstNode));
	newElement->key = value;
	newElement->parent = parent;
	newElement->left = NULL;
	newElement->right = NULL;
	count++;

	// Sprawdzenie czy drzewo jest puste
	if (parent == NULL)
	{
		root = newElement;
	}
	else
	{
		if (value > parent->key)
			parent->right = newElement;
		else
			parent->left = newElement;
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
		printf("%s[%d]\n", prefix, node->key);
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
				strcat(addToChildrenPrefix, "  |   ");
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
