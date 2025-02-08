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
       vector<vector<int>> words(n,vector<int>(6,0));
       for(int i=0;i<n;i++){
        string s;cin>>s;
        words[i][5]=s.length(); // store the length
        for(auto c:s){
            words[i][c-'a']++;
        }
       }

       int ans=0;
       for(int dom=0;dom<5;dom++){
        /*
        freq[c] gives +ve weight and freq[others] gives -ve weight
        
        */
        // sort in descending based on freq[c]-freq[others]
        sort(all(words),[&](auto w1,auto w2){
            return 2*w1[dom]-w1[5]>2*w2[dom]-w2[5];
        });
        int curFreqDom=0,totalLen=0;
        int i=0;
        while(i<n && (2*(curFreqDom+=words[i][dom])>(totalLen+=words[i][5]) || totalLen==0)){
            i++;
        }
        ans=max(ans,i);
       }
       cout<<ans<<"\n";
    }
    return 0;
}