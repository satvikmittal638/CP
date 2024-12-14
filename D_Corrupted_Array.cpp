#include<bits/stdc++.h>
using namespace std;

void print(vector<long long> v){
    for(auto e:v) if(e!=-1) cout<<e<<" ";
    cout<<"\n";
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<long long> b(n+2);
       long long sum=0;
       int mx1=-1,mx2=-1;
       for(int i=0;i<n+2;i++){
        cin>>b[i];
        sum+=b[i];
        if(mx1==-1 || b[mx1]<b[i]){
            mx2=mx1;
            mx1=i;
        }
        else if(mx2==-1 || b[mx2]<b[i]){
            mx2=i;
        }
       }
     long long suma,x;
     vector<long long> b2(b);
    
    }
    return 0;
}