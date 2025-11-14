#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
string op;cin>>op;
    int tt;cin>>tt;
    while(tt--){
       if(op=="first"){
        int n;cin>>n;
        vector<int> p(n);for(auto &i:p) cin>>i;
        // 1-> (1,n)
        // 0->(n,1)
        bool ans;
        for(int i=0;i<n;i++){
            // 1 is found first
            if(p[i]==1){
                ans=1;
                break;
            }
            else if(p[i]==n){
                ans=0;
                break;
            }
        }
        cout<<ans<<endl;

       }
       else{
        int n,x;cin>>n>>x;
        int p_end=n,s_st=1;
        // B.S for shortest prefix with range=n-1
        int q;
        int hi=n,lo=1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            cout<<"? 1 "<<mid<<endl;
            cin>>q;
            // try decreasing the size of the prefix
            if(q==n-1){
                p_end=mid;
                hi=mid-1;
            }
            // increase prefix size
            else{
                lo=mid+1;
            }
        }
        // B.S for shortest prefix with range=n-1
        hi=n,lo=1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            cout<<"? "<<mid<<" "<<n<<endl;
            cout.flush();
            cin>>q;
            // try decreasing the size of the suffix
            if(q==n-1){
                s_st=mid;
                lo=mid+1;
            }
            // increase suffix size
            else{
                hi=mid-1;
            }
        }
        int i1=min(p_end,s_st),in=max(p_end,s_st);// assume (1,n) initially
        // for (n,1)
        if(!x){
            swap(i1,in);
        }
        cout<<"! "<<in<<endl;
        }
    }
    return 0;
}