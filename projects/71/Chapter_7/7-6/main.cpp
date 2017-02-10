#include <iostream>

#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Components.h"
#include "Path.h"

#define N 20	//節點數
#define M 100	//邊數

using namespace std;

int main() {

	string filename = "testG2.txt";

    SparseGraph g = SparseGraph(7, false); 
    ReadGraph<SparseGraph> readGraph(g, filename); 
    g.show();  //打印鄰接表
    cout<<endl;


    Path<SparseGraph> dfs(g,0); // s = 0
    dfs.printFrom();
    dfs.printVisited();
    cout<<"DFS:" ;
    dfs.showPath(6);

    return 0;
}