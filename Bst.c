#include <string.h>
#include "BstNodeInt.h"
#include "BstNode.h"
#include "Bst.h"


// Korzen drzewa
struct BstNodeInt *root = NULL;
int* pointerToRoot = &root;

// Liczba wezlow
int count = 0;
int dataType = 0;

int main()
{
	while (1)
	{
		// Wyswietlenie opcji w menu
		switch(dataType){
			case 0: printf("Typ danych: 4 bajtowa liczba calkowita"); break;
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
			addElement(userInput, pointerToRoot, &count);
		}; break;
		case 3:
		{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			deleteElement(userInput, pointerToRoot, &count);
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
			findElement(userInput, root);
		}; break;
		case 6: dswBalance(pointerToRoot, count); break;
		case 7:{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			rotateRight(userInput, pointerToRoot);
		}; break;
		case 8:{
			printf("Podaj wartosc ");
			userInput = readUserInput();
			if (userInput == -1)
			{
				break;
			}
			rotateLeft(userInput, pointerToRoot);
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

// Funkcja odczytujaca i sprawdzajaca dane wprowadzone przez uzytkownika
int readUserInput()
{
	// Odczyt wyboru uzytkownika
	int userInput;
	scanf("%d", &userInput);
	return userInput;
};

// Wyswietla zawartosc BST
void showElements()
{
	printf("\n");

	printNode("","", root);
}

//Zmiana typu danych
void changeDataType(){
	if(dataType < 1) dataType++;
	else dataType = 0;
}