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

int formateInput(char* str){
    int isSigned = 0;
    if(str[0] == '-') isSigned = 1;
    else return isSigned;

    
    int len = strlen(str);
    for(int i = 0; i < len; i++ ){
        str[i] = str[i+1];
    }
    return isSigned;

}