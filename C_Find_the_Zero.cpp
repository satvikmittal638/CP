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
       bool found=0;
       for(int i=1;i<=2*n-2;i+=2){
        int res=-1;
        cout<<"? "<<i<<" "<<i+1<<endl;
        cin>>res;
        if(res==1) {
            found=1;
            cout<<"! "<<i<<endl;
            break;
        }
       }
       if(!found){
        int res1,res2;
        cout<<"? 1 3"<<endl;cin>>res1;
        cout<<"? 1 4"<<endl;cin>>res2;
        
        if(res1==1 || res2==1) cout<<"! 1";
        else cout<<"! 2";
        cout<<endl;
       }
    }
    return 0;
}