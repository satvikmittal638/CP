#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n),freq(n+1,0);

       for(auto &i:a) {
        cin>>i;
        freq[i]++;
       }
       int count=0;
       for(auto f:freq){
        count+=f/2;
       }
       cout<<count<<"\n";
    }
    return 0;
}