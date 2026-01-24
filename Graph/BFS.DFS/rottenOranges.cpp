// bfs + level order seperator method + one case each time

void bfs(vector <int>& rotteni,vector <int>& rottenj,vector<vector<int>> &adj,int &min){
        vector<vector<int>> vis(adj.size(), vector <int> (adj[0].size(),0));

        queue <pair<int,int>> q;
        // At start we can have multiple rotten orangess
        for(int i=0; i<rotteni.size(); i++){
            q.push({rotteni[i],rottenj[i]});
            vis[rotteni[i]][rottenj[i]]=1;
        }

        // add seperator
        q.push({adj.size(),adj[0].size()});

        while(!q.empty()){
            // curr
            pair <int,int> curr=q.front();
            q.pop();

            // if curr==separator
            if(curr.first==adj.size() && curr.second==adj[0].size()){
                // separator k kaam kro
                min++;

                // separator lgao
                if(!q.empty()){
                    q.push({adj.size(),adj[0].size()});
                }
            }
            else{
                //mark rotten
                if(adj[curr.first][curr.second]==1){
                    adj[curr.first][curr.second]=2;
                }

                // 4 directional check
                // left
                if(curr.second-1>=0 && !vis[curr.first][curr.second-1] && (adj[curr.first][curr.second-1]==1)){
                    q.push({curr.first,curr.second-1});
                    vis[curr.first][curr.second-1]=1;
                }
                // down
                if(curr.first+1<adj.size() && !vis[curr.first+1][curr.second] && (adj[curr.first+1][curr.second]==1)){
                    q.push({curr.first+1,curr.second});
                    vis[curr.first+1][curr.second]=1;
                }
                // right
                if(curr.second+1<adj[0].size() && !vis[curr.first][curr.second+1] && (adj[curr.first][curr.second+1]==1)){
                    q.push({curr.first,curr.second+1});
                    vis[curr.first][curr.second+1]=1;
                }
                // up
                if(curr.first-1>=0 && !vis[curr.first-1][curr.second] && (adj[curr.first-1][curr.second]==1)){
                    q.push({curr.first-1,curr.second});
                    vis[curr.first-1][curr.second]=1;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        //search for rotten and fresh orange
        vector <int> rotteni;
        vector <int> rottenj;
        int fresh=0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    rotteni.push_back(i);
                    rottenj.push_back(j);
                }
            }
        }

        int min=-1;
        if(fresh==0) return 0;

        bfs(rotteni,rottenj,grid,min);

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return min;
    }



// bfs + keeping track of time in queue(each call time+1) + covering each case with the help or arrays
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // we will keep track (inc time) of time when one rotten orange rottes other
        vector<vector<int>> vis(grid.size(), vector <int> (grid[0].size(),0));
        queue <pair<pair<int,int>,int>> q;
        int fresh=0;

        // check for fresh oranges,pushing multiple rotten oranges
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        if(fresh==0) return 0;

        int row[4]={0,1,0,-1};
        int col[4]={-1,0,1,0};

        int cnt=0;//for checking if any fresh orange left to be rotten or not
        int tm=0;//time required to completly elapse oranges
        
        while(!q.empty()){
            // curr node
            pair<pair<int,int>,int> curr=q.front();
            q.pop();

            int r=curr.first.first;
            int c=curr.first.second;
            int t=curr.second;

            tm=max(tm,t);

            // neighbours
            for(int i=0; i<4; i++){
                int nr=r+row[i];
                int nc=c+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=1;
                    cnt++;
                }
            }
        }

        if(cnt!=fresh) return -1;
        return tm;
    }