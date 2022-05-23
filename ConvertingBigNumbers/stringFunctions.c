#include <math.h>
#include "stringFunctions.h"
#include <stdio.h>
#include <stdlib.h>

//Funkcje do manipulacji stringow i obliczania pamieci potrzebnej do przechowywania stringow

//Zwraca ilosc cyfr w liczbie w zapisie dziesietnym dla danej ilosci bitow
int returnDigitNumber(int lengthOfBinary){
    double logResult = log(2)/log(10);
    double result = logResult*lengthOfBinary;
    result = ceil(result);
    int digits = (int) result;
    return digits;
}


//Odwraca string
void strrev(char* str){
    int i, len, temp;
    len = strlen(str);

    for(i = 0; i < len/2; i++){
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

//Zwraca ilosc bajtow potrzebnych do przechowywania liczby o zadanej dlugosci
int returnNeededBytes(int numberOfDigits){
    int bytes = 1;
    int decimalDigits = returnDigitNumber(bytes*8);
    while(decimalDigits < numberOfDigits+1){
        bytes++;
        decimalDigits = returnDigitNumber(bytes*8);
    }
    return bytes+1;
}

//Usuwanie znaku - ze stringa i zwracanie informacji o ujemnej liczbie
int formateInputWithoutSign(char* str){
    int isSigned = 0;
    if(str[0] == '-') isSigned = 1;
    else return isSigned;

    
    int len = strlen(str);
    for(int i = 0; i < len; i++ ){
        str[i] = str[i+1];
    }
    return isSigned;

}

//Zwrocenie czesci calkowitej liczby rzeczywistej
char* returnIntPart(char* str){
    int len, i, positionOfDot;
    len = strlen(str);
    for(i=0; i < len; i++){
        if(str[i] == '.'){
            positionOfDot = i;
            break;
        }
    }

    char* intPart = (char*) malloc (positionOfDot);
    for(i = 0; i < positionOfDot; i++){
        intPart[i] = str[i];
    }
    return intPart;
}

//Zwrocenie czesci dziesietnej liczby rzeczywistej
char* returnFloatPart(char* str){
    int len, i, positionOfDot;
    len = strlen(str);
    for(i=0; i < len; i++){
        if(str[i] == '.'){
            positionOfDot = i;
            break;
        }
    }

    char* floatPart = (char*) malloc(len-positionOfDot-1);
    int j;
    for(i = positionOfDot+1, j=0; i < len; i++, j++){
        floatPart[j] = str[i];
    }
    return floatPart;
}

//Wypelnienie zerami czesci rzeczywistej, w celu uzyskania poprawnego rzedu wielkosci
char* fillLeadingZeroes(char* str, int numberOfDigits){
    int len = strlen(str);
    int correctLen = numberOfDigits;
    char* newString = (char*) malloc (correctLen);
    int i, j;
    for(i = 0; i < correctLen-len; i++){
        newString[i] = '0';
    }
    
    for(j = 0; i < correctLen; i++, j++){
        newString[i] = str[j];
    }

    free(str);
    return newString;
}

//Wypelnienie zerami czesci rzeczywistej, w celu poprawnej konwersji do pamieci
char* fillBackZeroes(char* str, int numberOfDigits){
    int len = strlen(str);
    int correctLen = numberOfDigits;
    char* newString = (char*) malloc (correctLen);
    int i, j;
    for(i = 0; i < len; i++){
        newString[i] = str[i];
    }
    
    for(;i<correctLen;i++){
        newString[i] = '0';
    }

    free(str);
    return newString;
}

//Zamiana wartosci ascii znaku na string z liczba dziesietna
char* convertCharToDecimalString(char* str){
    int asciiValue = str[0];
    char* decimalString = malloc (3);
    sprintf(decimalString, "%d", asciiValue);
    free(str);
    return decimalString;

}

//Zamiana wartosci ascii w postaci stringa na typ znakowy o tej wartosci
void convertAsciiValueToChar(char* str){
    int asciiValue = atoi(str);
    str[0] = asciiValue;
    str[1] = '\0';
}