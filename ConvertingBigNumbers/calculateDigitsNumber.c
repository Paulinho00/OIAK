#include <math.h>

int returnDigitNumber(int lengthOfBinary){
    double logResult = log(2)/log(10);
    double result = logResult*lengthOfBinary;
    result = ceil(result);
    int digits = (int) result;
    return digits;
}

