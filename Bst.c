#include <string.h>
#include <stdio.h>
#include "BstNodeInt/BstNodeInt.h"
#include "BstNode.h"
#include "BstNodeRealNumber/BstNodeRealNumber.h"
#include "Bst.h"
#include "ConvertingBigNumbers/stringFunctions.h"

// Korzen drzewa
int root = NULL;
int* pointerToRoot = &root;
int bytes = 16;
int bytesFractionalPart = 16;
int* pointerToNumber;
int* poitnerToFractionalPart;
int numberOfDigits = 0;
int digitsInFractionalPart = 0;

// Liczba wezlow
int count = 0;
int dataType = 0;

int main()
{
	while (1)
	{
		numberOfDigits = returnDigitNumber(bytes*8);
		if(dataType == 1) numberOfDigits += digitsInFractionalPart+1;
		// Wyswietlenie opcji w menu
		switch(dataType){
			case 0: printf("Typ danych: %d bajtowa liczba calkowita", bytes); break;
			case 1: printf("Typ danych: liczba rzeczywista z %d bajtowa czescia calkowita i %d cyframi po przecinku", bytes, digitsInFractionalPart);
			case 2: printf("Typ danych: 1 bajtowy znak");
		}
		printf("\nWybierz opcje:\n");
		printf("1. Odczytaj dane z pliku\n");
		printf("2. Dodaj element do drzewa\n");
		printf("3. Usun wybrany element\n");
		printf("4. Wyswietl wszystkie wartosci\n");
		printf("5. Znajdz wartosc w drzewie\n");
		printf("6. Wykonaj rownowazenie algorytmem DSW\n");
		printf("7. Wykonaj rotacje w prawo dla wybranego elementu\n");
		printf("8. Wykonaj rotacje w lewo dla wybranego elementu\n");
		printf("9. Zmień typ danych\n");
		printf("0. Cofnij do menu glownego\n");
		printf("Podaj odpowiednia liczbe\n");

		// Odczyt wyboru uzytkownika
		int userChoice;
		scanf("%d", &userChoice);

		// Uruchomienie odpowiedniej funkcji w zaleznosci od wyboru
		switch (userChoice)
		{
		case 1:{
			char* fileName = (char*) malloc(20);
			scanf("%s", fileName);
			if(dataType == 1) readFromFileRealNumber(fileName);
			else if(dataType == 0 || dataType == 2) readFromFileInt(fileName);
			free(fileName);		
		} break;
		case 2:
		{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			if(dataType == 2) userInput = convertCharToDecimalString(userInput);
			int isSigned = formateInputWithoutSign(userInput);
			if(dataType == 1){
				char* fractionPart = returnFloatPart(userInput);
				fractionPart = fillBackZeroes(fractionPart, digitsInFractionalPart);
				char* intPart = returnIntPart(userInput);
				int* pointerToNumber = convertStringToINT(intPart, bytes);
				int* pointerToFractionalPart = convertStringToINT(fractionPart, bytesFractionalPart);
				free(userInput);
				addElementRealNumber(pointerToNumber, pointerToFractionalPart, pointerToRoot, &count, isSigned);
			}
			else if(dataType==0 || dataType== 2){
				pointerToNumber = convertStringToINT(userInput, bytes);
				free(userInput);
				addElementInt(pointerToNumber, pointerToRoot, &count, isSigned);
			}
		}; break;
		case 3:
		{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			if(dataType == 2) userInput = convertCharToDecimalString(userInput);
			int isSigned = formateInputWithoutSign(userInput);
			if(dataType == 1){
				char* fractionPart = returnFloatPart(userInput);
				fractionPart = fillBackZeroes(fractionPart, digitsInFractionalPart);
				char* intPart = returnIntPart(userInput);
				int* pointerToNumber = convertStringToINT(intPart, bytes);
				int* pointerToFractionalPart = convertStringToINT(fractionPart, bytesFractionalPart);
				free(userInput);
				deleteElementRealNumber(pointerToNumber, pointerToFractionalPart, pointerToRoot, &count, isSigned, bytesFractionalPart);
			}
			else if(dataType==0 || dataType== 2){
				pointerToNumber = convertStringToINT(userInput, bytes);
				free(userInput);
				deleteElementInt(pointerToNumber, pointerToRoot, &count, isSigned);
			}
		}; break;
		case 4:
			showElements(); break;
		case 5:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			if(dataType == 2) userInput = convertCharToDecimalString(userInput);
			int isSigned = formateInputWithoutSign(userInput);
			if(dataType==1){
				char* fractionPart = returnFloatPart(userInput);
				fractionPart = fillBackZeroes(fractionPart, digitsInFractionalPart);
				char* intPart = returnIntPart(userInput);
				int* pointerToNumber = convertStringToINT(intPart, bytes);
				int* pointerToFractionalPart = convertStringToINT(fractionPart, bytesFractionalPart);
				free(userInput);
				findElementRealNumber(pointerToNumber, pointerToFractionalPart, *pointerToRoot, isSigned);
			}
			else if(dataType==0 || dataType == 2){
				pointerToNumber = convertStringToINT(userInput, bytes);
				free(userInput);
				findElementInt(pointerToNumber, *pointerToRoot, isSigned);
			}
		}; break;
		case 6: dswBalance(pointerToRoot, count); break;
		case 7:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			if(dataType == 2) userInput = convertCharToDecimalString(userInput);
			int isSigned = formateInputWithoutSign(userInput);
			if(dataType == 1){
				char* fractionPart = returnFloatPart(userInput);
				fractionPart = fillBackZeroes(fractionPart, digitsInFractionalPart);
				char* intPart = returnIntPart(userInput);
				int* pointerToNumber = convertStringToINT(intPart, bytes);
				int* pointerToFractionalPart = convertStringToINT(fractionPart, bytesFractionalPart);
				free(userInput);
				rotateRightRealNumber(pointerToNumber, pointerToFractionalPart, pointerToRoot, isSigned);
			}
			else if(dataType == 0 || dataType == 2){
				pointerToNumber = convertStringToINT(userInput, bytes);
				free(userInput);
				rotateRightInt(pointerToNumber, pointerToRoot, isSigned);
			}
		}; break;
		case 8:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			if(dataType == 2) userInput = convertCharToDecimalString(userInput);
			int isSigned = formateInputWithoutSign(userInput);
			if(dataType == 1){
				char* fractionPart = returnFloatPart(userInput);
				fractionPart = fillBackZeroes(fractionPart, digitsInFractionalPart);
				char* intPart = returnIntPart(userInput);
				int* pointerToNumber = convertStringToINT(intPart, bytes);
				int* pointerToFractionalPart = convertStringToINT(fractionPart, bytesFractionalPart);
				free(userInput);
				rotateLeftRealNumber(pointerToNumber, pointerToFractionalPart, pointerToRoot, isSigned);
			}
			else if(dataType == 0 || dataType == 2){
				pointerToNumber = convertStringToINT(userInput, bytes);
				free(userInput);
				rotateLeftInt(pointerToNumber, pointerToRoot, isSigned);
			}
		}; break;
		case 9: changeDataType(); break;
		case 0:
			return;
		default:
			printf("Nie ma takiej opcji\n");
			break;
		}
	}
}



