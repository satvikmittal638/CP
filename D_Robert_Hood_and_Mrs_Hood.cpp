#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// TODO: some issue in TC-6
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,d,k;cin>>n>>d>>k;
       vector<int> cnt(n+2,0);
       while(k--){
        int l,r;cin>>l>>r;
        // range update
        cnt[l]++;
        cnt[r+1]--;
       }
       // accumulate all the prefixes
       for(int i=1;i<=n+1;i++){
        cnt[i]+=cnt[i-1];
       }
       // Aim: get maxm and minm value along with the first position of their occurence of the current window
       set<pair<int,int>> st;//{jobs,day}
       for(int r=1;r<=d;r++){
        st.insert({cnt[r],r});
       }
       int mxJobs,mnJobs,mxStart=1,mnStart=1;
       mnJobs=mxJobs=st.rbegin()->first;
       for(int l=1,r=d+1;r<=n;r++){
        // remove leading element from the window
        st.erase({cnt[l],l});
        l++;
        // add trailing element to the window
        st.insert({cnt[r],r});
        
        int curMxJobs=st.rbegin()->first;
        if(mxJobs<curMxJobs){
            mxJobs=curMxJobs;
            mxStart=l;
        }        
        if(mnJobs>curMxJobs){
            mnJobs=curMxJobs;
            mnStart=l;
        }
       }
       cout<<mxStart<<" "<<mnStart<<"\n";


    }
    return 0;
}
