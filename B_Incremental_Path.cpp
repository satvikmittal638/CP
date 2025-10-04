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
       int n,m;cin>>n>>m;
       string s;cin>>s;
       set<int> a;
       for(int i=0;i<m;i++){
        int x;cin>>x;
        a.insert(x);
       }
       int cur=2,prev=1;
       // finds white cell nearest to lo(ans may include lo also)
       auto findNearestWhite=[&](int lo){
          while(a.count(lo)) lo++;
           return lo;
        };
        // simulate for 1st person
        if(s[0]=='B' && a.count(cur)){
        // already black cell,find nearest white cell
        cur=findNearestWhite(cur);
        }
        a.insert(cur);
        // for(auto e:a) cout<<e<<' ';
        // cout<<'\n';
        // simulate for rest
       for(int i=1;i<n;i++){
        int mycur=prev;// start from (i-2)th command(the 2nd last command of the prvs person)
        mycur++;
        if(s[i-1]=='B' && a.count(mycur)){
            mycur=findNearestWhite(mycur);
        }
        prev=mycur;// cache the 2nd last move
        mycur++;
        if(s[i]=='B' && a.count(mycur)){
            mycur=findNearestWhite(mycur);
        }
        a.insert(mycur);
        cur=mycur;
        // for(auto e:a) cout<<e<<' ';
        // cout<<'\n';

       }
       cout<<a.size()<<'\n';
       for(auto e:a) cout<<e<<' ';
       cout<<'\n';

    }
    return 0;
}