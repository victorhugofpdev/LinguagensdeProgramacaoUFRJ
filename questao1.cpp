#include <iostream>
#include "fibonacci.h"
#include "fibonacci.cpp"

using namespace std;

int main(){
    int num;
    cout << "Para qual numero deseja calcular a sequecia de fibonacci? ";

    cin >> num;


    cout << functionfibonacci(num);

    return 0;
}