#include "queue.h"

int main() {
    Queue<int> coda;

    coda.enqueue(234);
    coda.enqueue(2234);
    coda.enqueue(4);
    coda.enqueue(22334);
    coda.enqueue(23);

    cout << coda << endl;

    int n1 = coda.dequeue(), n2 = coda.dequeue();
    cout << "dequeue of " << n1 << ", " << n2 << endl;
    cout << coda << endl; 
}