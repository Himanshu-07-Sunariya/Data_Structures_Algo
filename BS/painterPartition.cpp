// binary search on answers that is maximum days required to paint all the walls by k painters and days should remain minimum

bool isItPossible(vector <int>&arr,int np,int nw,int maxtimelimit){
        int time_for_wall=0;
        int painter=1;
        int i=0;
        
        while(i<nw){
            // agar humari ye wall ko paint krne ka time is in range for maxtime limit
            if(time_for_wall+arr[i]<=maxtimelimit){
                time_for_wall+=arr[i];
                i++;
            }
            
            else{
                painter++;
                time_for_wall=0;
                
                if(painter>np){
                    return false;
                }
                
            }
            
        }
        
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        // we ll be applying the binary search on the min time for each painter and 
        // the max time for combined
        
        // edge case
        
        
        int lo=*min_element(arr.begin(),arr.end());
        // int lo=0;
        int hi=0;
        int ans;
        
        int np=k;
        int nw=arr.size();
        
        for(int i=0; i<arr.size(); i++){
            hi+=arr[i];
        }
        
        
        while(lo<=hi){
            // mid=max time limit to be painted by the each painter
            int mid=lo+(hi-lo)/2;
            
            // hume is mid ko kam krna h like saari wall paint hogyi is time me yaani ki wo
            // sab walls paint hojaye us time ka max hoga
            
            if(isItPossible(arr,np,nw,mid)){
                ans=mid;
                hi=mid-1;
            }
            
            // itne max time k sath saari walls cover nahi ho parhi
            else{
                lo=mid+1;
            }
        }
        
        return ans;
    }