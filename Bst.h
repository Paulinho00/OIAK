int readUserInput();

// Odczytuje do drzewa, dane z pliku
void readFromFile(char filename[20]);

//Wyswietla zawartosc BST
void showElements();

void addElement(int value);

void printNode(char* prefix, char* childrenPrefix, struct BstNodeInt *node);

//Usuwa wybrany element
void deleteElement(int value);

// Wyszukiwanie pozycji na ktorym znajduje sie podana wartosc
void findElement(int value);

// Rotacja w lewo na wybranym elemencie
void rotateLeft(int value);

// Rotacja w prawo na wybranym elemencie
void rotateRight(int value);

//Funckaj zwracajaca logarytm binarny z liczby
extern int binaryLogarithm(int number);

//Funkcja obliczajaca potege liczby
extern int pow(int base, int exponent);