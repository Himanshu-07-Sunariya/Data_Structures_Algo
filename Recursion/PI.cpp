// recursive approach for the PRINT INCREASING QUESTION

// Approach 1:- one variable

#include <iostream>
using namespace std;

// void printInc(int n){
//     // base case
//     if(n==0){
//         return;
//     }

//     // recursive calls
//     printInc(n-1);
//     cout<<n<<endl;
// }

// int main(){
//     // for the print increasing function we need till where should i print;
//     int n;
//     cout<<"Enter the value of n:-"<<endl;
//     cin>>n;

//     printInc(n);
//     return 0;
// }


//Approach 2:- Recursive + two variable

void PI(int n,int i){
    // base case
    if(i==n){
        cout<<i<<endl;
        return;
    }

    // print time
    cout<<i<<endl;
    
    //recursive calls
    PI(n,i+1);
}

int main(){
    int n;
    cout<<"Enter the value of the n:-"<<endl;
    cin>>n;

    int i=1;
    PI(n,i);
    return 0;
}