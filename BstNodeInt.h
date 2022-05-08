//Funkcje wykorzystywane jedynie przy liczbach calkowitych 32 bitowych

extern int bytes;

// Element w BST
struct BstNodeInt
{
	// Wartosc wierzcholka
	int* key;
	// Wskaznik na lewego potomka
	struct BstNodeInt *left;
	// Wskaznik na prawego potomka
	struct BstNodeInt *right;
	// Wskaznik na rodzica
	struct BstNodeInt *parent;
	//Przechowuje informacje o znaku liczby
	int isSigned;
};

//Konstruktor dla struktury
extern struct BstNodeInt* constructorINT(int* pointerToValue, struct BstNodeInt* parent, int* count, int isSigned);

// Znajduje wskaznik na dany element
extern struct BstNodeInt *findPointerToElement(int* pointerToValue, struct BstNodeInt* root, int bytes, int isSigned);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNodeInt *findParentForElement(int* pointerToValue, struct BstNodeInt* root, int bytes, int isSigned);

//Dodaje element do drzewa
void addElement(int* pointerToValue, int* addressOfPointerToRoot, int* count,  int isSigned);

//DO PRZEROBIENIA W C
void printNode(char* prefix, char* childrenPrefix, struct BstNodeInt *node);

//DO PRZEROBIENIA W ASM
//Usuwa wybrany element
void deleteElement(int* pointerToInt, int* addressOfPointerToRoot, int* count, int isSigned);

//DO PRZEROBIENIA W ASM
// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int* pointerToInt, int addressOfRoot, int isSigned);

//DO PRZEROBIENIA W ASM
// Rotacja w lewo na wybranym elemencie
void rotateLeft(int* pointerToInt, int* addressOfPointerToRoot, int isSigned);

//DO PRZEROBIENIA W ASM
// Rotacja w prawo na wybranym elemencie
void rotateRight(int* pointerToInt, int* addressOfPointerToRoot, int isSigned);

//Ustawia rodzica dla nowego elementu
extern void setParentForElement(int addressOfRoot, int addressOfParent, int addressOfNewElement, int bytes);

//Konwersja liczby zapisanej w pamieci na string dziesietny
extern char* convertIntToString(int* pointerToInt, int bytes);

//Zapis liczby dziesietnej w stringu w pamieci
extern int* convertStringToINT(char* number, int bytes);
