// binary search on minimum distance

bool isItPossible(vector <int>&stalls,int nc,int mindist){
        int i=0;
        int lastcow=i;
        nc=nc-1;
        i=i+1;
        
        while(i<stalls.size()){
            // agar min distance sahi h 
            if(stalls[i]-stalls[lastcow]>=mindist){
                lastcow=i;
                nc--;
                
                if(nc<=0){
                    return true;
                }
            }
            
            // aage to bdhoge hi
            i++;
        }
        
        // agr nahi hua to
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        
        int nc=k;
        int ans;
        
        // sort -> taaki place krne k liye max miljaye aur hum cow place sahi order me krpaye
        int lo=0;
        int hi;
        
        sort(stalls.begin(),stalls.end());
        
        hi=stalls[stalls.size()-1];
        
        
        // binary search minimum distance
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(isItPossible(stalls,nc,mid)){
                ans=mid;
                lo=mid+1;
            }
            
            // nahi betha paye
            else{
                hi=mid-1;
            }
        }
        
        return ans;
        
    }