// Wyswietla zawartosc BST
void showElements()
{
	printf("\n");

	if(dataType == 0 || dataType == 2) printNodeInt("","", root);
	else if(dataType == 1) printNodeRealNumber("", "", root);
}

//Zmiana typu danych
void changeDataSize(){
	dropTreeInt(root);
	printf("Podaj nowy rozmiar: ");
	scanf("%d", &bytes);
	if(dataType == 1){
		printf("Podaj ilosc liczb po przecinku (minimalnie 3): ");
		scanf("%d", &digitsInFractionalPart );
		bytesFractionalPart = returnNeededBytes(digitsInFractionalPart);
	}
}

// Usuwa cale drzewo z l. calkowitymi
void dropTreeInt(struct BstNodeInt *element){
	if(element != NULL){
		dropTreeInt(element->left);
		dropTreeInt(element->right);
		deleteElementInt(element->key, pointerToRoot, &count, element->isSigned);
	}

}

//Usuwa cale drzewo z liczbami rzeczywistymi
void dropTreeRealNumber(struct BstNodeRealNumber *element){
	if(element != NULL){
		dropTreeRealNumber(element->left);
		dropTreeRealNumber(element->right);
		deleteElementRealNumber(element->keyIntPart, element->keyFractionalPart, pointerToRoot, &count, element->isSigned, bytesFractionalPart);
	}
}

