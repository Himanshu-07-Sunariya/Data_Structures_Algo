// approach subsequence pattern

class Solution {
  public:
    vector <string> finalans;
    
    void helper(int num,string ans,int prev){
        // base case
        if(num==0){
            finalans.push_back(ans);
            return;
        }
        
        // -ve base case
        if(prev==1){
            // self work && recursive calls
            helper(num-1,ans+"0",0);
        }
        
        else{
            helper(num-1,ans+"0",0);
            helper(num-1,ans+"1",1);
        }
        
        

        
    }
    vector<string> generateBinaryStrings(int num) {
        string ans;
        
        int prev=0;
        
        helper(num,ans,prev);
        
        return finalans;
    }
};