#ifndef INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


//使用鄰接表表示稀疏圖
class SparseGraph{

private:
	int n;	//點數
	int m;	//邊數
	bool directed; //是否為有向圖
	vector<vector<int>> g;

public:
	DenseGraph(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;

		for(int i=0; i<n;i++){		
			g.push_back(vector<int>()); //每個元素都是空向量（不涉及刪除）
		}
	}
	 ~DenseGraph(){

	 }

	 int V(){return n;}
	 int E(){return m;}

	 bool hasEdge(int v, int w){		
	 	//檢測平行邊
	 	assert(v>=0 && v<n);
	 	assert(w>=0 && w<n);

	 	fot(int i=0; i<g[v].size();i++){
	 		if(g[v][i]==w)
	 			return true;
	 	}
	 	return false;
	 }

	 void addEdge(int v, int w){	//在頂點v, w之間建立一條邊
	 	assert(v>=0 && v<n);
	 	assert(w>=0 && w<n);
	 	g[v].push_back(w);	
	 	if(v!=w && !directed)	//不能有自環邊 和 無向圖的情況
	 		g[w].push_back(v);
	 	m++;
	 }
};