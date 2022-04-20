//Funkcje wykorzystywane jedynie przy liczbach calkowitych 32 bitowych

//DO WYRZUCENIA
// Element w BST
struct BstNodeInt
{
	// Wartosc wierzcholka
	int key;
	// Wskaznik na lewego potomka
	struct BstNodeInt *left;
	// Wskaznik na prawego potomka
	struct BstNodeInt *right;
	// Wskaznik na rodzica
	struct BstNodeInt *parent;
};

//Konstruktor dla struktury
extern struct BstNodeInt* constructorINT(int value, struct BstNodeInt* parent, int* count);

// Znajduje wskaznik na dany element
extern struct BstNodeInt *findPointerToElement(int value, struct BstNodeInt* root);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNodeInt *findParentForElement(int value, struct BstNodeInt* root);

//DO ZROBIENIA FUNKCJA KONWERTERUJACA STRING NA INT I ODWROTNIE

//DO PRZEROBIENIA  W ASM
void addElement(int value, int* addressOfPointerToRoot, int* count);

//DO PRZEROBIENIA W C
void printNode(char* prefix, char* childrenPrefix, struct BstNodeInt *node);

//DO PRZEROBIENIA W ASM
//Usuwa wybrany element
void deleteElement(int value, int* addressOfPointerToRoot, int* count);

//DO PRZEROBIENIA W ASM
// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value, int addressOfRoot);

//DO PRZEROBIENIA W ASM
// Rotacja w lewo na wybranym elemencie
void rotateLeft(int value, int* addressOfPointerToRoot);

//DO PRZEROBIENIA W ASM
// Rotacja w prawo na wybranym elemencie
void rotateRight(int value, int* addressOfPointerToRoot);