#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#define N 100000
#define SWAP_TIMES 100
#define ARR_LEN(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;


template<typename Item>
class MaxHeap{
private:
    Item* data;
    int count;

public:
    MaxHeap(int capacity){
        data = new Item[capacity+1]; //data index from 1
        count = 0;
    }
    ~MaxHeap(){
        delete[] data;
        data = NULL;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return (0 == count);
    }
};


int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    

    return 0;
}