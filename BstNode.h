//Funkcje uniwersalne dla różnych typów danych

//Wyszukuje nastepnik przy usuwaniu
extern int findNextElement(int* addressOfPointerToNext, int addressOfDeleteNode);

//Zwraca wskaznik na jedyne dziecko elementu
extern int returnOnlyChild(int addressOfDeleteNode);

//Zmienia wskaznik na dziecko w rodzicu nastepnika, przy usuwaniu
extern void changeKidOfSuccessorsParent(int addressOfPointerToRoot, int addressOfChild, int addressOfNext);

//Zwalnianie pamieci
extern void destructor(int addressOfDeleteNode, int addressOfNext, int addressOfCount);

// Rownowazenie drzewa metoda DSW
extern void dswBalance(int* addressOfPointerToRoot, int count);

// Rotacja w lewo na wybranym elemencie
extern int rotateNodeLeft(int addressOfNode, int* addressOfPointerToRoot);

// Rotacja w prawo na wybranym elemencie
extern int rotateNodeRight(int addressOfNod, int* addressOfPointerToRoot);

// Usuwa cale drzewo
void dropTree(struct BstNodeInt *element);

//Odczyt drzewa z pliku
void readFromFile(char* fileName);

