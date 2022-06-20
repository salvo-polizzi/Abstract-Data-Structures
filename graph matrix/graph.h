#include <iostream>

using namespace std;

template<typename T>
class Node{
    private:
        T key;
    public:
        Node(T key): key(key) {}

        T getKey() {return this->key;}

        friend ostream& operator<<(ostream& os, Node<T>& nodo) {
            return os << nodo.key;
        } 
};


template<typename T>
class Graph{
    private:
        bool** matrix;
        Node<T>** array;
        int index;
        int maxSize;
    public:
        Graph(int maxSize = 100): index(0) {
            matrix = new bool* [maxSize];
            array = new Node<T>* [maxSize];

            for(int i=0; i<maxSize; i++) {
                matrix[i] = new bool [maxSize];
                for(int j=0; j<maxSize; j++) {
                    matrix[i][j] = false;
                }
            }
        }


        int search(T key) {
            if(index == 0)
                return -1;
            for(int i=0; i<index; i++) {
                if(array[i]->getKey() == key)
                    return i;
            }
            return -1;
        }

        
        void insertNode(T key) {
            array[index++] = new Node<T>(key);
        }


        void addEdge(T key1, T key2, bool isOriented = true) {
            if(index == 0)
                return;
            int indexKey1 = search(key1);
            int indexKey2 = search(key2);

            if(indexKey1 == -1 || indexKey2 == -1) {
                cout << "A key that you passed as parameter does not exists" << endl;
                return;
            }

            if(!isOriented) {
                matrix[indexKey1][indexKey2] = true;
                matrix[indexKey2][indexKey1] = true;
                return;
            }

            matrix[indexKey1][indexKey2] = true;
        
        }


        friend ostream& operator<<(ostream& os, Graph<T>& g) {
            os << "List of Nodes:" << endl;
            for(int i=0; i<g.index; i++) {
                os << g.array[i]->getKey() << " ";
            }
            os << endl;
            os << "List of Edges: ";
            for(int i=0; i<g.index; i++) {
                for(int j=0; j<g.index; j++) {
                    if(g.matrix[i][j]) {
                        os << "(" << g.array[i]->getKey() << ", " << g.array[j]->getKey() << "); ";
                    }
                }
                os << endl;
            }
            return os;
        }
};