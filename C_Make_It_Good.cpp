#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       reverse(a.begin(),a.end());
       //find the largest neigbourhood of the first maxima from the start
       // shaped like a /\
       // remove the remaining suffix

       // find increasing segment from start
       int i=0;
       while(i<n-1 && a[i]<=a[i+1]) i++;
       // find decreasing segment after reaching the maxima
       while(i<n-1 && a[i]>=a[i+1]) i++;
       cout<<n-(i+1)<<"\n"; // remove the rest of the suffix

    }
    return 0;
}