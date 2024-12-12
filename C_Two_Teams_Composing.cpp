#include<bits/stdc++.h>
using namespace std;

// O(n)
bool canMakeTeamOf(int x,int n,vector<int> freq){
    // make team 2
    int maxFreqInd=0;
    for(int i=1;i<=n;i++){
        if(freq[maxFreqInd]<freq[i]){
            maxFreqInd=i;
        }
    }
    if(freq[maxFreqInd]<x){
        return 0; // team 2 can't be made
    }
    freq[maxFreqInd]-=x; // take x players from here
    //make team 1
    int sz=0;
    for(int i=0;i<=n;i++){
        sz+=(freq[i]>0);// take 1 player from each skill
    }
    if(sz<x) return 0; // team 1 can't be made
    return 1; // both teams made :)
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> freq(n+1,0);
       for(int i=0;i<n;i++) {
        int a;cin>>a;
        freq[a]++;
       }
        int lo=0,hi=n/2;
        // net TC: O(nlogn)
        while(lo<hi){
            int mid=lo+(hi-lo+1)/2;
            if(canMakeTeamOf(mid,n,freq)){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        cout<<lo<<"\n";

    }
    return 0;
}