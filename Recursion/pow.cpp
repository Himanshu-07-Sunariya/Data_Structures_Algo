// brute force approach + edge case handled = better approach

 double pow(double x,int n){
        // base case
        if(n==0) return 1;

        //self work + rec

        return x*pow(x,n-1);
    }
    double myPow(double x, int n) {
        // edge case
        if(n<0){
            return 1/( pow(x,-n));
        }
        //base case
        if(n==0) return 1;
        
        // self work + recursive calls
        double recAns=myPow(x,n-1);

        return x*recAns;
    }


// Optimal Approach


    double pow(double x,long long n){
        // base case
        if(n==0) return 1;

        // self work
        double half=pow(x,n/2);

        // /recursive calls
        if(n%2==0){
            return half*half;
        }

        return x*half*half;
    }
    double myPow(double x, int n) {
        // edge case
        if(n<0){
            long long  N=n;
            return 1.0 /( pow(x,-N));
            // double k division horha h
        }
        //base case
        if(n==0) return 1;
        
        // self work
        double half=myPow(x,n/2);

        // /recursive calls
        if(n%2==0){
            return half*half;
        }

        return x*half*half;
    }



// best optimal approach all case handled

double pow(double x,long long N){
        // base case
        if(N==0) return 1;

        // self work 
        double half=pow(x,N/2);

        if(N%2==0) return half*half;

        return x*half*half;
    }

    double myPow(double x,int n){
        // -ve power case
        long long N=n;
        if(N<0){
            N=-N;
            return 1.0/pow(x,N);
        }

        // +ve power case:- isme simple krlo
        return pow(x,N);
    }