#include<bits/stdc++.h>
using namespace std;
int main()
{
    const long long MOD=1e9 +7;
    long long n;cin>>n;
    vector<long long> p(n);for(auto &i:p) cin>>i;
    long long cnt=0,curRoom=0;
    vector<bool> parity(n,0);
    // reach room n+1
    while(curRoom!=n){
        parity[curRoom]=!parity[curRoom];
        if(parity[curRoom]==0){
            curRoom++;// use 1st portal to move forward
            cnt++;
        }else{
            // convert to 0 based indexing
            curRoom=p[curRoom]-1;//use 2nd portal to move back
            cnt++;
        }
        if(cnt>=MOD) cnt-=MOD;
    }
    cout<<cnt;
    return 0;
}