#include <string.h>
#include <stdio.h>
#include "BstNodeInt.h"
#include "BstNode.h"
#include "Bst.h"
#include "ConvertingBigNumbers/stringFunctions.h"

// Korzen drzewa
struct BstNodeInt *root = NULL;
int* pointerToRoot = &root;
int bytes = 16;
int* pointerToNumber;
int numberOfDigits = 0;

// Liczba wezlow
int count = 0;
int dataType = 0;

int main()
{
	while (1)
	{
		numberOfDigits = returnDigitNumber(bytes*8);
		// Wyswietlenie opcji w menu
		switch(dataType){
			case 0: printf("Typ danych: %d bajtowa liczba calkowita", bytes); break;
			case 1: printf("Typ danych: liczba rzeczywista z %d bajtowa czescia calkowita i %d bajtowa czescia ulamkowa", bytes, bytes);
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
		printf("9. Zmień rozmiar danych\n");
		printf("10. Zmień typ danych\n");
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
			readFromFile(fileName);
			free(fileName);		
		} break;
		case 2:
		{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			int isSigned = formateInput(userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			addElementInt(pointerToNumber, pointerToRoot, &count, isSigned);
		}; break;
		case 3:
		{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			int isSigned = formateInput(userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			deleteElementInt(pointerToNumber, pointerToRoot, &count, isSigned);
		}; break;
		case 4:
			showElements(); break;
		case 5:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			int isSigned = formateInput(userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			findElementInt(pointerToNumber, *pointerToRoot, isSigned);
		}; break;
		case 6: dswBalance(pointerToRoot, count); break;
		case 7:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			int isSigned = formateInput(userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			rotateRightInt(pointerToNumber, pointerToRoot, isSigned);
		}; break;
		case 8:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			int isSigned = formateInput(userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			rotateLeftInt(pointerToNumber, pointerToRoot, isSigned);
		}; break;
		case 9: changeDataSize(); break;
		case 10: changeDataType(); break;
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

	printNodeInt("","", root);
}

//Zmiana typu danych
void changeDataSize(){
	dropTree(root);
	printf("Podaj nowy rozmiar: ");
	scanf("%d", &bytes);
}

// Usuwa cale drzewo
void dropTree(struct BstNodeInt *element){
	if(element != NULL){
		dropTree(element->left);
		dropTree(element->right);
		deleteElementInt(element->key, pointerToRoot, &count, element->isSigned);
	}

}

void readFromFile(char* fileName){
	if(root != NULL){
		dropTree(root);
	}
	
	FILE *file = fopen(fileName, "r");

	if(!file){
		printf("Blad otwarcia pliku\n");
		return;
	}

	int numberOfElements = 0;
	//Odczyt rozmiaru pojedynczego elementu
	fscanf(file, "%d", &bytes);
	int maxLength = returnDigitNumber(bytes*8)+2;

	char* number = (char*) malloc (maxLength);
	fgets(number, maxLength, file);
	while(fgets(number, maxLength, file)){
		if(number[0] == '\n') continue;
		int len = strlen(number);
		if(number[len-1] == '\n' ) number[len-1] = '\0';
		int isSigned = formateInput(number);
		int* numberInMemory = convertStringToINT(number, bytes);
		addElementInt(numberInMemory, pointerToRoot, &count, isSigned);
	}


}

void changeDataType()
{
	while (1)
	{
		printf("\nWybierz typ danych:\n");
		printf("1. Liczba calkowita\n");
		printf("2. Liczba rzeczywista\n");
		printf("0. Cofnij\n");
		printf("Wybierz opcje: ");

		// Odczyt wyboru uzytkownika
		int userChoice;
		scanf("%d", &userChoice);

		switch (userChoice)
		{
			case 1:{
				dataType = 0;
				return;
			}

			case 2:{
				dataType = 1;
				return;
			}
			case 0: return;
			default: printf("Nie ma takiej opcji"); break;
		}
	}
}