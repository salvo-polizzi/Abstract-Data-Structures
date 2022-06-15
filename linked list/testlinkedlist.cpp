#include "LinkedList.h"

int main() {
    List<int> lista;
    
    // testing inserting methods
    lista.insertInOrder(234);
    lista.insertInOrder(43);
    lista.insertInOrder(23434);
    lista.insertInOrder(2344);
    lista.insertInOrder(4);

    cout << lista << endl;

    //testing removing methods
    lista.removeNode(43);
    lista.removeNode(4324);
    lista.removeNode(4);
    lista.removeTail();

    cout << lista << endl;
}