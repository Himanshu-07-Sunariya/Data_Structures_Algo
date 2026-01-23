#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Graph{
    //data members
    map<int,map<int,int>> strg;
    int V;

    // constructor
    public:

    Graph(int V){
        this->V=V;
    }

    void addEdge(int u,int v,int cost){
        strg[u][v]=cost;
        strg[v][u]=cost;
    }

    void display(){
        for(int i=0; i<V; i++){

            cout<<i<<"\t";

            map<int,int>::iterator itr;

            for(itr=strg[i].begin(); itr!=strg[i].end(); itr++){
                cout<<itr->first<<"@"<<itr->second<<" , ";
            }
        }
    }


    // making the prims node
    class PrimsNode{
        public:

        int vname;
        int pvname;
        int cost;

        PrimsNode(int vname,int pvname, int cost){
            this->vname=vname;
            this->pvname=pvname;
            this->cost=cost;
        }
    }

    void prims(){
        //1.Create min heap
        priority_queue<PrimsNode*, vector <PrimsNode*> , compare> pq;
        
        //2. start from first node
        pq.push(new PrimsNode(0,-1,0));

        
    }
};