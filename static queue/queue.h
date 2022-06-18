#include <iostream>

using namespace std;

template<typename T>
class Queue{
    private:
        T* array;
        int tail;
        int head;
        int size;
        int maxSize;
    public:
        Queue(int maxSize = 100): maxSize(maxSize), tail(-1), head(-1), size(0) {
            array = new T[maxSize];
        }

        bool isEmpty() {return size == 0;}

        void enqueue(T val) {
            if(size == maxSize) {
			    cout << "Queue is full" << endl;
			    return;
		    }

            if(head == -1)
                head = 0;

            tail = (++tail)%maxSize;
            array[tail] = val;
            size++;
        }

        T dequeue() {
            if(this->isEmpty()) {
                cout << "Queue is empty" << endl;
                return 0;
            }
            T val = array[head];
            head = (++head)%maxSize;
            size--;
            return val;
        }


        friend ostream& operator<<(ostream& os, Queue<T>& coda) {
            if(coda.isEmpty())
                return os << "Queue is empty!" << endl;
            
            os << "Queue with size: " << coda.size << " and max size: " << coda.maxSize << endl;
            for(int i = coda.head, count = 0; count < coda.size; count++) {
                os << "queue[" << i << "] = " << coda.array[i] << endl;
                i = (i+1) % coda.maxSize;
            }

            return os;
        }


};