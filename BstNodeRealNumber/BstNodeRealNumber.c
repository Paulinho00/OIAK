#include <string.h>
#include <stdio.h>
#include "BstNodeRealNumber.h"
#include "../ConvertingBigNumbers/stringFunctions.h"


//Dodaje element do drzewa
void addElementRealNumber(int* pointerToIntPart, int* pointerToFractionalPart, int *addressOfPointerToRoot, int* count,  int isSigned)
{    
    // Sprawdzenie czy nie probujemy dodac duplikatu
	if (findPointerToElementRealNumber(pointerToIntPart, pointerToFractionalPart, *addressOfPointerToRoot, bytes, isSigned, bytesFractionalPart) != NULL)
	{ 
		printf("Istnieje element o takim kluczu, dodawanie duplikatow jest zabronione\n");
		return;
	}

    // Wyszukanie rodzica dla nowego elementu
	struct BstNodeRealNumber *parent = findParentForElementRealNumber(pointerToIntPart, pointerToFractionalPart ,*addressOfPointerToRoot, bytes, isSigned, bytesFractionalPart);

    //Tworzenie nowego elementu
	struct BstNodeRealNumber *newElement = constructorRealNumberNode(pointerToIntPart, pointerToFractionalPart, parent, count, isSigned);

    //Ustawienie nowego elementu w rodzicu 
	setParentForElementRealNumber(addressOfPointerToRoot, parent, newElement, bytes, bytesFractionalPart);

}

