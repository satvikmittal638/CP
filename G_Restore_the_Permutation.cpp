#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> p(n+1);

       set<int> avl;
       for(int i=1;i<=n;i++){
        avl.insert(i);
       }

       bool ok=1;
       for(int i=1;i<=n/2;i++){
        cin>>p[2*i];// put maxm later for lexicographical minimalness
        // if b has duplicate elts, no p possible
        if(!avl.count(p[2*i])) ok=0;
        else avl.erase(avl.find(p[2*i]));
       }
       if(!ok){
        cout<<"-1\n";
        continue;
       }
       // put largest available elt at the end
       for(int i=n/2;i>=1;i--){
        // find largest available <=p[2*i]
        auto it=avl.upper_bound(p[2*i]);
        // all available>p[2*i]
        if(it==avl.begin()){
            ok=0;
            break;
        }
        it--;
        p[2*i-1]=*it;
        avl.erase(it);
       }
       if(!ok){
        cout<<"-1\n";
        continue;
       }
       for(int i=1;i<=n;i++) cout<<p[i]<<' ';
       cout<<'\n';


    }
    return 0;
}