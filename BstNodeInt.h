//Funkcje wykorzystywane jedynie przy liczbach calkowitych 32 bitowych

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

void addElement(int value, int* addressOfPointerToRoot, int* count);

void printNode(char* prefix, char* childrenPrefix, struct BstNodeInt *node);

//Usuwa wybrany element
void deleteElement(int value, int* addressOfPointerToRoot, int* count);

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value, int addressOfRoot);

// Rotacja w lewo na wybranym elemencie
void rotateLeft(int value, int* addressOfPointerToRoot);

// Rotacja w prawo na wybranym elemencie
void rotateRight(int value, int* addressOfPointerToRoot);