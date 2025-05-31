#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> x(n),y(n);
       for(ll i=0;i<n;i++)cin>>x[i]>>y[i];
       // edge case
       if(n==1) {
        cout<<"1\n";
        continue;
       }

       vector<ll> tmp_x(x),tmp_y(y);
       sort(all(tmp_x));
       sort(all(tmp_y));
       // Now try excluding each of the n polls
       ll mnX=tmp_x[0],mxX=tmp_x[n-1],mnY=tmp_y[0],mxY=tmp_y[n-1];
       ll ans=(mxX-mnX+1)*(mxY-mnY+1);
       for(ll i=0;i<n;i++){
        if(x[i]==tmp_x[0]){
            mnX=tmp_x[1];
        }
        else if(x[i]==tmp_x[n-1]){
            mxX=tmp_x[n-2];
        }

        if(y[i]==tmp_y[0]){
            mnY=tmp_y[1];// use 2nd minm
        }
        else if(x[i]==tmp_y[n-1]){
            mxY=tmp_y[n-2];
        }
        ll cur_ans=(mxX-mnX+1)*(mxY-mnY+1);
        // check if this poll is in the new rect/can be moved to this new rect
        // poll is inside the new rect
        if(mnX<=x[i] && x[i]<=mxX && mnY<=y[i] && y[i]<=mxY){
            // do nothing
        }else{
            // poll can be moved new rect(there's an empty space)
            if(cur_ans==n-1){
            // current rectangle is full, so we increase either of x length or y length depending on which one gives u a minm area
            cur_ans=min((mxX-mnX+2)*(mxY-mnY+1),(mxX-mnX+1)*(mxY-mnY+2));
            }
        }


        // update
        ans=min(ans,cur_ans);

        // roll back
        mnX=tmp_x[0];
        mxX=tmp_x[n-1];
        mnY=tmp_y[0];
        mxY=tmp_y[n-1];
       }
       cout<<ans<<"\n";
    }
    return 0;
}