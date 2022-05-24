#include <string.h>
#include <stdio.h>
#include "BstNodeInt.h"
#include "../ConvertingBigNumbers/stringFunctions.h"

// Dodaje element do drzewa
void addElementInt(int* pointerToValue, int* addressOfPointerToRoot,int* count, int isSigned)
{
	// Sprawdzenie czy nie probujemy dodac duplikatu
	if (findPointerToElementInt(pointerToValue, *addressOfPointerToRoot, bytes, isSigned) != NULL)
	{
		printf("Istnieje element o takim kluczu, dodawanie duplikatow jest zabronione\n");
		return;
	}

	// Wyszukanie rodzica dla nowego elementu
	struct BstNodeInt *parent = findParentForElementInt(pointerToValue, *addressOfPointerToRoot, bytes, isSigned);

	// Tworzenie nowego elementu
	struct BstNodeInt *newElement = constructorINT(pointerToValue, parent, count, isSigned);

	//Ustawienie nowego elementu w rodzicu 
	setParentForElementInt(addressOfPointerToRoot, parent, newElement, bytes);
}

//Usuwa wybrany element
void deleteElementInt(int* pointerToValue, int* addressOfPointerToRoot, int* count, int isSigned) {
	//Wyszukanie wskaznika na usuwany element
	struct BstNodeInt* deleteNode = findPointerToElementInt(pointerToValue, *addressOfPointerToRoot, bytes, isSigned);
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
		destructorINT(deleteNode, next, count);
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}


//Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElementInt(int* pointerToValue, int addressOfRoot, int isSigned) {
	//Wyszukanie wskaznika na element
	struct BstNodeInt* element = findPointerToElementInt(pointerToValue, addressOfRoot, bytes, isSigned);
	if (element != NULL) {
		char* number = convertIntToString(pointerToValue,bytes);
		if(dataType == 2) convertAsciiValueToChar(number);
		//Wyswietlenie odpowiedniego komunikatu
		if(isSigned) printf("Element o wartosci : -%s\n", number);
		else printf("Element o wartosci : %s\n", number);
		//Wyswietlenie informacji o rodzicu
		if (element != addressOfRoot) {
			number = convertIntToString(element->parent->key, bytes);
			if(dataType == 2) convertAsciiValueToChar(number);
			if(element->isSigned) printf("Rodzic: -%s\n",number);
			else printf("Rodzic: %s\n",number);

		}
		else printf("Rodzic: Brak\n");
		//Wyswietlenie informacji o lewym nastepniku
		if (element->left != NULL) {
			number = convertIntToString(element->left->key, bytes);
			if(dataType == 2) convertAsciiValueToChar(number);
			if(element->left->isSigned) printf("Lewy potomek: -%s\n", number);
			else printf("Lewy potomek: %s\n", number);
		}
		else printf("Lewy potomek: Brak\n");
		//Wyswietleie informacji o prawym nastepniku
		if (element->right != NULL) {
			number = convertIntToString(element->right->key, bytes);
			if(dataType == 2) convertAsciiValueToChar(number);
			if(element->right->isSigned) printf("Prawy potomek: -%s\n", number);
			else printf("Prawy potomek: %s\n", number);
		}
		else printf("Prawy potomek: Brak\n\n");
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}

// Funkcja wypisujaca potomkow danego elementu
void printNodeInt(char* prefix, char* childrenPrefix, struct BstNodeInt *node)
{
	if (node != NULL)
	{
		char* number = convertIntToString(node->key, bytes);

		if(dataType == 2) convertAsciiValueToChar(number);
		if(node->isSigned) printf(" %s[-%s]\n", prefix, number);
		else printf(" %s[%s]\n", prefix, number);

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
				printNodeInt(addToPrefix, addToChildrenPrefix, node->left);
			}
			else
			{
				char *addToPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToPrefix, childrenPrefix);
				strcat(addToPrefix, " L--");
				char *addToChildrenPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToChildrenPrefix, childrenPrefix);
				strcat(addToChildrenPrefix, "      ");
				printNodeInt(addToPrefix, addToChildrenPrefix, node->left);
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
			printNodeInt(addToPrefix, addToChildrenPrefix, node->right);
		}
	}
	
}

//Rotacja w lewo na wybranym elemencie
void rotateLeftInt(int* pointerToValue, int* addressOfPointerToRoot, int isSigned) {
	struct BstNodeInt* node = findPointerToElementInt(pointerToValue, *addressOfPointerToRoot, bytes, isSigned);
	//Wykonanie rotacji
	int output = rotateNodeLeft(node, addressOfPointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if (output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
}

//Rotacja w prawo na wybranym elemencie
void rotateRightInt(int* pointerToValue, int* addressOfPointerToRoot, int isSigned) {
	struct BstNodeInt* node = findPointerToElementInt(pointerToValue, *addressOfPointerToRoot, bytes, isSigned);
	//Wykonanie rotacji
	int output = rotateNodeRight(node, addressOfPointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if(output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
	
}