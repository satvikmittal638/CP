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
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       vector<vector<vector<int>>> sacks;
       // we can freely match elts within a sack
       sacks.push_back({a,b});
       int ans=0;
       for(int i=30;i>=0;i--){
        int mask=(1<<i);
        bool canHave1=1;
        vector<vector<vector<int>>> tmpSacks;
        for(auto sack:sacks){
            auto cura=sack[0],curb=sack[1];
            vector<vector<int>> bita(2),bitb(2);
            for(auto e:cura){
                int bit=(e&mask)!=0;
                bita[bit].push_back(e);
            }
            for(auto e:curb){
                int bit=(e&mask)!=0;
                bitb[bit].push_back(e);
            }
            // this bit will be 1 in f(a,b)
            // segregate them again
            if(bita[0].size()==bitb[1].size()){
                if(bita[0].size()){
                    tmpSacks.push_back({bita[0],bitb[1]});
                }
                if(bita[1].size()){
                    tmpSacks.push_back({bita[1],bitb[0]});
                }
            }
            // this bit can't be 1 in f(a,b)
            // set it to 0 and no segregation of this sack
            else{
                canHave1=0;
                break;
            }
        }
        if(canHave1) {
            ans|=mask;
            sacks=tmpSacks;
        }
        }
        cout<<ans<<'\n';
    }
    return 0;
}