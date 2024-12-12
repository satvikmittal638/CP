#include<bits/stdc++.h>
using namespace std;
int main()
{
    // TODO-not understood clearly
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> e(n);for(auto &i:e) cin>>i;
       sort(e.begin(),e.end());
       int cnt_grps=0;
       for(int i=0;i<n;i++){
        int cur_sz=1;// include ith person in the grp
        while(i<n-1 && cur_sz<e[i]){
            cur_sz++;
            i++;
        }
        cnt_grps+=(cur_sz>=e[i]);
       }
       cout<<cnt_grps<<"\n";
    }
    return 0;
}