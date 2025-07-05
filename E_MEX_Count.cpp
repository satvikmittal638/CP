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
       int n;cin>>n;
       vector<int> cnt(n+1,0);
       for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
       }
       vector<int> elts;
       for(int i=0;i<=n;i++){
        if(cnt[i]>0) elts.push_back(i);
        else{
            break;
        }
       }
       if(elts.size()) elts.push_back(elts.back()+1);
       else{
        elts.push_back(0);
       }
       // now elts[i] gives no. of elts <i
       int mex=elts.back();
       vector<int> ansK(n+1,0);
       for(int z=0;z<=mex;z++){
        int lo=cnt[z],hi=n-elts[z];
        ansK[lo]++;
        if(hi<n) ansK[hi+1]--;
       }
       for(int i=1;i<=n;i++){
        ansK[i]+=ansK[i-1];
       }
       for(auto e:ansK) cout<<e<<" ";
       cout<<"\n";
       
    }
    return 0;
}