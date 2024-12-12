#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int k;cin>>k;
       vector<int> a(k);for(auto &i:a) cin>>i;
       sort(a.begin(),a.end());
       int lo=0,hi=k-1;
       while(lo<hi){
        if(a[lo]*a[hi]>k-2){
            hi--;
        }else if(a[lo]*a[hi]<k-2){
            lo++;
        }else{
            break;
        }
       }
    cout<<a[lo]<<" "<<a[hi]<<"\n";
       
    }
    return 0;
}