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
    /*
prefixes with even number of -ves pair with each other
Likewise ... odd .. 
so that the resulting subarray has even number of -ves to make prod +ve
    */
    int cnt_neg=0,cnt_evenNegs=1,cnt_oddNegs=0; // empty subarray has even number of -ves
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        cnt_neg+=a<0;
        cnt_evenNegs+=(cnt_neg&1)==0;
        cnt_oddNegs+=(cnt_neg&1)!=0;
    }
    auto nC2=[](ll n){
        return n*(n-1)/2;
    };
    ll cnt_Pos=nC2(cnt_evenNegs)+nC2(cnt_oddNegs),
        cnt_Neg=nC2(n)+n-cnt_Pos; // total subarrays is nC2 +n
    cout<<cnt_Neg<<" "<<cnt_Pos;
    return 0;
}