// Approach 1:- Recursive approach

int min_num=INT_MAX;

    void perfectSquares(int n,int cnt){
        //+ve base case
        if(n==0){
            min_num=min(min_num,cnt);
            return;
        }
        // -ve base case
        if(n<0){
            return;
        }
        // recursive calls

        for(int i=1; i*i<=n; i++){
            perfectSquares(n-(i*i),cnt+1);
        }
    }
    int numSquares(int n) {
        int cnt=0;
        perfectSquares(n,cnt);

        return min_num;
    }


// Approach 2:- maybe better recursive one

