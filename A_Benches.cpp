#include<bits/stdc++.h>
using namespace std;

bool canBeMax(int k,vector<int> a,int m){
    int morePpl=0;
    for(int i=0;i<a.size();i++){
        if(a[i]<=k){
            morePpl+=k-a[i];
        }else{
            return 0;
        }
    }
    // if coming ppl are in excess than required to reach a given maxm no. of ppl on the bench
    if(morePpl<m){
        return 0;
    }
    return 1;
}

int main()
{
    int n,m;cin>>n>>m;
    vector<int> a(n);for(auto &i:a) cin>>i;
    int maxK=*max_element(a.begin(),a.end())+m;

    // B.S. minK
    int lo=*min_element(a.begin(),a.end()),hi=maxK;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(canBeMax(mid,a,m)){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo<<" "<<maxK;
    return 0;
}