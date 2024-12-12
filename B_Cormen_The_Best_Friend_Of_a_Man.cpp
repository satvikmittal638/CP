#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    vector<int> a(n),extra_walks(n,0);
    for(auto &i:a) cin>>i;
    // no extra walk required on 1st(and on the last day also)
    for(int i=1;i<n;i++){
        /*
        if there are not enough walks on i and i-1 days, its better to walk more on ith day
        since it will help us in the future(greedy approach)
        */ 
       extra_walks[i]+=max(k-a[i]-(a[i-1]+extra_walks[i-1]),0); // to add non-negative additional steps

    }
    long long totalWalks=accumulate(extra_walks.begin(),extra_walks.end(),0);
    cout<<totalWalks<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]+extra_walks[i]<<" ";
    }
    return 0;
}