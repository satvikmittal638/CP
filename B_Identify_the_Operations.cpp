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
const ll MOD=998244353;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       // simulate operations via a doubly ll
       vector<int> a(n),inva(n+1,-1),next(n,-1),prev(n,-1);
       for(int i=0;i<n;i++){
        cin>>a[i];
        inva[a[i]]=i;
       }
       for(int i=0;i<n;i++){
        if(i>0) prev[i]=i-1;
        if(i<n-1) next[i]=i+1;
       }
       vector<int> b(k);
       vector<bool> isTrash(n,1);// values at which indices of a don't occur in b
       for(auto &i:b) {
        cin>>i;
        isTrash[inva[i]]=0;
       }
       ll ans=1ll;
       for(auto e:b){
        int i=inva[e];
        // trash on both sides
        if(prev[i]!=-1 && isTrash[prev[i]] && next[i]!=-1 && isTrash[next[i]]){
            ans=(ans*2)%MOD;
            // can delete either of prev[i] or next[i] aribitrarily
            /*
            First, we can notice, that the actual values are not very important. Let's use | to denote something that we will use later, and . to denote something removable. You should note, that the order of the | chosen is still important, though not represented here.

            So our array looks like ..|...|...|...|...|....

            Now we can see that one of the | will be next. After we add it to the array b, it is useless, and removable like a ., because all values in "b" are distinct. So using either |. and .| in .|. yield a ... So the next state is the same regardless of whether we choose left or right.
            */
            // lets delete prev[i]
            int before=prev[prev[i]];
            if(before!=-1){
                next[before]=i;
                prev[i]=before;
            }

        }
        // trash only before, no trash after
        else if(prev[i]!=-1 && isTrash[prev[i]]){
            // delete prev[i]
            int before=prev[prev[i]];
            if(before!=-1){
                next[before]=i;
                prev[i]=before;
            }

        }
        // trash only after,no trash before
        else if(next[i]!=-1 && isTrash[next[i]]){
            // delete next[i]
            int after=next[next[i]];
            if(after!=-1){
                next[i]=after;
                prev[after]=i;
            }
        }
        // no trash on either side
        else{
            ans=0;
            break;
        }
        isTrash[i]=1; // now this elt can be deleted in future
       }
       cout<<ans<<'\n';


    }
    return 0;
}