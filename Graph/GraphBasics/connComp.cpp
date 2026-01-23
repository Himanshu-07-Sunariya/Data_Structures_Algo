#include <bits/stdc++.h>
using namespace std;

int main(){
    // ANY TRAVERSAL ALGO BUT THE PATTERN TO COVER ALL THE VERTICES OF GRAPH WILL BE SAME 
    // LIKE THIS:- U CAN APPLY ANY TRAVERSAL ALGO
    // 1 based graph it is
    // we will be using visited array so that no vertex is repeated and the traversal is stucked..
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            traversal(i);
        }
    }

    return 0;
}