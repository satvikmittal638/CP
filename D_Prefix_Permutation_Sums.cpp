#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void solve(){
    int n;cin>>n;
       multiset<int> ms;
       ll a,preva=0;
       for(int i=0;i<n-1;i++){
        cin>>a;
        ms.insert(a-preva);
        preva=a;
       }
        // check how many elts exceed n
        int more_than_n=-1;
        for(auto e:ms){
            if(e>n){
                if(more_than_n==-1) more_than_n=e;
                else {
                // multiple elements exceeding n found, so no permutation possible
                    cout<<"NO\n";return;
                }
            }
        }
       int rpt_elt=-1;
       for(int i=1;i<=n;i++){
        if(ms.count(i)>1) {
            if(rpt_elt==-1)
                rpt_elt=i;
            else {
                // multiple repetitive elements found,so no permutation is possible
                cout<<"NO\n";
                return;
            }
        }
        if()
       }
       
}


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       
    }
    return 0;
}