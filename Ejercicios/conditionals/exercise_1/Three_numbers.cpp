#include "Three_numbers.h"

ThreeNumbers::ThreeNumbers(int num1, int num2, int num3) 
    : number1(num1), number2(num2), number3(num3) {}


int ThreeNumbers::findLargest() const {
    int max = number1;
    if (number2 > max) max = number2;
    if (number3 > max) max = number3;
    return max;
}
