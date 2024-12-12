#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
        vector<pair<int,int>> a(n);
        for(auto &i:a) cin>>i.first;
        for(auto &i:a) cin>>i.second;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(a[i].first,a[i].second);
        }
        int maxSum=INT_MIN;
        // to move down via tha ith col
        for(int i=0;i<n;i++){
            /*
            the col whose maxm is at the top moves to the left and
            the one which has maxm at the bottom moves to the right
            */
            maxSum=max(maxSum,sum+min(a[i].first,a[i].second));
        }
        cout<<maxSum<<"\n";
    }
    return 0;
}