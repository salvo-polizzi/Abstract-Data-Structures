#include <iostream>

using namespace std;


template<typename T>
class Stack{
    private:
        T* array;
        int size;
        int maxSize;
        int top;
    public:
        Stack(int maxSize = 100): maxSize(maxSize), size(0), top(-1) {
            array = new T[maxSize];
        }

        bool isEmpty() {return size == 0;}

        T getTop() {
            if(this->isEmpty())
                return NULL;
            return array[top];
        }

        void push(T val) {
            array[++top] = val;
            size++;
        }

        T pop() {
            if(this->isEmpty()) {
                cout << "Empty List! Cannot Pop" << endl;
                return NULL;
            }

            size--;
            return array[top--];
        }


        friend ostream& operator<<(ostream& os, Stack<T>& s) {
            if(s.isEmpty())
                return os << "Empty Stack!" << endl;
            os << "SP (stack pointer) -> " << s.getTop() << endl;
            os << "Stack: ";
            for(int i=s.top; i>=0; i--) {
                os << s.array[i] << " ";
            }
            os << endl;
            return os;
        }
};