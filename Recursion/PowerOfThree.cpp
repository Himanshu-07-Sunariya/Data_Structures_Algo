// iterative + recursive approach

// bool isPowerOfThree(int n) {
    //     long long x=3;

    //     if(n==1){
    //         return true;
    //     }

    //     while(x<=n){
    //         if(x==n) return true;
    //         x=3*x;
    //     }

    //     return false;
    // }
    bool isPower(int n,long long x){
        // +ve base case
        if(n-x==0) return true;

        // -ve base case
        if(n-x<0) return false; 
        // real recursive work
        return isPower(n,3*x);
    }

    bool isPowerOfThree(int n){
        long long x=3;
        if(n==1) return true;
        if(x>n) return false;
        bool ans=isPower(n,x);
        return ans;
    }