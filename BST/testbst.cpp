#include "bst.h"

int main() {
    BST<int> bst;

    
    bst.insert(3);
    bst.insert(241);
    bst.insert(432);
    bst.insert(24241);
    
    cout << "bst with heigth: " << bst.heigth() << endl;
    bst.inorder();
    cout << endl;

    cout << "Il successore di 3 nel BST è " << bst.successor(3) << endl;
    cout << "Il predecessore di 24241 nel BST è " << bst.predecessor(bst.search(24241)) << endl;

    bst.remove(241);
    bst.remove(23213);
    bst.remove(432);
    
    cout << "bst with heigth: " << bst.heigth() << endl;
    bst.inorder();
    cout << endl;

    
}