#include <math.h>


template <typename T> class Heap {
    private:
        int heapSize;
        int arrSize;
        T* A;

    public:
        Heap(int arrSize, T* A) {
            this->heapSize = 0;
            this->arrSize = arrSize;
            this->A = A;
        }

        int getArrayMaxSize() const {
            return sizeof(A) / sizeof(A[0]);
        }

        int getHeapSize() const {
            return heapSize;
        }

        void setHeapSize(int heapSize) {
            this->heapSize = heapSize;            
        }

        int getParent(int i) const { return i > 0 ? i >> 1 : -1 }

        int getLeftChild(int i) const {  
            int l = i >> 1;
            return l < this->heapSize ? l : -1;
        }

        int getRightChild(int i) const {
            int r = (i << 1) + 1;
            return r < this->heapSize ? r : -1;
        }
};