#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;

    vector <int> adj(n+1);
    // for weighted graph it will be of pair type

    // O(2E) sc
    // O(m) tc

    // m edges input
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // for weighted graph :- wt is taken as input

        adj[u].push_back(v);
        adj[v].push_back(u);
        // for directed graph it is not required
    }
    return 0;
}