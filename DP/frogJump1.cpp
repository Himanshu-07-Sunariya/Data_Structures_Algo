// recursive approach

int helper(int ind,vector <int> &height){
        // +ve base case
        if(ind==height.size()-1) return 0;
        
        // recursive calls
        int jump1=INT_MAX;
        int jump2=INT_MAX;
        if(ind+1<height.size()){
            jump1=abs(height[ind]-height[ind+1])+helper(ind+1,height);
        }
        
        if(ind+2<height.size()){
            jump2=abs(height[ind]-height[ind+2])+helper(ind+2,height);
        }
        
        return min(jump1,jump2);
    }
    int minCost(vector<int>& height) {
        int ind=0;
        return helper(ind,height);
    }


// td and  bu

int frog_TD(int ind,vector <int> &height,vector <int> &dp){
        // +ve base case
        if(ind==height.size()-1) return 0;
        
        // dp td step2
        if(dp[ind]!=-1) return dp[ind];
        
        // recursive calls
        int jump1=INT_MAX;
        int jump2=INT_MAX;
        if(ind+1<height.size()){
            jump1=abs(height[ind]-height[ind+1])+frog_TD(ind+1,height,dp);
        }
        
        if(ind+2<height.size()){
            jump2=abs(height[ind]-height[ind+2])+frog_TD(ind+2,height,dp);
        }
        
        dp[ind]=min(jump1,jump2);
        return dp[ind];
    }
    
    int frog_BU(int ind,vector <int> &height){
        // 1. Create dp array
        vector <int> dp(height.size(),-1);
        
        // 2. base case fill
        dp[height.size()-1]=0;
        
        // 3. iterative work
        for(int i=height.size()-2; i>=0; i--){
            int jump1=INT_MAX;
            int jump2=INT_MAX;
            if(i+1<height.size()){
                jump1=abs(height[i]-height[i+1])+dp[i+1];
            }
            
            if(i+2<height.size()){
                jump2=abs(height[i]-height[i+2])+dp[i+2];
            }
            
            dp[i]=min(jump1,jump2);
        }
        
        // we r considering the whole array of cost with stairs
        return dp[0];
    }
    
    int minCost(vector<int>& height) {
        int ind=0;
        // return helper(ind,height);
        // vector <int> dp(height.size(),-1);
        
        // return frog_TD(ind,height,dp);
        
        return frog_BU(ind,height);
    }
};


// Bottom up space optimized


    int frog_BUSO(int ind,vector <int> &height){
        // 1. Create dp array
        // vector <int> dp(height.size(),-1);
        int next1=0;
        int next2=0;
        
        int curr;
        
        // 2. base case fill
        // dp[height.size()-1]=0;
        
        // 3. iterative work
        for(int i=height.size()-2; i>=0; i--){
            int jump1=INT_MAX;
            int jump2=INT_MAX;
            if(i+1<height.size()){
                jump1=abs(height[i]-height[i+1])+next1;
            }
            
            if(i+2<height.size()){
                jump2=abs(height[i]-height[i+2])+next2;
            }
            
            curr=min(jump1,jump2);
            
            next2=next1;
            next1=curr;
        }
        
        // we r considering the whole array of cost with stairs
        return curr;
    }
    
    int minCost(vector<int>& height) {
        int ind=0;
        // return helper(ind,height);
        // vector <int> dp(height.size(),-1);
        
        // return frog_TD(ind,height,dp);
        return frog_BUSO(ind,height);
    }