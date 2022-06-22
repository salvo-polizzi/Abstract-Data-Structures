#include "/Users/salvopolizzi/Desktop/ADT/Abstract-Data-Structures/Double Linked List/DoubleLinkedList.h"

template<typename T>
class GraphVertex: public List<T>{
    public:
        GraphVertex(T key): List<T>() {
            List<T>::insertTail(key);
        }

        friend ostream& operator<<(ostream& os, GraphVertex<T>& nodo) {
            os << "Node with key: " << nodo.getHead()->getVal();
            os << "\tAdjacency List: ";

            Node<T>* ptr = nodo.getHead();
            while(ptr) {
                os << ptr->getVal() << " -> ";
                ptr = ptr->getNext();
            }
            os << endl;
            return os;
        }
};


template<typename T>
class Graph{
    private:
        List< GraphVertex<T> > listNodes;
        int numVertices;
    public:
        Graph(): numVertices(0) {}

        Node< GraphVertex<T> >* search(T key) {
            if(numVertices == 0)
                return NULL;
            
            Node< GraphVertex<T> >* ptr = listNodes.getHead();
            while(ptr) {
                if(ptr->getVal().getHead()->getVal() == key) 
                    return ptr;
                ptr = ptr->getNext();
            }

            return NULL;
        }

        void addVertex(T val) {
            GraphVertex<T> n(val);
            listNodes.insertTail(n);
            numVertices++;
        }

        void addEdge(T key1, T key2) {
            Node< GraphVertex<T> >* n1 = this->search(key1);
            Node< GraphVertex<T> >* n2 = this->search(key2);

            if(n1 && n2) {
                n1->getVal().insertTail(key2);
            }
        }

        friend ostream& operator<<(ostream& os, Graph<T>& g) {
            os << g.listNodes << endl;
            return os;
        }
};