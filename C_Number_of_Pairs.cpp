#include<bits/stdc++.h>
using namespace std;

long long cnt_PairSumLessEqK(int k, vector<int> a){
    long long cnt=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        int other=k-a[i];
        // find last index j>i st a[j]<=k-a[i]
        // number of pairs possible with a[i] are j-i now
        auto it=upper_bound(a.begin()+i+1,a.end(),other);
        it--;
        int j=it-a.begin();
        cnt+=j-i;
    }
    return cnt;
}


int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,l,r;cin>>n>>l>>r;
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(a.begin(),a.end());
       long long A=cnt_PairSumLessEqK(r,a);
       long long B=cnt_PairSumLessEqK(l-1,a);
       cout<<A-B<<"\n";
    }
    return 0;
}