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
       int n,m;cin>>n>>m;
       string s;cin>>s;
       vector<vector<ll>> a(n,vector<ll>(m));
       vector<ll> rowSum(n,0ll),colSum(m,0ll),row_cnt(n,0ll);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            rowSum[i]+=a[i][j];
            colSum[j]+=a[i][j];
        }
       }
       int i=0,j=0;
        for(auto c:s){
            row_cnt[i]++;
            if(c=='D'){
                i++;
            }
            else if(c=='R'){
                j++;
            }
        }
        row_cnt[i]++;//last block
        int tgt=0;// sum for each row/col
        i=0,j=0;
        for(auto c:s){
            // cout<<i<<" "<<j<<"\n";
            // cout<<row_cnt[i]<<" ";
            if(row_cnt[i]==1){
                a[i][j]=tgt-rowSum[i];
                rowSum[i]=0;
                colSum[j]+=a[i][j]; // update col sum
            }
            else{
                a[i][j]=tgt-colSum[j];
                colSum[j]=0;
                rowSum[i]+=a[i][j]; // update row sum
            }
            row_cnt[i]--; // solved for 1 unknown

            if(c=='D'){
                i++;
            }
            else {
                j++;
            }
        }
        // last block
        if(row_cnt[i]==1){
            a[i][j]=tgt-rowSum[i];
            rowSum[i]=0;
            colSum[j]+=a[i][j]; // update col sum
            row_cnt[i]--; // solved for 1 unknown
        }
        else{
            a[i][j]=tgt-colSum[j];
            colSum[j]=0;
            rowSum[i]+=a[i][j]; // update row sum
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}