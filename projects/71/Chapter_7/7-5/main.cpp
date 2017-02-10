#include <iostream>

#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Components.h"

#define N 20	//節點數
#define M 100	//邊數

using namespace std;

int main() {

	string filename1 = "testG1.txt";
    string filename2 = "testG2.txt";

	SparseGraph g1(13, false); 
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    g1.show();  //打印鄰接表
    cout<<"TestG1.txt, Component Count: "<<component1.count()<<endl;

    cout<<endl;

    SparseGraph g2(7, false); 
    ReadGraph<SparseGraph> readGraph2(g2, filename2);
    Component<SparseGraph> component2(g2);
    g2.show();  //打印鄰接矩陣
    cout<<"TestG2.txt, Component Count: "<<component2.count()<<endl;

    return 0;
}