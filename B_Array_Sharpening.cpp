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
       vector<int> a(n);for(auto &i:a) cin>>i;
       int prefEnd=-1,sufEnd=n;
       // find longest prefix which can be made
       // increasing like 0,1,...k
       for(int i=0;i<n;i++){
        if(a[i]<i) break;
        prefEnd=i;
       }
        // find longest prefix which can be made
       // decreasing like k,k-1,..0
       // or make increasing in reverse
       for(int i=n-1;i>=0;i--){
        if(a[i]<(n-1)-i) break;
        sufEnd=i;
       }
       // check if the prefix and suffix have a non empty intersection to make whole array pointed
       cout<<(prefEnd>=sufEnd?"Yes":"No")<<"\n"; 


    }
    return 0;
}