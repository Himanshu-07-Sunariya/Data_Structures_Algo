// brute force approach

void lexical_counting(int curr,int n,vector <int> &ans){
        // base case
        if(curr>n){
            return;
        }
        
        // printing the lexical counting:
        if(curr!=0){
            ans.push_back(curr);
        }

        // recursive calls
        // extra 0 call handle
        // this will be handled here

        for(int i=0;i<10; i++){
            if(i==0 && curr==0) continue;

            lexical_counting(curr*10+i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector <int> ans;
        lexical_counting(0,n,ans);
        return ans;
    }