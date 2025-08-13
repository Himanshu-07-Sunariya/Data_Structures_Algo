// writing the code for the FIRST COME FIRST SERVE ALGORITHM

#include <bits/stdc++.h>
using namespace std;

// you are given the arrival time and burst time you have to make function for the CT, Total Arrival Time(TAT), WT()Waiting time
int* fcfs_ct(int* at,int* bt,int length){
    
    int* ct=new int[length];

    int len=0;
    for(int i=0; i<length; i++){
        ct[i]=at[i]+bt[i]+len;
        len+=bt[i];
    }

    return ct;
}

int* fcfs_tat(int* at,int *ct,int length){
    int* tat=new int[length];

    for(int i=0; i<length; i++){
        tat[i]=ct[i]-at[i];
    }

    return tat;
}

int *fcfs_wt(int* tat,int* bt,int length){
    int *wt=new int[length];

    for(int i=0; i<length; i++){
        wt[i]=tat[i]-bt[i];
    }

    return wt;
}

int main(){

    int at[4]={0,0,0,0};
    int bt[4]={3,7,2,6};

    cout<<"Arrival time is:-"<<endl;

    for(int i=0; i<4; i++){
        cout<<at[i]<<" ";
    }

    cout<<endl;


    cout<<"Burst time is:-"<<endl;

    for(int i=0; i<4; i++){
        cout<<bt[i]<<" ";
    }

    cout<<endl;

    auto ct=fcfs_ct(at,bt,4);

    cout<<"Completion time:-"<<endl;

    for(int i=0; i<4; i++){
        cout<<ct[i]<<" ";
    }
    cout<<endl;

    

    auto tat=fcfs_tat(at,ct,4);

    cout<<"Turn Around Time:-"<<endl;

    for(int i=0; i<4; i++){
        cout<<tat[i]<<" ";
    }

    cout<<endl;

    auto wt=fcfs_wt(tat,bt,4);

    cout<<"Waiting Time:-"<<endl;

    for(int i=0; i<4; i++){
        cout<<wt[i]<<" ";
    }

    cout<<endl;

    cout<<"Average Turn Around Time:-"<<endl;

    int ATAT=0;

    for(int i=0;i<4; i++){
        ATAT+=tat[i];
    }

    cout<<"atat is:-"<<ATAT/4<<endl;


    cout<<"Average Waiting Time:-"<<endl;

    int AWT=0;

    for(int i=0;i<4; i++){
        AWT+=wt[i];
    }

    cout<<"awt is:-"<<AWT/4<<endl;


    return 0;
}