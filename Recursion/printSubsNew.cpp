// duplicate case ques

#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string ques,string ans){
    // base case
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    char ch=ques[0];
    string remaining=ques.substr(1);

    if(ques[0]==ans[ans.size()-1]){
        printSubsequences(remaining,ans+ch);
    }
    else{
         // 2 calls for ya to character aega ya to nahi aega
        printSubsequences(remaining,ans);
        printSubsequences(remaining,ans+ch);
    }
}

int main(){
    string ques="aab";
    string ans="";
    
 
    printSubsequences(ques,ans);
    return 0;
}
