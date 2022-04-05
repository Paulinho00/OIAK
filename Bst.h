int readUserInput();

// Odczytuje do drzewa, dane z pliku
void readFromFile(char filename[20]);

//Konstruktor dla struktury
extern struct BstNode *constructorINT(int value, struct BstNode* parent, int* count);

//Ustawia rodzica dla nowego elementu
extern void setParentForElement(struct BstNode** root, struct BstNode* parent, struct BstNode* newElement);

// Znajduje wskaznik na dany element
extern struct BstNode *findPointerToElement(int value, struct BstNode* root);

//Znajduje wskaznik na rodzica nowego elementu
extern struct BstNode *findParentForElement(int value, struct BstNode* root);

void addElement(int value);

//Wyszukuje nastepnik przy usuwaniu
extern struct BstNode *findNextElement(struct BstNode** next, struct BstNode* deleteNode);

//Zwraca wskaznik na jedyne dziecko elementu
extern struct BstNode *returnOnlyChild(struct BstNode* deleteNode);

//Zmienia wskaznik na dziecko w rodzicu nastepnika, przy usuwaniu
extern void changeKidOfSuccessorsParent(struct BstNode** pointerToRoot, struct BstNode* child, struct BstNode** next);

//Zwalnianie pamieci
extern void destructor(struct BstNode* deleteNode, struct BstNode* next, int* count);

//Usuwa wybrany element
void deleteElement(int value);

//Wyswietla zawartosc BST
void showElements();

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value);

// Rownowazenie drzewa metoda DSW
void dswBalance();

// Rotacja w lewo na wybranym elemencie
void rotateLeft(int value);

// Rotacja w lewo na wybranym elemencie
int rotateNodeLeft(struct BstNode *node);

// Rotacja w prawo na wybranym elemencie
void rotateRight(int value);

// Rotacja w prawo na wybranym elemencie
extern int rotateNodeRight(struct BstNode *node, struct BstNode** root);

void print(char prefix[], char childrenPrefix[], struct BstNode *node);

//Funckaj zwracajaca logarytm binarny z liczby
extern int binaryLogarithm(int number);

//Funkcja obliczajaca potege liczby
extern int pow(int base, int exponent);

// Znajduje nastepnik elementu
extern struct BstNode *findSuccessor(struct BstNode *element);

// Zwraca najmniejszy klucz zaczynajac od danego elementu
extern struct BstNode *findMinKey(struct BstNode *element);

// Usuwa cale drzewo
void dropTree(struct BstNode *element);