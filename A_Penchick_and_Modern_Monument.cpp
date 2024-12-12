#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> h(n),freq(n+1,0);
       for(int i=0;i<n;i++){
        cin>>h[i];
        freq[h[i]]++;
       }
       int maxFreqInd=0;
       for(int i=0;i<freq.size();i++){
        if(freq[i]>freq[maxFreqInd]){
            maxFreqInd=i;
        }
       }
    int ans=n-freq[maxFreqInd];
       cout<<ans<<"\n";
    }
    return 0;
}