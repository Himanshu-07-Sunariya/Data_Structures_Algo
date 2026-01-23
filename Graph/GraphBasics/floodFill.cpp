// matrix approach

void helper(vector<vector<int>>& image, int sr, int sc, int color,int cell){
        // base case
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) return;

        if(image[sr][sc]!=cell) return;

        // set my color first
        image[sr][sc]=color;
        // }

        // left
        helper(image,sr,sc-1,color,cell);
        // down
        helper(image,sr+1,sc,color,cell);
        // right
        helper(image,sr,sc+1,color,cell);
        // up
        helper(image,sr-1,sc,color,cell);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cell=image[sr][sc];

        if(cell==color) return image;
        // no graph approach
        helper(image,sr,sc,color,cell);

        return image;
    }


// Graph bfs approach

class Solution {
public:
    
    // void helper(vector<vector<int>>& image, int sr, int sc, int color,int cell){
    //     // base case
    //     if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size()) return;

    //     if(image[sr][sc]!=cell) return;

    //     // set my color first
    //     image[sr][sc]=color;
    //     // }

    //     // left
    //     helper(image,sr,sc-1,color,cell);
    //     // down
    //     helper(image,sr+1,sc,color,cell);
    //     // right
    //     helper(image,sr,sc+1,color,cell);
    //     // up
    //     helper(image,sr-1,sc,color,cell);
    // }

    void bfs(vector<vector<int>>& image,int sr,int sc,int color,int cell){
        vector<vector<int>> vis(image.size(), vector <int> (image[0].size(),0));

        queue <pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;

        while(!q.empty()){
            // curr node
            pair<int,int> p=q.front();
            q.pop();

            // self work
            if(image[p.first][p.second]==cell){
                image[p.first][p.second]=color;

                // neighbours
                // left
                if(p.second-1>=0 && !vis[p.first][p.second-1]){
                    q.push({p.first,p.second-1});
                    vis[p.first][p.second-1]=1;
                }
                // down
                if(p.first+1<image.size() && !vis[p.first+1][p.second]){
                    q.push({p.first+1,p.second});
                    vis[p.first+1][p.second]=1;
                }
                // right
                if(p.second+1<image[0].size() && !vis[p.first][p.second+1]){
                    q.push({p.first,p.second+1});
                    vis[p.first][p.second+1]=1;
                }
                // up
                if(p.first-1>=0 && !vis[p.first-1][p.second]){
                    q.push({p.first-1,p.second});
                    vis[p.first-1][p.second]=1;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cell=image[sr][sc];

        if(cell==color) return image;
        
        // bfs approach
        bfs(image,sr,sc,color,cell);

        return image;
    }
};