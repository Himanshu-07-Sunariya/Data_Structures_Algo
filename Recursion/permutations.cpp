#include <bits/stdc++.h>
using namespace std;


// duplicate wala baad me krenge


void printPermutations(string ques,string ans){
    // base case
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    // 1.Accessing the character jiski permutations nikalenge uski location fix krke
    // 2.Remaining ques ko bhi pass krenge sth sth

    // calls ques length k hisaab se lgengi
    for(int i=0; i<ques.length(); i++){
        char ch=ques[i];
        string rem=ques.substr(0,i)+ques.substr(i+1);

        // recursive call time yesssss
        printPermutations(rem,ans+ch);
    }
}

int main(){
    string ques="abc";
    string ans="";

    printPermutations(ques,ans);
    return 0;
}