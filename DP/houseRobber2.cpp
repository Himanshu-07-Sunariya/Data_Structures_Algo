// Recursive approach

int helper(int ind,vector <int> &nums,int n){
        // edge case
        if(n==1) return nums[ind];
        if(n==2) return max(nums[ind],nums[ind+1]);
        
        // +ve base case
        if(ind>=n){
            return 0;
        }

        // recursive calls
        // pick /not pick
        int include=nums[ind]+helper(ind+2,nums,n);
        int exclude=helper(ind+1,nums,n);

        return max(include,exclude);
    }

    int rob(vector<int>& nums) {
        int ind=0;
        int ans1,ans2;

        // pick the last house and skipping the first house
        int n=nums.size();
        ans1=helper(ind+1,nums,n);

        // pick the first house and skipping the last house
        ans2=helper(ind,nums,n-1);

        return max(ans1,ans2);
    }

// TOP DOWN Approach

int helper_TD(int ind,vector <int> &nums,int n,vector <int> &dp){
        // +ve base case
        if(ind>=n){
            return 0;
        }

        // dp step 2
        if(dp[ind]!=-1){
            return dp[ind];
        }

        // recursive calls
        // pick /not pick
        int include=nums[ind]+helper_TD(ind+2,nums,n,dp);
        int exclude=helper_TD(ind+1,nums,n,dp);

        dp[ind]=max(include,exclude);
        return dp[ind];
    }

    int rob(vector<int>& nums) {
        int ind=0;
        int ans1,ans2;

        // // pick the last house and skipping the first house
        // int n=nums.size();
        // ans1=helper(ind+1,nums,n);

        // // pick the first house and skipping the last house
        // ans2=helper(ind,nums,n-1);

        // return max(ans1,ans2);
        int n=nums.size();

        if(n==1) return nums[ind];
        if(n==2) return max(nums[ind],nums[ind+1]);

        vector <int> dp1(n+1,-1);
        ans1=helper_TD(ind+1,nums,n,dp1);

        vector <int> dp2(n,-1);
        ans2=helper_TD(ind,nums,n-1,dp2);

        return max(ans1,ans2);
    }

// Bottom Up approach

int helper_BU(int ind,vector <int> &nums,int n){
        // 1. Create dp array
        vector <int> dp(n+1,-1);

        // 2. base case fill
        dp[n]=0;

        for(int i=n-1; i>=ind; i--){
            // pick /not pick
            int include=nums[i];
            if(i+2<n){
                include=nums[i]+dp[i+2];
            }
            int exclude=dp[i+1];

            dp[i]=max(include,exclude);
        }

        return dp[ind];
    }

    int helper_BUSO(int ind,vector <int> &nums,int n){
        // 1. Create dp array
        // vector <int> dp(n+1,-1);
        int next1=0;
        int next2=0;
        int curr;

        // 2. base case fill
        // dp[n]=0;

        for(int i=n-1; i>=ind; i--){
            // pick /not pick
            int include=nums[i];
            if(i+2<n){
                include=nums[i]+next2;
            }
            int exclude=next1;

            curr=max(include,exclude);

            // shifting 
            next2=next1;
            next1=curr;
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        int ind=0;
        int ans1,ans2;

        // // pick the last house and skipping the first house
        // int n=nums.size();
        // ans1=helper(ind+1,nums,n);

        // // pick the first house and skipping the last house
        // ans2=helper(ind,nums,n-1);

        // return max(ans1,ans2);
        int n=nums.size();

        if(n==1) return nums[ind];
        if(n==2) return max(nums[ind],nums[ind+1]);

        // vector <int> dp1(n+1,-1);
        // ans1=helper_TD(ind+1,nums,n,dp1);

        // vector <int> dp2(n,-1);
        // ans2=helper_TD(ind,nums,n-1,dp2);

        ans1=helper_BUSO(ind+1,nums,n);
        ans2=helper_BUSO(ind,nums,n-1);

        return max(ans1,ans2);
    }