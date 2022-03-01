#include <math.h>
#include<algorithm>
#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


template <typename T> class MaxHeap {
    private:
        vector<T>* A;

        void heapify(int parent) {
            int left = getLeftChild(parent);
            int right = getRightChild(parent);
            int max = parent;
            
            if (left < A->size() && (*A)[left] > (*A)[max])
                max = left;
            
            if (right < A->size() && (*A)[right] > (*A)[max])
                max = right;
            
            if (max != parent) {
                swap(A[max], A[parent]);
                heapify(max);
            }
        }

        void buildHeap() {
            int fromFirstParent = (A->size() / 2) -1;

            for (int parent = fromFirstParent; parent >= 0; parent--) 
                heapify(parent);
        }

    public:
        MaxHeap() {
            A = new vector<T>();
            buildHeap();
        }

        int getHeapSize() const { return A.size(); }

        int getParent(int i) const { return i >> 1; }

        int getLeftChild(int i) const { return (1 << 1) + 1; }

        int getRightChild(int i) const { return (1 << 1)+ 2; }

        bool hasNext() const { return !A->empty(); }

        T getNext() const { return A.front(); }

        T next() {
            if (A->size() < 0) throw "heap underflow";
            
            T next = A->back();

            swap(A->front(), next);

            A->pop_back();

            heapify(0);

            return next;
        }

        void increaseKey(int i, int key) {
            if (i < 0 || i >= A->size()) throw "out of bound";

            if (key < A->at(i)) throw "the candidate key is smaller than the current key";
            
            (*A)[i] = key;

            while (i > 0 && (*A)[i] > (*A)[getParent(i)]) {
                int parent = getParent(i);

                swap(A[i], A[parent]);
                i = parent;
            }
        }

        MaxHeap* pushKey(int key) {
            A->push_back(INT_MIN);
            cout << "before \n";
            increaseKey(A->size()-1, key);
            cout << "after \n";

            return this;
        }
};


int main() {
    MaxHeap<int>* heap = new MaxHeap<int>();

    heap->pushKey(23)
        ->pushKey(21)
        ->pushKey(1)
        ->pushKey(90)
        ->pushKey(65)
        ->pushKey(23)
        ->pushKey(1)
        ->pushKey(22)
        ->pushKey(8)
        ->pushKey(5);

    cout << "<<<< HEAPSORT >>>> \n\nSORTED ARRAY -> ";

    while (heap->hasNext()) {
        cout << heap->next() << " ";
    }
        
    cout << endl;

    return 0;
}
