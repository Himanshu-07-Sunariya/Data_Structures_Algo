bool isItPossible(vector <int> &pages,int nb,int ns,int pagelimit){
        int student_no=1;
        int pagesread=0;

        int i=0;

        while(i<nb){
            if(pagesread+pages[i]<=pagelimit){
                pagesread+=pages[i];
                i++;
            }
            else{
                student_no++;
                pagesread=0;

                if(student_no>ns){
                    return false;
                }
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        // applying the binary search on the sum of the whole array
        // like the book allocation problem:- ya to wo book pdhega ya to wo ek full sum ki range ke beeech me rhna chahiye

        int lo=0;
        int hi=0;
        int ns=k;
        int nb=nums.size();
        int ans;

        for(int i=0; i<nums.size(); i++){
            hi+=nums[i];
        }

        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isItPossible(nums,nb,ns,mid)){
                ans=mid;
                hi=mid-1;
            }

            // not possible answer
            else{
                lo=mid+1;
            }
        }

        return ans;
    }