// given
// n :- no of nodes/vertices and m:- no of edges
// which edges is connected to which node it should be taken as input

// 3 ways to take input in graph 1.matrix 2.list 3.set

// STORE METHOD :-ADJACENCY MATRIX
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the number of vertices:-"<<endl;
    cin>>n;
    cout<<"Enter the number of edges:-"<<endl;
    cin>>m;

    vector<vector<int>> adj(n+1, vector <int> (n+1,0));
    // m edges input
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u;
        cin>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return 0;
}