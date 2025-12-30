// Recursive approach

#include <bits/stdc++.h>
using namespace std;

int maxSumOfAdj(int ind,vector <int> &nums){
    // +ve base case
    if(ind>=nums.size()) return 0;

    if(nums[ind]<0){
        return maxSumOfAdj(ind+1,nums);
    }
    // no need to handle it seperately,can be handled when max condition is used

    //pick /not pick
    int include=nums[ind]+maxSumOfAdj(ind+2,nums);
    int exclude=maxSumOfAdj(ind+1,nums);

    return max(include,exclude);
}

int main(){
    int ind=0;
    vector <int> nums={4,-1,7,-3,9};
    cout<<maxSumOfAdj(ind,nums)<<endl;
    return 0;
}