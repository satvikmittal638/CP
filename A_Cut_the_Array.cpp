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
       vector<int> a(n+1),pref(n+1,0);
       for(int i=1;i<=n;i++) {
        cin>>a[i];pref[i]=pref[i-1]+a[i];
        }
        int ansl=0,ansr=0;
        bool done=0;
        for(int l=1;l<n && !done;l++){
            for(int r=l+1;r<n;r++){
                int p=pref[l]%3, m=(pref[r]-pref[l])%3, s=(pref[n]-pref[r])%3;
                if(p==m && m==s || (p!=m && m!=s && p!=s)){
                    ansl=l;
                    ansr=r;
                    done=1;
                    break;
                }
            }
        }
        cout<<ansl<<" "<<ansr<<'\n';


       
       
    }
    return 0;
}