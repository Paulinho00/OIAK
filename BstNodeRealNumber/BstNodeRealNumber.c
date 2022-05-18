#include <string.h>
#include <stdio.h>
#include "BstNodeRealNumber.h"


//Dodaje element do drzewa
void addElementRealNumber(int* pointerToIntPart, int* pointerToFractionalPart, int *addressOfPointerToRoot, int* count,  int isSigned)
{    
    // Sprawdzenie czy nie probujemy dodac duplikatu
	if (findPointerToElementRealNumber(pointerToIntPart, pointerToFractionalPart, *addressOfPointerToRoot, bytes, isSigned) != NULL)
	{ 
		printf("Istnieje element o takim kluczu, dodawanie duplikatow jest zabronione\n");
		return;
	}

    // Wyszukanie rodzica dla nowego elementu
	struct BstNodeRealNumber *parent = findParentForElementRealNumber(pointerToIntPart, pointerToFractionalPart ,*addressOfPointerToRoot, bytes, isSigned);

    //Tworzenie nowego elementu
	struct BstNodeRealNumber *newElement = constructorRealNumberNode(pointerToIntPart, pointerToFractionalPart, parent, count, isSigned);

    //Ustawienie nowego elementu w rodzicu 
	setParentForElementRealNumber(addressOfPointerToRoot, parent, newElement, bytes);

}

// Funkcja wypisujaca potomkow danego elementu
void printNodeRealNumber(char* prefix, char* childrenPrefix, struct BstNodeRealNumber *node)
{
	if (node != NULL)
	{
		char* keyInt = convertIntToString(node->keyIntPart, bytes);
        char* keyFraction = convertIntToString(node->keyFractionalPart, bytes);
		if(node->isSigned) printf(" %s[-%s.%s]\n", prefix, keyInt, keyFraction);
		else printf(" %s[%s.%s]\n", prefix, keyInt, keyFraction);
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