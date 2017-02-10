#ifndef INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//使用鄰接矩陣表示稠密圖
class DenseGraph{

private:
	int n;	//點數
	int m;	//邊數
	bool directed; //是否為有向圖
	vector<vector<bool> > g;

public:
	 DenseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		for(int i=0; i<n;i++){		
			g.push_back(vector<bool>(n,false)); //初始化創建一個n*n矩陣，每個元素都是false
		}
	 }

	 ~DenseGraph(){

	 }

	 int V(){return n;}
	 int E(){return m;}

	 bool hasEdge(int v, int w){		
	 	assert(v>=0 && v<n);
	 	assert(w>=0 && w<n);
	 	return g[v][w];
	 }

	 void addEdge(int v, int w){	//在頂點v, w之間建立一條邊
	 	assert(v>=0 && v<n);
	 	assert(w>=0 && w<n);

	 	if(hasEdge(v,w))	//處理平行邊問題
	 		return;
	 	g[v][w] = true;		
	 	if(!directed)	//無向圖的情況
	 		g[w][v] = true;
	 	m++;
	 }

    void show(){
        for(int i=0; i<n ; i++){
            cout<<"vertex "<<i<<":\t";
            for(int j=0; j<n; j++)
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }

	 class adjIterator{

	 private:
	 	DenseGraph &G;	//存放圖
	 	int v;	//存放該節點
	 	int index;

	 public:
	 	adjIterator(DenseGraph &graph, int v):G(graph){	//需要迭代的 圖 和 頂點
	 		this->v = v;
	 		this->index = -1;
	 	}

	 	int begin(){	//begin 尋找第一個值為true的元素
	 		index = -1;
	 		return next();
	 	}

	 	int next(){
	 		for(index+=1; index<G.V(); index++){
				if(G.g[v][index])
					return index;
	 		}
	 		return -1;
	 	}

	 	bool end(){
	 		return index>= G.V();

	 	}
	 };
};


#endif