// brute force approach

int powerOfTen(int times){
        int ten=1;
        for(int i=0; i<times; i++){
            ten=ten*10;
        }

        return ten;
    }
    
    int maximum69Number (int num) {
        int maxi=num;
        int temp;
        int x=1;
        int i=1;

        while(x>0){
            // value allot wala kaam
            temp=num;
            int mod=powerOfTen(i);
            // single digit extraction
            x=(temp/(mod/10))%10;

            // main if conditions
            // case 1:- 6 vala case
            if(x==6){
                x=3;
                temp=temp+(x*(mod/10));
                maxi=max(temp,maxi);
            }

            // case 2:- 6 vala case
            if(x==9){
                x=3;
                temp=temp-(x*(mod/10));
                maxi=max(temp,maxi);
            }

            i++;
        }

        return maxi;
    }