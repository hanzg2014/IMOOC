
#ifndef INC_04_READ_GRAPH_READGRAPH_H
#define INC_04_READ_GRAPH_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


/* 要讀取的 txt的格式
    13 13   #第一行 頂點個數V 和 邊的個數E
    0 5     #第二行開始 是 邊的信息（連接的兩個定點）
    4 3
    ...

    9 11
    5 3
*/

//可以同時作用域 稀疏圖 和 稠密圖
template <typename Graph>
class ReadGraph{
public:
    ReadGraph(Graph &graph, const string &filename){
        ifstream file(filename);    //把 filename 變成 入文件流
        string line;
        int V, E;

        assert(file.is_open()); //執行 assert 當中的語句

        assert(getline(file, line));    //將file中的第一行 讀到 line當中 並且成功
        stringstream ss(line);  //把 line 放在一個 stringstream 對象當中
        ss>>V>>E;   //靠空白字符分隔

        assert(V==graph.V());   //頂點個數的確認

        for(int i=0; i<E; i++){
            assert(getline(file, line));
            stringstream ss(line);  //
            int a, b;
            ss>>a>>b;
            assert(a>=0 && a<V);
            assert(b>=0 && b<V);
            graph.addEdge(a,b);
        }
    }

};

#endif //INC_04_READ_GRAPH_READGRAPH_H
