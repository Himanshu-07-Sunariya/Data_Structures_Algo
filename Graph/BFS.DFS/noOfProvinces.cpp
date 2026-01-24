// dfs approach

class Solution {
public:
    void dfs(int node,vector<vector<int>> &isConnected,vector <int> &vis){
        // mark visited
        vis[node]=1;

        // neighbours pr traverse kro if the are not visited
        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[node][j]==1 && !vis[j]){
                dfs(j,isConnected,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <int> vis(isConnected.size(),0);
        int province=0;
       
        // jo connected component nahi hoga wo unvisited mark hoga
        for(int i=0; i<isConnected.size(); i++){
            // this loop is used to traverse all node
            if(!vis[i]){
                province++;
                dfs(i,isConnected,vis);
            }
        }

        return province;
    }
};