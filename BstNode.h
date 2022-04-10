//Funkcje uniwersalne dla różnych typów danych

//Ustawia rodzica dla nowego elementu
extern void setParentForElement(int AddressOfRoot, int AddressOfParent, int AddressOfNewElement);

//Wyszukuje nastepnik przy usuwaniu
extern int findNextElement(int* AddressOfPointerToNext, int AddressOfDeleteNode);

//Zwraca wskaznik na jedyne dziecko elementu
extern int returnOnlyChild(int AddressOfDeleteNode);

//Zmienia wskaznik na dziecko w rodzicu nastepnika, przy usuwaniu
extern void changeKidOfSuccessorsParent(int AddressOfPointerToRoot, int AddressOfChild, int AddressOfNext);

//Zwalnianie pamieci
extern void destructor(int AddressOfDeleteNode, int AddressOfNext, int AddressOfCount);

// Rownowazenie drzewa metoda DSW
extern void dswBalance(int* AddressOfPointerToRoot, int count);

// Rotacja w lewo na wybranym elemencie
extern int rotateNodeLeft(int AddressOfNode, int* AddressOfPointerToRoot);

// Rotacja w prawo na wybranym elemencie
extern int rotateNodeRight(int AddressOfNod, int* AddressOfPointerToRoot);

// Usuwa cale drzewo
void dropTree(struct BstNodeInt *element);