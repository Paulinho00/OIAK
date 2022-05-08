//Funkcje wykorzystywane jedynie przy liczbach calkowitych

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
extern struct BstNodeInt *findPointerToElementInt(int* pointerToValue, struct BstNodeInt* root, int bytes, int isSigned);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNodeInt *findParentForElementInt(int* pointerToValue, struct BstNodeInt* root, int bytes, int isSigned);

//Dodaje element do drzewa
void addElementInt(int* pointerToValue, int* addressOfPointerToRoot, int* count,  int isSigned);

void printNodeInt(char* prefix, char* childrenPrefix, struct BstNodeInt *node);

//Usuwa wybrany element
void deleteElementInt(int* pointerToInt, int* addressOfPointerToRoot, int* count, int isSigned);

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElementInt(int* pointerToInt, int addressOfRoot, int isSigned);

// Rotacja w lewo na wybranym elemencie
void rotateLeftInt(int* pointerToInt, int* addressOfPointerToRoot, int isSigned);


// Rotacja w prawo na wybranym elemencie
void rotateRightInt(int* pointerToInt, int* addressOfPointerToRoot, int isSigned);

//Ustawia rodzica dla nowego elementu
extern void setParentForElementInt(int addressOfRoot, int addressOfParent, int addressOfNewElement, int bytes);

//Konwersja liczby zapisanej w pamieci na string dziesietny
extern char* convertIntToString(int* pointerToInt, int bytes);

//Zapis liczby dziesietnej w stringu w pamieci
extern int* convertStringToINT(char* number, int bytes);
