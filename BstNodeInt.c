#include <string.h>
#include "BstNodeInt.h"

// Dodaje element do drzewa
void addElement(int value, int* addressOfPointerToRoot, int* count)
{
	// Sprawdzenie czy nie probujemy dodac duplikatu
	if (findPointerToElement(value, *addressOfPointerToRoot) != NULL)
	{
		printf("Istnieje element o takim kluczu, dodawanie duplikatow jest zabronione\n");
		return;
	}

	// Wyszukanie rodzica dla nowego elementu
	struct BstNodeInt *parent = findParentForElement(value, *addressOfPointerToRoot);

	// Tworzenie nowego elementu
	struct BstNodeInt *newElement = constructorINT(value, parent, count);

	//Ustawienie nowego elementu w rodzicu 
	setParentForElement(addressOfPointerToRoot, parent, newElement);
}

//Usuwa wybrany element
void deleteElement(int value, int* addressOfPointerToRoot, int* count) {
	//Wyszukanie wskaznika na usuwany element
	struct BstNodeInt* deleteNode = findPointerToElement(value, *addressOfPointerToRoot);
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
		changeKidOfSuccessorsParent(addressOfPointerToRoot, child, &next);

		//Usuwanie wezla
		destructor(deleteNode, next, count);
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}


//Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value, int addressOfRoot) {
	//Wyszukanie wskaznika na element
	struct BstNodeInt* element = findPointerToElement(value, addressOfRoot);
	if (element != NULL) {
		//Wyswietlenie odpowiedniego komunikatu
		printf("Element o wartosci : %d\n", value);
		//Wyswietlenie informacji o rodzicu
		if (element != addressOfRoot) printf("Rodzic: %d\n",element->parent->key);
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
void rotateLeft(int value, int* addressOfPointerToRoot) {
	struct BstNodeInt* node = findPointerToElement(value, *addressOfPointerToRoot);
	//Wykonanie rotacji
	int output = rotateNodeLeft(node, addressOfPointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if (output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
}

//Rotacja w prawo na wybranym elemencie
void rotateRight(int value, int* addressOfPointerToRoot) {
	struct BstNodeInt* node = findPointerToElement(value, *addressOfPointerToRoot);
	//Wykonanie rotacji
	int output = rotateNodeRight(node, addressOfPointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if(output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
	
}