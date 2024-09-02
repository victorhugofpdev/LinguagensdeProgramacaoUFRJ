#include <iostream>
#include "fibonacci2.cpp"

using namespace std;

int main(){

    Fibonacci fibonacci;
    int num;

    cout << "Para qual numero deseja calcular a sequecia de fibonacci? ";

    cin >> num;

    fibonacci.setFibonacci(num);
    
    cout << fibonacci.getFibonacci();

    return 0;
}