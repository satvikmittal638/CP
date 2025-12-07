#include<bits/stdc++.h>
using namespace std;
#define ll			 long long
#define pb			 push_back
#define pii			 pair<int,int>
#define mii			 map<int,int>
#define vi			 vector<int>
#define mp			 make_pair
#define mod			 1000000007
#define input			 for(int i=0; i<n; i++) cin>>v[i];
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((a[j]%a[i])%2==0){
                cout<<a[i]<<" "<<a[j]<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
