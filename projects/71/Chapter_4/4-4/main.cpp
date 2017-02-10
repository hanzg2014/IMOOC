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
    int capacity;

    void shiftUp(int k){
        while(k>1 && data[k/2]<data[k]){
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k){
    	while(2*k <= count){	//有左子結點麼？
    		int j = 2 * k;	//取得左子結點
    		if(j+1<=count && data[j+1]>data[j]){//有 右子結點 且 右子結點 的值比 左子結點 更大
    			j++;
    			//swap(data[k], data[j++]);
    		}
    		if(data[k]>=data[j]){
    			break;
    		}
    		swap(data[k], data[j]);
    		k = j;
    	}
    }

public:
    MaxHeap(int capacity){
        data = new Item[capacity+1]; //data index from 1
        this->capacity = capacity;
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

    void insert(Item item){
        assert(count+1 <= capacity);
        data[count+1]= item;
        count++;
        shiftUp(count);
    }

    void printHeap(){
        for(int i=1; i<=count; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    Item extractMax(){
    	assert(count>0);
    	Item ret = data[1];
    	swap(data[1], data[count--]);
    	shiftDown(1);
    	return ret;
    }
};

int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    
    srand(time(NULL));
    for(int i=0; i<15; i++){
        maxheap.insert(rand()%100);
    }

    maxheap.printHeap();
    while(!maxheap.isEmpty())
    	cout<<maxheap.extractMax()<<" ";	//不需要重載
    cout<<endl;

    return 0;
}