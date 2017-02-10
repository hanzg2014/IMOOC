#include <iostream>

#include "SparseGraph.h"
#include "DenseGraph.h"

#define N 20	//節點數
#define M 100	//邊數

using namespace std;

int main() {

	srand( time(NULL) );


	SparseGraph g1(N, false); //無向稀疏圖
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g1.addEdge( a , b );
    }

    // O(E)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        SparseGraph::adjIterator adj( g1 , v );	//內部類的調用
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }

    cout<<endl;

    DenseGraph g2(N, false); //無向稠密圖
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g2.addEdge( a , b );
    }

    // O(E)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        DenseGraph::adjIterator adj( g2 , v );	//內部類的調用
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }

    return 0;
}