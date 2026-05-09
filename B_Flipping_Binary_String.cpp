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
       string s;cin>>s;
       vector<int> inds0,inds1;
       for(int i=0;i<n;i++){
        if(s[i]=='0') inds0.push_back(i+1);
        else inds1.push_back(i+1);
       }
       
       if(inds0.size()%2!=0){
        cout<<inds0.size()<<'\n';
        for(auto e:inds0) cout<<e<<' ';
       }
       else if(inds1.size()>0 && inds1.size()%2==0){
        cout<<inds1.size()<<'\n';
        for(auto e:inds1) cout<<e<<' ';
       }
       else if(inds0.size()==n){
        cout<<"0";
       }
       else{
        cout<<"-1";
       }
       cout<<'\n';
    }
    return 0;
}