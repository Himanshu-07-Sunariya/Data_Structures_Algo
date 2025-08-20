// Approach 1 :-Recursive approach

#include <iostream>
using namespace std;

void cointoss(int n,string ans){
    // base case
    if(n==0){
        cout<<ans<<endl;
        return;
    }

    // recursive calls

    // 2 coin h bro to do recursive calls kyunki ya to head ayega ya tail aega
    // ye coin use hogya toss hoke to dusre coin ko baari do iski baari khtm hogyi
    cointoss(n-1,ans+"H");
    cointoss(n-1,ans+"T");
}

int main(){
    cout<<"Enter the No. of coins:-"<<endl;
    int n;
    cin>>n;

    string ans="";

    cointoss(n,ans);
    return 0;
}