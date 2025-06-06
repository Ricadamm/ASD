#include <iostream>

using namespace std;

class Node {
private:
    int iData;

public:
    Node(int key) {
        iData = key;
    }

    int getKey() {
        return iData;
    }
};

class Heap {
private:
    Node** heapArray;
    int maxSize;
    int currentSize;

public:
    Heap(int mx) {
        maxSize = mx;
        currentSize = 0;
        heapArray = new Node*[maxSize + 1];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    void trickleUp(int index) {
        int parent = index / 2;
        Node* bottom = heapArray[index];

        while (index > 1 && heapArray[parent]->getKey() > bottom->getKey()) {
            heapArray[index] = heapArray[parent];
            index = parent;
            parent = parent / 2;
        }
        heapArray[index] = bottom;
    }

     void trickleDown(int index) {
        int smallerChild;
        Node* top = heapArray[index];

        while (index * 2 <= currentSize) {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if (rightChild <= currentSize && heapArray[leftChild]->getKey() > heapArray[rightChild]->getKey()) {
                smallerChild = rightChild;
            } else {
                smallerChild = leftChild;
            }

            if (top->getKey() <= heapArray[smallerChild]->getKey()) {
                break;
            }

            heapArray[index] = heapArray[smallerChild];
            index = smallerChild;
        }
        heapArray[index] = top;
    }

   Node* insert(int key) {
        if (isFull()) {
        return NULL;
        }
        Node* newNode = new Node(key);
        heapArray[++currentSize] = newNode;
        trickleUp(currentSize);
        return newNode; 
     }
    

    Node* remove() {
        if (isEmpty()) {
            return NULL;
        }
        Node* root = heapArray[1];
        heapArray[1] = heapArray[currentSize--];
        trickleDown(1);
        return root;
    }

    void displayHeap() {
        for (int i = 1; i <= currentSize; i++) {
            cout << heapArray[i]->getKey() << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap(7);
    heap.insert(33);
    heap.insert(13);
    heap.insert(53);
    heap.insert(9);
    heap.insert(25);
    heap.insert(55);

    cout << "Elements:" << endl << "33 13 53 9 25 55" << endl;
    cout << "Min-Heap:" << endl;
    heap.displayHeap();

    heap.remove();  
    cout << "After removing (min):" << endl;
    heap.displayHeap();

    return 0;
}

