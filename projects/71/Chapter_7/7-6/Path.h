#ifndef INC_06_FINDING_A_PATH_PATH_H
#define INC_06_FINDING_A_PATH_PATH_H

#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Path{

private:
    Graph &G;
    bool* visited;
    int s;	//source 原點
    int* from; //遍歷時，前一個節點

    void dfs(int v){
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);   //Graph可以是一個成員變量， 避免混淆加上 typename
        for(int i=adj.begin(); !adj.end(); i=adj.next()){
            if(!visited[i]){
            	from[i] = v;
                dfs(i);
            }
        }
    }


public:
    Path(Graph &graph, int s):G(graph){

    	assert(s>=0 && s<G.V());
        visited = new bool[G.V()];  //節點數
        from = new int[G.V()]; 

        for(int i=0; i<G.V(); i++){
            visited[i] = false;
            from[i] = -1;	//-1 代表沒有被遍歷到, from[s]永遠是 -1
        }
        this->s = s;	
        //find path 算法
        dfs(s);
    }

    ~Path(){
        delete[] visited;
        delete[] from;
    }

    void printFrom(){
        for(int i=0; i<G.V(); i++){
            cout<<"from["<<i<<"]:"<<from[i]<<endl;
        }
    }

        void printVisited(){
        for(int i=0; i<G.V(); i++){
            cout<<"visited["<<i<<"]:"<<visited[i]<<endl;
        }
    }

    bool hasPath(int w){	//s到w， 是否有路徑？
    	assert(w>=0 && w<G.V());
    	return visited[w];
    }

    void path(int w, vector<int> &vec){

    	vec.clear();	//安全起見 清空vec
    	assert(w>=0 && w<G.V());
    	stack<int> s;
    	int p = w;
    	while(p!=-1){
    	//	cout<<p<<" ";
    		s.push(p);
    		p = from[p];
    	}

    	while(!s.empty()){
    	//	cout<<s.top();
    		vec.push_back(s.top());
    		s.pop();
    	}
    }

    void showPath(int w){

    	vector<int> vec;
    	path(w, vec);
    	
    	for(int i=0; i<vec.size(); i++){
    		cout<<vec[i];
    		if(i == vec.size()-1)
    			cout<<endl;
    		else
    			cout<<"->";
    	}    
    }
};

#endif