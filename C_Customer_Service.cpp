#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> cnt_1;
       for(int i=0;i<n;i++){
        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        // count number of trailing ones
        int j=n-1;
        while(a[j]==1 && j>=0){
            j--;
        }
        cnt_1.push_back(n-j-1);
       }
       sort(all(cnt_1)); 
       // now use each queue so that minm power(i.e. minm trailing 1 q) is used first greedily
       int k=0;
       int mex=0;
       for(int i=0;i<n;i++){
        while(k<n && cnt_1[k]<mex)k++;
        if(k<n) {
            mex++;
            k++;// used this queue
        }
        else break;
       }
       cout<<mex<<"\n";
    }
    return 0;
}