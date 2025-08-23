// binary search on minimum days to grow flower as we r going to return the answer for min days

bool isItPossible(int m,int k,int mindaylimit,vector <int> &bloomDay){
        int i=0;
        int bouque=0;
        int adj_flow=0;

        while(i<bloomDay.size()){
            // agr ye din jo h lesser than min days
            if(bloomDay[i]<=mindaylimit){
                adj_flow++;

                // agar flower ug gye ek bhi bouque bnane layak to bouque bna do
                if(adj_flow==k){
                    bouque++;
                    adj_flow=0;

                    // alag se check ki bouque bne ki nahi

                    if(bouque==m){
                        return true;
                    }
                }
                
            }

            // agr us din nahi uga h to count dubara se kro adjacent flowers
            else{
                adj_flow=0;
            }

            i++;
        }

        

        return false;
    }

    int minDays(vector <int>& bloomDay, int m, int k) {
        // using binary search on answers(minimum no days to bloom)

        // edge case
        if((long)m*k>bloomDay.size()) return -1;

        int ans=-1;
        int lo=*min_element(bloomDay.begin(),bloomDay.end());
        int hi=*max_element(bloomDay.begin(),bloomDay.end());

        while(lo<=hi){
            // mid=kya itne minimum no of days me utne phool uggye? ki m bouque bn jaye
            int mid=lo+(hi-lo)/2;

            if(isItPossible(m,k,mid,bloomDay)){
                ans=mid;
                hi=mid-1;
            }

            // agr itne din me nahi uge m bouque bnane layak to aur din wait kro ugne ka
            else{
                lo=mid+1;
            }
        }

        return ans;
    }