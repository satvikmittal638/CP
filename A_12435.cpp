#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    vector<int> a(5);
    for(auto &i:a) cin>>i;
    bool ok=0;
    for(int i=0;i<4;i++){
        swap(a[i],a[i+1]);
        if(is_sorted(all(a))){
            ok=1;break;
        }
        else{
            swap(a[i],a[i+1]);
        }
    }
    cout<<(ok?"Yes":"No");
    return 0;
}