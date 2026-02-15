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
       ll a,b,c,d;cin>>a>>b>>c>>d;
       auto getDivs=[](int n){
        vector<ll> divs;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divs.push_back(i);
                if(i*i!=n)divs.push_back(n/i);
            }
        }
        return divs;
       };
       auto diva=getDivs(a),divb=getDivs(b);
       ll ansx=-1,ansy=-1;
       for(auto da:diva){
        for(auto db:divb){
            // reorder factors s.t ab=AB and A|x, B|y
            ll A=da*db,B=(a*b)/A;
            ll curx=(a/A+1)*A; // smallest multiple of A in (a,c]
            ll cury=(b/B+1)*B; // smallest multiple of B in (b,d]
            if(curx<=c && cury<=d){
                ansx=curx;
                ansy=cury;
                break;
            }
        }
       }
       cout<<ansx<<' '<<ansy<<'\n';

    }
    return 0;
}