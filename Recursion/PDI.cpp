#include <bits/stdc++.h>
using namespace std;

void pdi(int n){
    // base case
    if(n==0) return;

    // print statement
    cout<<n<<endl;

    // recursive call
    pdi(n-1);
}

int main(){
    int n=5;
    pdi(n);
    return 0;
}