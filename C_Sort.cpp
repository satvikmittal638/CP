#include<bits/stdc++.h>
using namespace std;
int solve(string a,string b,int l,int r){
    l--;r--; // make 0 indexed
    sort(a.begin()+l,a.begin()+(r+1));
    sort(b.begin()+l,b.begin()+(r+1));
    int cnt=0;
    for(int i=l;i<=r;i++){
        cnt+=(a[i]!=b[i]);
    }
    return cnt;
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       string a,b;cin>>a>>b;
       while(q--){
        int l,r;cin>>l>>r;
        cout<<solve(a,b,l,r)<<"\n";
       }
    }
    return 0;
}