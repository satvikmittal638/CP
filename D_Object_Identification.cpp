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
       vector<int> cnt(n+1,0),pos(n+1,0);
       vector<int> x(n);
       for(int i=0;i<n;i++) {
        cin>>x[i];
        pos[x[i]]=i;
        cnt[x[i]]++;
       }
       bool done=0;
       for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            cout<<"? "<<i<<" "<<(i==1?2:1)<<endl;
            int res;cin>>res;
            if(res==0) cout<<"! A";
            else cout<<"! B";
            cout<<endl;
            done=1;
            break;
        }
       }
       // array is a permutation
       if(!done){
        int res1,res2;
        cout<<"? "<<pos[1]+1<<" "<<pos[n]+1<<endl;cin>>res1;
        cout<<"? "<<pos[n]+1<<" "<<pos[1]+1<<endl;cin>>res2;
        if(res1==res2 && res1>=n-1){
            cout<<"! B";
        }
        else{
            cout<<"! A";
        }
        cout<<endl;
       }
       
    }
    return 0;
}