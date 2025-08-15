// iterative approach

bool isPowerOfFour(int n) {
        if(n==1) return true;

        long long int x=4;
        while(x<=n){
            if(x==n) return true;
            x=4*x;
        }

        return false;
    }


// Recursive Approach

bool isPower(int n,long long int x){
        // +ve base case
        if(x==n) return true;
        // -ve base case
        if(x>n) return false;
        // recursive calls
        return isPower(n,x*4);
    }


    bool isPowerOfFour(int n){
        //need helper function
        // one edge case
        if(n==1) return true;

        long long int x=4;

        return isPower(n,x);
    }