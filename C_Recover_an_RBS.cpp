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
        int n;
       string s;cin>>s;n=s.length();
       int cntOpen=count(all(s),'('),cntClosed=count(all(s),')');
       int openNeeded=n/2-cntOpen,closedNeeded=n/2-cntClosed;
       // make an RBS
       string rbs1=s;
       int firstClosed=-1;
       for(int i=0,i_open=0,i_closed=0;i<n;i++){
        if(rbs1[i]=='?'){
            if(i_open<openNeeded) {
                rbs1[i]='(';
                i_open++;
            }
            else if(i_closed<closedNeeded) {
                rbs1[i]=')';
                if(i_closed==0) firstClosed=i;
                i_closed++;
            }
        }
       }
       int sum=0;
       vector<int> cnt(n,0);// cnt[i] is no. of elts in [0,i] s.t. a[j]>=2 for all 0<=j<=i
       sum=1;
       for(int i=1;i<n;i++){
        sum+=(rbs1[i]=='(')-(rbs1[i]==')');
        cnt[i]+=cnt[i-1]+(sum>=2);
       }
       bool found=0;
       for(int i=0;i<firstClosed;i++){
        int cur_cnt=cnt[firstClosed-1]-(i>0?cnt[i-1]:0);
        if(s[i]=='?' && cur_cnt==(firstClosed-i)){
            found=1;
            break;
        }
       }
       cout<<(found?"NO":"YES")<<"\n";

       
    }
    return 0;
}