#include "stack.h"

int main() {
    Stack<int> pila;

    pila.push(234);
    pila.push(2234);
    pila.push(4);
    pila.push(22);
    pila.push(23234);

    cout << pila << endl;

    int n1 = pila.pop();
    int n2 = pila.pop();

    cout << "Pop of " << n1 << ", " << n2 << endl;

    cout << pila << endl;
}