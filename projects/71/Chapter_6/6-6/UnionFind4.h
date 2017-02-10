
#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include <iostream>
#include <cassert>

using namespace std;

namespace UF4 {

    class UnionFind {

    private:
        int *parent;
        int *rank;	//以i為根的元素的層數
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            if(p!=parent[p])
                parent[p] = find(parent[p]);
                   //路徑壓縮
            return parent[p];
        }

        // int find(int p) {
        //     assert(p >= 0 && p < count);
        //     while(p!=parent[p]){
        //         parent[p] = parent[parent[p]];   //路徑壓縮
        //     	p = parent[p];	
        //     }
        //     return p;
        // }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {

            int pRoot = find(p);    //在此處加速
            int qRoot = find(q);

            if (pRoot == qRoot)	//已經在一起，不需要合併
                return;
            if(rank[pRoot]<rank[qRoot]){
                parent[pRoot] = qRoot;
            }
            else if(rank[pRoot]>rank[qRoot]){
            	parent[qRoot] = pRoot;
            }
           	else{	//rank[pRoot]==rank[qRoot]
           		parent[pRoot] = qRoot;
           		rank[qRoot]++;
           	}


        }
    };
}
#endif //UNIONFIND_UNIONFIND3_H
