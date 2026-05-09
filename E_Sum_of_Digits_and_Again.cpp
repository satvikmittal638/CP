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
       string s;cin>>s;
       vector<int> cnt(10,0);
       for(auto c:s) cnt[c-'0']++;
       // brute over S(x) from 0 to 9|s|
       for(int sum=0;sum<=9*s.size();sum++){
        // build the whole suffix starting from S(x)
        string suf,cur;
        vector<int> curcnt(10,0);
        suf=cur=to_string(sum);// start with S(x) appended
        for(auto c:cur) curcnt[c-'0']++;// update curcnt
        while(cur.length()>1){
            int cursum=0;
            for(auto c:cur) cursum+=c-'0';
            // find sum of digits and update the count
            cur=to_string(cursum);
            suf+=cur;// append this

            // update curcnt
            for(auto c:cur) curcnt[c-'0']++;
            
        }
        // validate this suffix
        int cursum=0;
        // compute S(x) from the x formed from remaining digits
        for(int i=0;i<10;i++){
            if(cnt[i]<curcnt[i]){
                cursum=-1;
                break;
            }
            cursum+=(cnt[i]-curcnt[i])*i;
        }
        // print the valid solution
        if(cursum==sum){
            // print x
            for(int i=9;i>=0;i--){
                for(int j=0;j<cnt[i]-curcnt[i];j++){
                    cout<<i;
                }
            }
            cout<<suf<<'\n';
            break;
        }
       }
       // edge case
       if(s.length()==1) cout<<s<<'\n';
    }
    return 0;
}