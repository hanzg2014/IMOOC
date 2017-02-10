#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
using namespace std;

template<typename Item>
class IndexMaxHeap{

private:
    Item* data;		//數組指針
    int* indexes;
    int* reverse;		//reverse
    
    int count;		//目前已經存放的元素個數
    int capacity;	//所能存放的數組的最大長度

    void shiftUp(int k){
        while(k>1 && data[indexes[k/2]]<data[indexes[k]]){  //比較data
            swap(indexes[k/2], indexes[k]);   //交換indexes
            reverse[indexes[k/2]] = k/2;	
            reverse[indexes[k]]=k;
            k /= 2;
        }
    }

    void shiftDown(int k){
    	while(2*k <= count){	//有左子結點麼？
    		int j = 2*k;	//取得左子結點
    		if(j+1<=count && data[indexes[j+1]]>data[indexes[j]]){	//有 右子結點 且 右子結點 的值比 左子結點 更大
    			j++;
    			//swap(data[k], data[j++]);
    		}
    		if(data[indexes[k]]>=data[indexes[j]]){
    			break;
    		}

    		swap(indexes[k], indexes[j]);
    		reverse(indexes[k]) = k;
    		reverse(indexes[j]) = j;
    		k = j;
    	}
    }

public:
    IndexMaxHeap(int capacity){
        data = new Item[capacity+1];	//data index from 1
        indexes = new int[capacity+1]; 
        reverse = new int[capacity+1]; 
        for(int i=0; i<=capacity;i++)	//
        	reverse[i] = 0;
        count = 0;
        this->capacity = capacity;
    }
    /*
    IndexMaxHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;
        for(int i=0; i<n; i++){
            data[i+1] = arr[i];
        }
        count = n;
        for(int i=count/2; i>=1; i--){
            shiftDown(i);
        }
    }
    */
    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
        data = NULL;
        indexes = NULL;
        reverse = NULL;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return (0 == count);
    }

    void insert(int i, Item item){  //用戶看到的索引i， 
        assert(count+1 <= capacity);    //必須不能越界
        assert(i+1>=1 && i+1<=capacity);    //必須不能越界

        i+=1;   //用戶角度從0計算， 為了方便從1計算的內部操作，需要進行轉換
        data[i]= item;
        indexes[count+1]=i;
        reverse[i]=count+1;
        count++;
        shiftUp(count);
    }

    void printHeap(){
    	for(int i=1; i<=count; i++){
            cout<<i<<" ";
        }
        for(int i=1; i<=count; i++){
            cout<<indexes[i]<<" ";
        }
        cout<<endl;
		for(int i=1; i<=count; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
		for(int i=1; i<=count; i++){
            cout<<reverse[i]<<" ";
        }
        cout<<endl;
    }

    Item extractMax(){
    	assert(count>0);
    	
        Item ret = data[indexes[1]];

    	swap(indexes[1], indexes[count]);
    	reverse[indexes[1]] = 1;
    	reverse[indexes[count]] = 0;
    	count --;
    	shiftDown(1);

    	return ret;
    }

    int extractMaxIndex(){
        assert(count>0);

        int ret = indexes[1] - 1;   //對於外部用戶, index 從0開始

        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
    	reverse[indexes[count]] = 0;
    	count --;

        shiftDown(1);
        return ret;
    }

    bool contain(int i){
        assert(i+1>=1 && i+1<=capacity);    //必須不能越界
    	return reverse[i+1] != 0;	//不等於0的話，說明堆裡面是包含索引i
    }

    Item getItem(int i){    //用戶的 index 從0開始
    	assert(contain(i));
        return data[i+1];
    }

    void change(int i, Item newItem){   //用戶利用索引修改data, 並且維護堆
        assert(contain(i));

        i+=1;
        data[i] = newItem;

        /*
        //找到indexes[j]=i, j表示data[i]在堆中的位置.
        //之後進行shiftUp(j)和shiftDown(j)
        for（int j=1; j<=count; j++）{    //O(N)
            if(indexes[j]==i){
                shiftUp(j);     //O(log(N))
                shiftDown(j);   //O(log(N))
                return;
            }
        }
        */
        int j = reverse[i];
        shiftUp(j);     //O(log(N))
        shiftDown(j);   //O(log(N))
        return;
    }
};