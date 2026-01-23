//DFS

// in dfs u will be calling dfs from the starting node 
// now u will mark that node to be visited then 
// add it to dfs array and then call for the neighbours for dfs traversal one by one with the help of adjacency list

class Solution {
  public:
    void helper(int node,vector<vector<int>> &adj,vector <int> &dfsans,vector <int> &vis){
        // step1:-visited mark
        vis[node]=1;
        
        // step2:- dfs ans me push
        dfsans.push_back(node);
        
        //neighbours pr depth frist search kro ek ek karke
        
        
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                helper(adj[node][i],adj,dfsans,vis);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector <int> dfsans;
        vector <int> vis(adj.size(),0);
        int startnode=0;
        
        helper(startnode,adj,dfsans,vis);
        return dfsans;
    }
};