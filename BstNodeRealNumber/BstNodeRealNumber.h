extern int bytes;

// Element w BST
struct BstNodeRealNumber
{
	// Wartosc wierzcholka - czesc calkowita
	int* keyIntPart;
    // Wartosc wierzcholka - czesc ulamkowa
    int* keyFractionalPart;
	// Wskaznik na lewego potomka
	struct BstNodeRealNumber *left;
	// Wskaznik na prawego potomka
	struct BstNodeRealNumber *right;
	// Wskaznik na rodzica
	struct BstNodeRealNumber *parent;
	//Przechowuje informacje o znaku liczby
	int isSigned;
};

//Konstruktor dla struktury
extern struct BstNodeRealNumber* constructorRealNumberNode(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* parent, int* count, int isSigned);

// Znajduje wskaznik na dany element
extern struct BstNodeRealNumber* findPointerToElementRealNumber(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* root, int bytes, int isSigned);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNodeRealNumber* findParentForElementRealNumber(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* root, int bytes, int isSigned);

//Dodaje element do drzewa
void addElementRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int* count,  int isSigned);

void printNodeRealNumber(char* prefix, char* childrenPrefix, struct BstNodeRealNumber *node);

//Usuwa wybrany element
void deleteElementRealNumber(int* pointerToValue, int* pointerToFractionalPart,  int* addressOfPointerToRoot, int* count, int isSigned);

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElementRealNumber(int* pointerToValue, int* pointerToFractionalPart, int addressOfRoot, int isSigned);

// Rotacja w lewo na wybranym elemencie
void rotateLeftRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int isSigned);


// Rotacja w prawo na wybranym elemencie
void rotateRightRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int isSigned);

//Ustawia rodzica dla nowego elementu
extern void setParentForElementRealNumber(int addressOfRoot, int addressOfParent, int addressOfNewElement, int bytes);
