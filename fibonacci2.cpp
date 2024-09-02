
#include "fibonacci2.h"

int Fibonacci::computeFibonacci(int num){
    int result = num;
    if (num == 0 )
    return 0;
    else if (num == 1)
    return 1;
    else
    do {
        result = result*(num-1);
        num--;
    }
    while (num > 1);
    return result;
}



void Fibonacci::setFibonacci(int num){
    result = computeFibonacci(num);

}
int Fibonacci::getFibonacci(){
    return result;

}
