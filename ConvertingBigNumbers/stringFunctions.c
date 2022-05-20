#include <math.h>
#include "stringFunctions.h"

int returnDigitNumber(int lengthOfBinary){
    double logResult = log(2)/log(10);
    double result = logResult*lengthOfBinary;
    result = ceil(result);
    int digits = (int) result;
    return digits;
}

void strrev(char* str){
    int i, len, temp;
    len = strlen(str);

    for(i = 0; i < len/2; i++){
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

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

char* fillLeadingZeroes(char* str, int bytes){
    int len = strlen(str);
    int correctLen = returnDigitNumber(bytes*8);
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

char* fillBackZeroes(char* str, int bytes){
    int len = strlen(str);
    int correctLen = returnDigitNumber(bytes*8);
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