extern int bytes;
extern int bytesFractionalPart;
extern int digitsInFractionalPart;

// Element w BST
struct BstNodeRealNumber
{
	// Wartosc wierzcholka - czesc calkowita
	int* keyIntPart;
	// Wskaznik na lewego potomka
	struct BstNodeRealNumber *left;
	// Wskaznik na prawego potomka
	struct BstNodeRealNumber *right;
	// Wskaznik na rodzica
	struct BstNodeRealNumber *parent;
	// Wartosc wierzcholka - czesc ulamkowa
    int* keyFractionalPart;
	//Przechowuje informacje o znaku liczby
	int isSigned;
};

//Konstruktor dla struktury
extern struct BstNodeRealNumber* constructorRealNumberNode(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* parent, int* count, int isSigned);

// Znajduje wskaznik na dany element
extern struct BstNodeRealNumber* findPointerToElementRealNumber(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* root, int bytes, int isSigned, int bytesFractionalPart);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNodeRealNumber* findParentForElementRealNumber(int* pointerToIntValue, int* pointerToFractionalPart, struct BstNodeRealNumber* root, int bytes, int isSigned, int bytesFractionalPart);

//Dodaje element do drzewa
void addElementRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int* count,  int isSigned);

void printNodeRealNumber(char* prefix, char* childrenPrefix, struct BstNodeRealNumber *node);

//Usuwa wybrany element
void deleteElementRealNumber(int* pointerToValue, int* pointerToFractionalPart,  int* addressOfPointerToRoot, int* count, int isSigned, int bytesFractionalPart);

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElementRealNumber(int* pointerToValue, int* pointerToFractionalPart, int addressOfRoot, int isSigned);

// Rotacja w lewo na wybranym elemencie
void rotateLeftRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int isSigned);


// Rotacja w prawo na wybranym elemencie
void rotateRightRealNumber(int* pointerToValue, int* pointerToFractionalPart, int* addressOfPointerToRoot, int isSigned);

//Ustawia rodzica dla nowego elementu
extern void setParentForElementRealNumber(int addressOfRoot, int addressOfParent, int addressOfNewElement, int bytes, int bytesFractionalPart);

// Usuwa cale drzewo z liczba rzeywistymi
void dropTreeRealNumber(struct BstNodeRealNumber *element);

//Zwalnianie pamieci
extern void destructorRealNumber(int addressOfDeleteNode, int addressOfNext, int addressOfCount);

//Zmienia wskaznik na dziecko w rodzicu nastepnika, przy usuwaniu
extern void changeKidOfSuccessorsParentRealNumber(int addressOfPointerToRoot, int addressOfChild, int addressOfNext);


