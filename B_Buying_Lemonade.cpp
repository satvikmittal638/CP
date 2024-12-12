#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
checks if we can get atleast k cans in cnt_press moves using an optimal strategy    
*/
bool canGetAtleastK(long long k,long long cnt_press,vector<long long> a){
    long long cnt=0;
    int i=0;
    while(i<a.size() && k>0){
        cnt+=a[i]+1; // did a[i]+1 presses
        k-=a[i]; // received a[i] cans
    }
    return cnt<=cnt_press;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        vector<long long> a(n);
        for(auto &i:a) cin>>i;
        sort(a.begin(),a.end());
        long long lo=1, hi=accumulate(a.begin(),a.end(),0)+n; // when a slot becomes empty, we see it only after doing 1 additional button press
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(canGetAtleastK(k,mid,a)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        cout<<lo<<"\n";
    }   
    return 0;
}