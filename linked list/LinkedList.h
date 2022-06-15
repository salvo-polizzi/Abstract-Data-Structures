#include <iostream>

using namespace std;


template<typename T> 
class Node{
    private:
        T val;
        Node<T>* next;

        template<typename U>
        friend class List;

    public:
        Node(T key): val(key), next(nullptr) {}

        T getKey() {return this->key;}

        Node<T>* getNext() {return this->next;}

        friend ostream& operator<<(ostream& os, Node<T>* nodo) {
            os << "@node " << &nodo << ", val = " << nodo->val;
            return os;
        }
};



template<typename T>
class List{
    private:
        Node<T>* head;
    public:
        List(): head(nullptr) {}

        bool isEmpty() {return head == nullptr;}

        void insertHead(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                return;
            }

            Node<T>* toInsert = new Node<T>(val);
            toInsert->next = head;
            head = toInsert;
        }

        void insertTail(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                return;
            }

            Node<T>* ptr = this->head;
            while(ptr->next)
                ptr = ptr->next;
            
            Node<T>* toInsert = new Node<T>(val);
            ptr->next = toInsert;
        }


        void insertInOrder(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                return;
            }

            if(head->val > val) {
                this->insertHead(val);
                return;
            }

            Node<T>* ptr = this->head;
            while(ptr->next && ptr->val <= val) {
                if(ptr->next->val > val)
                    break;
                ptr = ptr->next;
            }


            if(!(ptr->next)) {
                this->insertTail(val);
                return;
            }


            Node<T>* toInsert = new Node<T>(val);
            toInsert->next = ptr->next;
            ptr->next = toInsert;
        }


        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty List! Nothing to remove" << endl;
                return;
            }

            Node<T>* ptr = head;
            head = head->next;
            delete ptr;
        }


        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty List! Nothing to remove" << endl;
                return;
            }

            Node<T>* cur = head;
            Node<T>* prev = nullptr;
            while(cur->next) {
                prev = cur;
                cur = cur->next;
            }            

            prev->next = nullptr;
            delete cur;
        }


        void removeNode(T val) {
            if(this->isEmpty()) {
                cout << "Empty List! Nothing to remove" << endl;
                return;
            }

            if(head->val == val) {
                removeHead();
                return;
            }

            Node<T>* cur = head;
            Node<T>* prev = nullptr;
            while(cur->next && cur->val != val) {
                prev = cur;
                cur = cur->next;
            }            

            if(!(cur->next) && cur->val == val) {
                removeTail();
                return;
            }else if(!(cur->next) && cur->val != val) {
                cout << "Value "<< val << " to remove not found!" << endl;
                return;
            }


            prev->next = cur->next;

            delete cur;
        }



        friend ostream& operator<<(ostream& os, List<T>& lista) {
            Node<T>* ptr = lista.head;
            os << "List Head: " << ptr << endl;
            while(ptr) {
                os << ptr << endl;
                ptr = ptr->getNext();
            }
            os << endl << endl;
            return os;
        }
};