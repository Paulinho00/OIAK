#include <string.h>
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
		case 2:
		{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			addElement(pointerToNumber, pointerToRoot, &count);
		}; break;
		case 3:
		{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			deleteElement(pointerToNumber, pointerToRoot, &count);
		}; break;
		case 4:
			showElements(); break;
		case 5:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			findElement(pointerToNumber, pointerToRoot);
		}; break;
		case 6: dswBalance(pointerToRoot, count); break;
		case 7:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			rotateRight(pointerToNumber, pointerToRoot);
		}; break;
		case 8:{
			char* userInput = (char*) malloc(numberOfDigits);
			printf("Podaj wartosc ");
			scanf("%s", userInput);
			pointerToNumber = convertStringToINT(userInput, bytes);
			free(userInput);
			rotateLeft(pointerToNumber, pointerToRoot);
		}; break;
		case 9: changeDataSize(); break;
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

	printNode("","", root);
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
		deleteElement(element->key, pointerToRoot, &count);
	}

}