//Usuwa wybrany element
void deleteElementRealNumber(int* pointerToValue, int* pointerToFractionalPart,  int* addressOfPointerToRoot, int* count, int isSigned, int bytesFractionalPart){
	//Wyszukanie wskaznika na usuwany element
	struct BstNodeRealNumber* deleteNode = findPointerToElementRealNumber(pointerToValue, pointerToFractionalPart, *addressOfPointerToRoot, bytes, isSigned, bytesFractionalPart );
	if (deleteNode != NULL) {
		struct BstNodeRealNumber* next;
		struct BstNodeRealNumber* child;
		//Sprawdzenie czy element ma potomka
		next = (struct BstNodeRealNumber*) findNextElement(&next, deleteNode);

		//Odczyt jedynego potomka nastepnika
		child = (struct BstNodeRealNumber*) returnOnlyChild(next);

		//Sprawdzenie czy nastepnik ma jakiegos potomka
		if (child != NULL) {
			//Dodanie do dziecka rodzica nastepnika, 
			child->parent = next->parent;
		}

		//Zmiana wskaznikow na dzieci w rodzicu nastepnika
		changeKidOfSuccessorsParent(addressOfPointerToRoot, child, &next);

		//Usuwanie wezla
		destructorRealNumber(deleteNode, next, count);
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}

// Funkcja wypisujaca potomkow danego elementu
void printNodeRealNumber(char* prefix, char* childrenPrefix, struct BstNodeRealNumber *node)
{
	if (node != NULL)
	{
		char* keyInt = convertIntToString(node->keyIntPart, bytes);
        char* keyFraction = convertIntToString(node->keyFractionalPart, bytesFractionalPart);
		keyFraction = fillLeadingZeroes(keyFraction, digitsInFractionalPart);
		keyFraction[digitsInFractionalPart] = 0;
		if(node->isSigned) printf(" %s[-%s.%s]\n", prefix, keyInt, keyFraction);
		else printf(" %s[%s.%s]\n", prefix, keyInt, keyFraction);
		struct BstNodeRealNumber *next;
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
				printNodeRealNumber(addToPrefix, addToChildrenPrefix, node->left);
			}
			else
			{
				char *addToPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToPrefix, childrenPrefix);
				strcat(addToPrefix, " L--");
				char *addToChildrenPrefix = (char*) malloc(strlen(childrenPrefix)*sizeof(char)+6);
				strcpy(addToChildrenPrefix, childrenPrefix);
				strcat(addToChildrenPrefix, "      ");
				printNodeRealNumber(addToPrefix, addToChildrenPrefix, node->left);
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
			printNodeRealNumber(addToPrefix, addToChildrenPrefix, node->right);
		}
	}
	
}

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElementRealNumber(int* pointerToValue, int* pointerToFractionalPart, int addressOfRoot, int isSigned){
	//Wyszukanie wskaznika na element
	struct BstNodeRealNumber* element = findPointerToElementRealNumber(pointerToValue, pointerToFractionalPart, addressOfRoot, bytes, isSigned, bytesFractionalPart);
	if (element != NULL) {
		char* keyInt = convertIntToString(pointerToValue, bytes);
        char* keyFraction = convertIntToString(pointerToFractionalPart, bytesFractionalPart);
		keyFraction = fillLeadingZeroes(keyFraction, digitsInFractionalPart);
		keyFraction[digitsInFractionalPart] = 0;
		//Wyswietlenie odpowiedniego komunikatu
		if(isSigned) printf("Element o wartości: -%s.%s\n", keyInt, keyFraction);
		else printf("Element o wartości: %s.%s\n", keyInt, keyFraction);
		//Wyswietlenie informacji o rodzicu
		if (element != addressOfRoot) {
			keyInt = convertIntToString(element->parent->keyIntPart, bytes);
			keyFraction = convertIntToString(element->parent->keyFractionalPart, bytesFractionalPart);
			keyFraction = fillLeadingZeroes(keyFraction, digitsInFractionalPart);
			keyFraction[digitsInFractionalPart] = 0;
			if(element->isSigned) printf("Rodzic: -%s.%s\n", keyInt, keyFraction);
			else printf("Rodzic: %s.%s\n", keyInt, keyFraction);

		}
		else printf("Rodzic: Brak\n");
		//Wyswietlenie informacji o lewym nastepniku
		if (element->left != NULL) {
			keyInt = convertIntToString(element->left->keyIntPart, bytes);
			keyFraction = convertIntToString(element->left->keyFractionalPart, bytesFractionalPart);
			keyFraction = fillLeadingZeroes(keyFraction, digitsInFractionalPart);
			keyFraction[digitsInFractionalPart] = 0;
			if(element->isSigned) printf("Lewy potomek: -%s.%s\n", keyInt, keyFraction);
			else printf("Lewy potomek: %s.%s\n", keyInt, keyFraction);
		}
		else printf("Lewy potomek: Brak\n");

		//Wyswietleie informacji o prawym nastepniku
		if (element->right != NULL) {
			keyInt = convertIntToString(element->right->keyIntPart, bytes);
			keyFraction = convertIntToString(element->right->keyFractionalPart, bytesFractionalPart);
			keyFraction = fillLeadingZeroes(keyFraction, digitsInFractionalPart);
			keyFraction[digitsInFractionalPart] = 0;
			if(element->isSigned) printf("Prawy potomek: -%s.%s\n", keyInt, keyFraction);
			else printf("Prawy potomek: %s.%s\n", keyInt, keyFraction);
		}
		else printf("Prawy potomek: Brak\n\n");
	}
	else {
		printf("Nie ma takiego elementu\n");
	}
}

// Rotacja w lewo na wybranym elemencie
void rotateLeftRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int isSigned){
	struct BstNodeRealNumber* node = findPointerToElementRealNumber(pointerToValue, pointerToFractionalPart, *addressOfPointerToRoot, bytes, isSigned, bytesFractionalPart);
	//Wykonanie rotacji
	int output = rotateNodeLeft(node, addressOfPointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if (output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
}


// Rotacja w prawo na wybranym elemencie
void rotateRightRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int isSigned){
	struct BstNodeRealNumber* node = findPointerToElementRealNumber(pointerToValue, pointerToFractionalPart, *addressOfPointerToRoot, bytes, isSigned, bytesFractionalPart);
	//Wykonanie rotacji
	int output = rotateNodeRight(node, addressOfPointerToRoot);
	if (output == -1) printf("Nie ma takiego elementu\n");
	else if (output == -2) printf("Niemozliwe jest wykonanie takiej rotacji dla tego elementu\n");
}
