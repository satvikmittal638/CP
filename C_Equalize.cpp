#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int ans=0;
    for(int i=0;i<n-1;i++){
        // swap adjacent places
        if(
            (a[i]=='0' && a[i+1]=='1' && b[i]=='1' && b[i+1]=='0')||
            (a[i]=='1' && a[i+1]=='0' && b[i]=='0' && b[i+1]=='1')
        ){
            swap(a[i],a[i+1]);
            ans++;
            i++;// skip next bit
        }
        else{
            if(a[i]!=b[i]){
                a[i]=b[i];
                ans++;
            }
        }
    }
    if(a[n-1]!=b[n-1]) ans++;
    // cout<<a;
    cout<<ans;
    return 0;
}