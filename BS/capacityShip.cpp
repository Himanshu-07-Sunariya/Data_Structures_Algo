//BRUTE FORCE APPROACH 
 
 

// // int sumofweights(vector <int> weights){
    //     int sum=0;
    //     for(int i:weights){
    //         sum+=i;
    //     }
    //     return sum;
    // }

    // int shipWithinDays(vector<int>& weights, int days) {
    //     int cap=*max_element(weights.begin(),weights.end());
    //     int daycnt=1;
    //     int sum=sumofweights(weights);
    //     int psum=0;

    //     while(cap<=sum){
    //         for(int i=0; i<weights.size(); i++){
    //             psum+=weights[i];
    //             if(psum>cap && weights[i]<=cap){
    //                 daycnt++;
    //                 psum=weights[i];
    //             }
    //             if(weights[i]>cap){
    //                 cap=weights[i];
    //                 i=0;
    //                 psum=0;
    //                 daycnt=0;
    //             }
    //         }
    //         if(daycnt>days){
    //             cap++;
    //         }
    //         if(daycnt==days){
    //             return cap;
    //         }
    //         psum=0;
    //         daycnt=0;
    //     }
    //     return -1;
    // }



// binary search on answers(OPTIMAL APPROACH)

bool isItPossible(vector <int> &weights,int days,int nw,int weightlimit){
        int curr_wt=0;
        int daycnt=1;

        int i=0;

        while(i<nw){
            // weight<=weightlimit uthane ki per day
            if(curr_wt+weights[i]<=weightlimit){
                curr_wt+=weights[i];
                i++;
            }

            // weightlimit crossed
            else{
                daycnt++;
                curr_wt=0;

                if(daycnt>days){
                    return false;
                }
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days){
        // ya to us din kuch na uthaye
        int lo=0;

        // ya to us din wt uthane ki limit 
        int hi=0;

        int nw=weights.size();

        for(int i=0; i<weights.size(); i++){
            hi+=weights[i];
        }

        int ans;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            // kya hum specified no of days me itna wazan utha parhe h

            if(isItPossible(weights,days,nw,mid)){
                ans=mid;
                hi=mid-1;
            }

            // specific days me itna wazan nahi utha paye
            else{
                lo=mid+1;
            }
        }
        return ans;
    }