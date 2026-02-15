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
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       // empty final array
       if(k<=1){
        cout<<"YES\n";
        continue;
       }
       vector<int> tmp(a),b;sort(all(tmp));
       int edge=tmp[k-2],cnt=0,cntLess=0;// maintain count of elt=edge and <edge
       for(int i=0;i<n;i++){
        if(a[i]<=edge) b.push_back(a[i]);
        cnt+=a[i]==edge;
        cntLess+=a[i]<edge;
       }
       // now from b, u can delete atmost cnt-(k-1-cntLess) elts=edge
       int buffer=cnt-(k-1-cntLess);
       int i=0,j=b.size()-1;
       bool ok=1;
       while(i<j && ok){
        if(b[i]==b[j]){
            i++;j--;
        }
        else{
            // delete this
            if(b[i]==edge){
                i++;
                buffer--;
            }
            else if(b[j]==edge){
                j--;
                buffer--;
            }
            // some other non-deletable elts don't match, can't do anything about them
            else{
                ok=0;
                break;
            }
        }
       }
       ok&=buffer>=0;
       cout<<(ok?"YES":"NO")<<'\n';


    }
    return 0;
}