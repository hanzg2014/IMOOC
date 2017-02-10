
#ifndef INC_05_DFS_AND_COMPONENTS_COMPONENTS_H
#define INC_05_DFS_AND_COMPONENTS_COMPONENTS_H

#include <iostream>
#include <cassert>
using namespace std;


template <typename Graph>
class Component{

private:
    Graph &G;
    bool* visited;
    int* id;    //各個節點所在的聯通分量的id
    int ccount; //圖 當中所包含的 聯通分量 的個數

    void dfs(int v){

        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);   //Graph可以是一個成員變量， 避免混淆加上 typename
        for(int i=adj.begin(); !adj.end(); i=adj.next()){
            if(!visited[i])
                dfs(i);
        }
    }

public:
    Component(Graph &graph):G(graph){
        visited = new bool[G.V()];  //節點數
        ccount = 0;
        for(int i=0; i<G.V(); i++){
            visited[i] = false;
            id[i] = -1;
        }
        for(int i=0; i<G.V(); i++){
            if(!visited[i]){
                dfs(i);     //Depth-First-Search 掃遍一個聯通中的所有節點
                ccount++;
            }
        }
    }
    ~Component(){
        delete[] visited;
        delete[] id;
    }

    int count(){
        return ccount;
    }

    bool isConnected(int v, int w){
        assert(v>=0 && v<G.V());
        assert(w>=0 && w<G.V());
        return id[v] == id[w];
    }
};

#endif //INC_05_DFS_AND_COMPONENTS_COMPONENTS_H

