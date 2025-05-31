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
       string s;cin>>s;
       // now there exists atleast 1 zero
       int k=-1;
       for(int i=0;i<n/2;i++){
        if(s[i]=='0') {
            k=i+1;
            break;
        }
       }
       if(k!=-1){
        // 0 at position k in the 1st half
        cout<<k<<" "<<n<<" "<<k+1<<" "<<n<<"\n";
        continue;
       }
       for(int i=n/2;i<n;i++){
        if(s[i]=='0') {
            k=i+1;
            break;
        }
       }
       if(k!=-1){
        // 0 at position k in the 2nd half
        cout<<"1 "<<k<<" "<<"1 "<<k-1<<"\n";
        continue;
       }
       
       cout<<"1 "<<n-1<<" 2 "<<n<<"\n";

    }
    return 0;
}