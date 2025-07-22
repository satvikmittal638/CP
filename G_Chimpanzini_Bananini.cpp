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
       int q;cin>>q;

       // perform 1st query
       ll s,k;cin>>s>>k;q--;

       deque<ll> dq;dq.push_back(k);
       ll sum=k,rizz=k,n=1,last;
       bool isRev=0;
       cout<<rizz<<"\n";
       while(q--){
        cin>>s;
        ll del=0ll;
           if(s==1){
            if(isRev) last=dq.front();
            else last=dq.back();

            del=sum-n*last;

            // update last to 2nd last i.e perform cyclic shift
            if(isRev) {
                dq.pop_front();dq.push_back(last);
            }
            else{
                dq.pop_back();dq.push_front(last);
            }
            
           }
           else if(s==2){
            del=(n+1)*sum-2*rizz;
            isRev=!isRev;
           }
           else{
            n++;
            cin>>k;
            sum+=k;
            del=n*k;
            if(isRev) dq.push_front(k);
            else dq.push_back(k);
           }
           rizz+=del;
           cout<<rizz<<"\n";
       }
    }
    return 0;
}