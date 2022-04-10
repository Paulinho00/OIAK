#include <string.h>
#include "BstNodeInt.h"
#include "BstNode.h"
#include "Bst.h"


// Korzen drzewa
struct BstNodeInt *root = NULL;
struct BstNodeInt **pointerToRoot = &root;

// Liczba wezlow
int count = 0;

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
		case 5:{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			findElement(userInput);
		}; break;
		case 6: dswBalance(pointerToRoot, count); break;
		case 7:{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			rotateRight(userInput);
		}; break;
		case 8:{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			rotateLeft(userInput);
		}; break;
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
	struct BstNodeInt *parent = findParentForElement(value, root);

	// Tworzenie nowego elementu
	struct BstNodeInt *newElement = constructorINT(value, parent, &count);

	//Ustawienie nowego elementu w rodzicu 
	setParentForElement(pointerToRoot, parent, newElement);
}

//Usuwa wybrany element
void deleteElement(int value) {
	//Wyszukanie wskaznika na usuwany element
	struct BstNodeInt* deleteNode = findPointerToElement(value, root);
	if (deleteNode != NULL) {
		struct BstNodeInt* next;
		struct BstNodeInt* child;
		//Sprawdzenie czy element ma potomka
		next = (struct BstNodeInt*) findNextElement(&next, deleteNode);

		//Odczyt jedynego potomka nastepnika
		child = (struct BstNodeInt*) returnOnlyChild(next);

		//Sprawdzenie czy nastepnik ma jakiegos potomka
		if (child != NULL) {
			//Dodanie do dziecka rodzica nastepnika, 
			child->parent = next->parent;
		}

		//Zmiana wskaznikow na dzieci w rodzicu nastepnika
		changeKidOfSuccessorsParent(pointerToRoot, child, &next);

		//Usuwanie wezla
		destructor(deleteNode, next, &count);
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}

// Wyswietla zawartosc BST
void showElements()
{
	printf("\n");

	printNode("","", root);
}

//Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value) {
	//Wyszukanie wskaznika na element
	struct BstNodeInt* element = findPointerToElement(value, root);
	if (element != NULL) {
		//Wyswietlenie odpowiedniego komunikatu
		printf("Element o wartosci : %d\n", value);
		//Wyswietlenie informacji o rodzicu
		if (element != root) printf("Rodzic: %d\n",element->parent->key);
		else printf("Rodzic: Brak\n");
		//Wyswietlenie informacji o lewym nastepniku
		if (element->left != NULL) printf("Lewy nastepnik: %d\n", element->left->key);
		else printf("Lewy nastepnik: Brak\n");
		//Wyswietleie informacji o prawym nastepniku
		if (element->right != NULL) printf("Prawy nastepnik: %d\n", element->right->key);
		else printf("Prawy nastepnik: Brak\n\n");
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}

// Funkcja wypisujaca potomkow danego elementu
void printNode(char* prefix, char* childrenPrefix, struct BstNodeInt *node)
{
	if (node != NULL)
	{
		printf(" %s[%d]\n", prefix, node->key);
		struct BstNodeInt *next;
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
				printNode(addToPrefix, addToChildrenPrefix, node->left);
			}
			else
			{
				char *addToPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToPrefix, childrenPrefix);
				strcat(addToPrefix, " L--");
				char *addToChildrenPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToChildrenPrefix, childrenPrefix);
				strcat(addToChildrenPrefix, "      ");
				printNode(addToPrefix, addToChildrenPrefix, node->left);
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
			printNode(addToPrefix, addToChildrenPrefix, node->right);
		}
	}
}

//Rotacja w lewo na wybranym elemencie
void rotateLeft(int value) {
	struct BstNodeInt* node = findPointerToElement(value, root);
	//Wykonanie rotacji
	int output = rotateNodeLeft(node, pointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if (output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
}

//Rotacja w prawo na wybranym elemencie
void rotateRight(int value) {
	struct BstNodeInt* node = findPointerToElement(value, root);
	//Wykonanie rotacji
	int output = rotateNodeRight(node, pointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if(output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
	
}