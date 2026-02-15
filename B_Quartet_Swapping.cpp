#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> ods,evs;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        if(i%2==0) evs.push_back(a);
        else ods.push_back(a);
       }
       sort(rall(ods));
       sort(rall(evs));
       vector<int> ans(n);
       for(int i=0;i<n;i+=2){
        ans[i]=evs.back();evs.pop_back();
       }

       for(int i=1;i<n;i+=2){
        ans[i]=ods.back();ods.pop_back();
       }
       for(auto e: ans) cout<<e<<' ';
       cout<<'\n';
    }
    return 0;
}