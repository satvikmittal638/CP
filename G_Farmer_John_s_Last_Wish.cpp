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
       // normalize
       vector<int> div(n+1,0); // div[d] is no. of elts out of those seen so far which share a common divisor d>1
       for(int i=0;i<n;i++){
        // factorise a[i]
        div[a[i]]++; // the number itself
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j==0){
                div[j]++;
                if(j!=a[i]/j){
                    div[a[i]/j]++; 
                }
            }
        }
        // How to take fast maxm over div
    }
       cout<<'\n';
    }
    return 0;
}