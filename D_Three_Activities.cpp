#include<bits/stdc++.h>
using namespace std;

vector<int> best3(vector<int> v,int n){
    int mx1,mx2,mx3;
    mx1=mx2=mx3=-1;
    for(int i=0;i<n;i++){
        if(mx1==-1 || v[i]>v[mx1]){
            mx3=mx2;
            mx2=mx1;
            mx1=i;
        }
        else if(mx2==-1 || v[i]>v[mx2]){
            mx3=mx2;
            mx2=i;
        }
        else if(mx3==-1 || v[i]>v[mx3]){
            mx3=i;
        }
    }
    return {mx1,mx2,mx3};
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n),b(n),c(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       for(auto &i:c) cin>>i;
       vector<int> besta,bestb,bestc;
       besta=best3(a,n);
       bestb=best3(b,n);
       bestc=best3(c,n);
       int ans=INT_MIN;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                for(int z=0;z<3;z++){
                    if(besta[x]!=bestb[y] && bestb[y]!=bestc[z] && bestc[z]!=besta[x]){
                        ans=max(ans,a[besta[x]]+b[bestb[y]]+c[bestc[z]]);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}