void readFromFileInt(char* fileName){
	if(root != NULL){
		dropTreeInt(root);
	}
	
	FILE *file = fopen(fileName, "r");

	if(!file){
		printf("Blad otwarcia pliku\n");
		return;
	}

	int numberOfElements = 0;
	//Odczyt rozmiaru pojedynczego elementu
	if(dataType == 2) bytes = 1;
	else fscanf(file, "%d", &bytes);
	int maxLength = returnDigitNumber(bytes*8)+2;

	char* number = (char*) malloc (maxLength);
	if(dataType != 2) fgets(number, maxLength, file);
	while(fgets(number, maxLength, file)){
		if(number[0] == '\n') continue;
		int len = strlen(number);
		if(number[len-1] == '\n' ) number[len-1] = '\0';
		if(dataType == 2) number = convertCharToDecimalString(number);
		int isSigned = formateInputWithoutSign(number);
		int* numberInMemory = convertStringToINT(number, bytes);
		addElementInt(numberInMemory, pointerToRoot, &count, isSigned);
	}


}

void readFromFileRealNumber(char* fileName){
	if(root != NULL){
		dropTreeRealNumber(root);
	}
	
	FILE *file = fopen(fileName, "r");

	if(!file){
		printf("Blad otwarcia pliku\n");
		return;
	}

	//Odczyt rozmiaru pojedynczego elementu
	fscanf(file, "%d %d", &bytes, &digitsInFractionalPart);
	bytesFractionalPart = returnNeededBytes(digitsInFractionalPart);
	int maxLength = returnDigitNumber(bytes*8)+digitsInFractionalPart+3;
	char* number = (char*) malloc (maxLength);
	fgets(number, maxLength, file);
	while(fgets(number, maxLength, file)){
		if(number[0] == '\n') continue;
		int len = strlen(number);
		if(number[len-1] == '\n' ) number[len-1] = '\0';
		int isSigned = formateInputWithoutSign(number);
		char* fractionPart = returnFloatPart(number);
		fractionPart = fillBackZeroes(fractionPart, digitsInFractionalPart);
		char* intPart = returnIntPart(number);
		int* pointerToNumber = convertStringToINT(intPart, bytes);
		int* pointerToFractionalPart = convertStringToINT(fractionPart, bytesFractionalPart);
		addElementRealNumber(pointerToNumber, pointerToFractionalPart, pointerToRoot, &count, isSigned);
	}
}

void changeDataType()
{
	while (1)
	{
		printf("\nWybierz typ danych:\n");
		printf("1. Liczba calkowita\n");
		printf("2. Liczba rzeczywista\n");
		printf("3. Znak\n");
		printf("0. Cofnij\n");
		printf("Wybierz opcje: ");

		// Odczyt wyboru uzytkownika
		int userChoice;
		scanf("%d", &userChoice);

		switch (userChoice)
		{
			case 1:{
				if(dataType == 1) dropTreeRealNumber(root);
				if(dataType == 0 || dataType == 2) dropTreeInt(root);
				dataType = 0;
				changeDataSize();
				return;
			}

			case 2:{
				if(dataType == 0 || dataType == 2) dropTreeInt(root);
				if(dataType == 1) dropTreeRealNumber(root);
				dataType = 1;
				changeDataSize();
				return;
			}
			case 3:{
				if(dataType == 1) dropTreeRealNumber(root);
				if(dataType == 0 || dataType == 2) dropTreeInt(root);
				dataType = 2;
				bytes = 1;
			}
			case 0: return;
			default: printf("Nie ma takiej opcji"); break;
		}
	}
}