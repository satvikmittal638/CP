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
// implementation me off by 1 me hug dia :(((
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<vector<int>> a(n,vector<int>(m,0));
       int cnt1=0;
       for(auto &i:a){
        for(auto &j:i) {
            cin>>j;
            cnt1+=j;
        }
       }
       ll k=cnt1/2,ans=k*(cnt1-k);
       vector<int> maxCs;
       maxCs.push_back(m-1);// initiator(to be ignored later)
       for(int i=n-1;i>=0;i--){
        int maxC=-1;
        for(int j=0;j<=maxCs.back() && k-a[i][j]>=0;j++){
            k-=a[i][j];
            maxC=max(maxC,j);
        }
        
        maxCs.push_back(maxC);
       }
       reverse(all(maxCs));
       maxCs.pop_back();
    //    for(auto e:maxCs) cout<<e<<' ';
       // now generate moves
       string ops;
       int curC=-1;
       for(int i=0;i<maxCs.size();i++){
        for(int j=curC;j<maxCs[i];j++) ops+="R";
        curC=maxCs[i];
        ops+="D";
       }
       // reach the bottom right
       while(curC < m - 1) {
           ops += "R";
           curC++;
       }
       cout<<ans<<'\n'<<ops<<'\n';

    }
    return 0;
}