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
       int n,k;cin>>n>>k;
       string s;cin>>s;
       bool ok=1;
       for(int i=0;i<k && ok;i++){
           for(int j=i+k;j<n;j+=k){
               if((s[i]=='1' && s[j]=='0') || (s[i]=='0' && s[j]=='1')){
                   ok=0;break;
                }
                else if(s[i]=='?' && s[j]!='?'){
                    s[i]=s[j];
                }
            }
        }
        // cout<<s<<" ";
        // check 1st segment of length k
        int cnt0,cnt1,cntq;
        cnt0=cnt1=cntq=0;
        for(int i=0;i<k;i++){
         cnt0+=s[i]=='0';
         cnt1+=s[i]=='1';
         cntq+=s[i]=='?';
        }
        ok&=(cntq>=abs(cnt0-cnt1) && (cntq-abs(cnt0-cnt1))%2==0);
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}