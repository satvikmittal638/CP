#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       long long sum=accumulate(a.begin(),a.end(),0);
       cout<<(sum%2==0?"Bob":"Alice")<<"\n";
    }
    return 0;
}