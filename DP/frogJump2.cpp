//Recursive Approach

int helper(int ind,vector <int> &height,int k){
        // +ve base case
        if(ind==height.size()-1) return 0;
        
        // -ve base case
        
        // recursive calls
        // int jump1=INT_MAX;
        // int jump2=INT_MAX;
        // if(ind+1<height.size()){
        //     jump1=abs(height[ind]-height[ind+1])+helper(ind+1,height);
        // }
        
        // if(ind+2<height.size()){
        //     jump2=abs(height[ind]-height[ind+2])+helper(ind+2,height);
        // }
        
        // return min(jump1,jump2);
        int ans=INT_MAX;
        for(int i=1;i<=k; i++){
            int jump=INT_MAX;
            
            if(ind+i<heights.size()){
                jump=abs(heights[ind]-heights[ind+i])+helper(ind+i,heights,k);
            }
            ans=min(ans,jump);
        }

        return ans;
    }

// Top down Approach

    int helper_TD(int ind,vector <int> &heights,int k,vector <int> &dp){
         // +ve base case
        if(ind==heights.size()-1) return 0;

        // dp step2
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=INT_MAX;
        for(int i=1;i<=k; i++){
            int jump=INT_MAX;
            
            if(ind+i<heights.size()){
                jump=abs(heights[ind]-heights[ind+i])+helper_TD(ind+i,heights,k,dp);
            }
            ans=min(ans,jump);
            
        }

        dp[ind]=ans;

        return ans;
    }

// Bottom Up approach

    int helper_BU(vector <int> &heights,int k){
        // 1. create dp array
        vector <int> dp(heights.size(),-1);

        // 2. base case fill
        dp[heights.size()-1]=0;

        // 3. Cell meaning :- considering elements from i to n now tell how much min cost will be to reach final stair by [i+1,i+k] steps

        // 4.iterative work
        for(int i=heights.size()-2; i>=0; i--){

            int ans=INT_MAX;
            for(int j=1;j<=k; j++){
                int jump=INT_MAX;
                
                if(i+j<heights.size()){
                    jump=abs(heights[i]-heights[i+j])+dp[i+j];
                }
                ans=min(ans,jump);
                
            }

            dp[i]=ans;
        }

        return dp[0];
    }

    int frogJump(vector<int>& heights, int k) {
        int ind=0;
        vector <int> dp(heights.size(),-1);
        return helper_TD(ind,heights,k,dp);
    }

// ind variable is used to consider the elements from ind to n but.....in BU approach we will be using i as index considering


// Bottom Up Approach Space Optimized

// cant do bcoz index dependency cant be predicted
