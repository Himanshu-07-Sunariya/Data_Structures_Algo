// brute force approach

// int minEatingSpeed(vector<int>& piles, int h) {
    //     // int sum=0;
    //     // int hour=0;
    //     // for(int i=0; i<piles.size(); i++){
    //     //     sum+=piles[i];
    //     // }
    //     // int k=1;
    //     // while(k<=sum){
    //     //     hour=0;
    //     //     for(int i=0; i<piles.size(); i++){
    //     //         hour+=ceil((double) piles[i]/k);
    //     //     }
    //     //     if(hour>h){
    //     //         k++;
    //     //     }
    //     //     else if(hour<=h){
    //     //         return k;
    //     //         break;
    //     //     }
    //     // }
    //     // return -1;      


    //     // optimal approach
    //     int maxPile = *max_element(piles.begin(), piles.end());
    //     int low=1;
    //     int high=maxPile;
    //     int ans;
    //     int hour;

    //     while(low<=high){
    //         hour=0;
    //         int mid=low + (high-low)/2;
    //         for(int i=0; i<piles.size(); i++){
    //             hour+=ceil((double) (piles[i]) / (double) (mid) );
    //         }
    //         if(hour<=h){
    //             ans=mid;
    //             high=mid-1;
    //         }
    //         else{
    //             low=mid+1;
    //         }
    //     }
    //     return low;
    // }



// OPTIMAL APPROACH

bool isItPossible(vector <int> &piles,int nbp,int nh,int mid){
        int i=0;
        double hrcnt=0;

        while(i<nbp){
            // kya is dabbe se saare kele khapaunga
            int temp=piles[i];

            if(temp<=mid){
                hrcnt++;
                i++;
            }

            // arey is dabbe me zyda kele h dusre ghnte me bhi khaunga
            else{
                hrcnt+=ceil((double)temp/mid);
                i++;
            }
        }

        if(hrcnt<=nh){
            return true;
        }

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h){
        // koko nalla h kuch nahi khapaya(nahi nalla nahi h kch to khaega)
        // atleast ek kela to khaega hi
        int lo=1;

        // koko avval darje ka baandar h sb thoos gya
        // sabse bda wala box k sb khagya
        int hi=0;
        int nh=h;
        int nbp=piles.size();
        int ans;
        int maxi=INT_MIN;

        // int hi = *max_element(piles.begin(), piles.end());

        for(int i=0; i<piles.size(); i++){
            maxi=max(piles[i],maxi);
        }

        // aur zyda se zyda ek kele ki peti khajaega
        hi=maxi;

        // ques is ek pile ko khane me kitna time lgega agr sab pile ke khane ka time ==h then u 
        // solved it bitch

        // binary search on answer method
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isItPossible(piles,nbp,nh,mid)){
                //ari betichod har ek ghnte me (mid count) banana khaane pr hum sahi time pr saare
                // kele kha gye??

                ans=mid;
                // agar humne wqt se phle kha liya itne to kya hum aur km speed se
                //  khaake bhi sahi time
                // tk khele kha skte h
                hi=mid-1;
            }

            // agar hum nahi kha paye is time limit kele to hume aur speed me khaane chahiye kele
            else{
                lo=mid+1;
            }
        }

        return ans;
    }