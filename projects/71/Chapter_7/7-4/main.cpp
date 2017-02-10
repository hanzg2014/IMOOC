#include <iostream>

#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

#define N 20	//節點數
#define M 100	//邊數

using namespace std;

int main() {

	string filename1 = "readG1.txt";
    string filename2 = "readG2.txt";

	SparseGraph g1(13, false); 
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    g1.show();  //打印鄰接表

    cout<<endl;

    DenseGraph g2(13, false); 
    ReadGraph<DenseGraph> readGraph2(g2, filename1);
    g2.show();  //打印鄰接矩陣

    return 0;
}