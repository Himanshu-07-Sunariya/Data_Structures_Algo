// BFS
// bfs traversal is just like Level Order traversal
// but levels is defined like 1 edge distance is defined to be another level assume we are on level 0 and the next node is on level 1

// make the graph using adjacency list
// int n,m and for loop then adjacency list fill

// then pass V and adjacency list to the bfs function(LEVELORDER TRAVERSAL)


class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector <int> bfsans;
        
        vector <int> vis(adj.size(),0);
        
        queue <int> q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            // curr vertex take out
            int curr=q.front();
            q.pop();
            
            // print 
            bfsans.push_back(curr);
            
            // unvisited neighbours add
            for(int i=0; i<adj[curr].size(); i++){
                if(!vis[adj[curr][i]]){
                    q.push(adj[curr][i]);
                    vis[adj[curr][i]]=1;
                }
            }
        }
        
        return bfsans;
    }

    // Time complexity:-O(3N)
    // Space complexity:-O(N)+O(2E)
};