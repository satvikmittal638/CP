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
       vector<string> g(n),w(n),numToStr;
       vector<int> ng(n),nw(n);
       for(int i=0;i<n;i++){
        cin>>g[i]>>w[i];
        numToStr.emplace_back(g[i]);
        numToStr.emplace_back(w[i]);
       }
       // keep unique only
       sort(all(numToStr));
        numToStr.erase(unique(all(numToStr)), numToStr.end());
       map<string,int> strToNum;
       for(int i=0;i<numToStr.size();i++){
        strToNum[numToStr[i]]=i;
       }
       for(int i=0;i<n;i++){
        ng[i]=strToNum[g[i]];
        nw[i]=strToNum[w[i]];
       }
       // now comparisons of artists and genras are O(1)

       // try all subsets
       int ans=n;// base:remove all
       for(int i=1;i<(1<<n);i++){
        // construct subset
        int sz=0;
        vector<vector<int>> gs(40);
        for(int j=0;j<=16;j++){
            // elt in subset
            if((i>>j)&1){
                sz++;
                gs[ng[j]].emplace_back(j);
            }
        }

        // remove empty places from g 
        // so that adjacent vectors are now non-empty
        gs.erase(
            remove_if(all(gs),
                    [](const vector<int>& x) {
                        return x.empty();
                    }),
            gs.end()
        );
        // now check if different gs can be connected together
        // checks if a index has been used for same writer connections
        vector<bool> used(40,0);
        vector<int> conns(40,0);
        int conn_comp=gs.size();
        for(int i=0;i<gs.size()-1;i++){
            bool done=0;
            for(int j=i+1;j<gs.size() && !done && conns[i]<=2 && conns[j]<=2;j++){
                for(auto e1:gs[i]){
                    for(auto e2:gs[j]){
                        // check if same writer
                        if(nw[e1]==nw[e2] && !used[e1] && !used[e2]){
                            used[e1]=1;
                            used[e2]=1;
                            conns[i]++;
                            conns[j]++;
                            conn_comp--;
                            done=1;
                            break;
                            // now gs[i] and gs[j] connected
                        }
                    }
                    if(done) break;
                }
            }
        }
        if(conn_comp==1){
            ans=min(ans,n-sz);
        }
       }
       cout<<ans<<'\n';


    }
    return 0;
}