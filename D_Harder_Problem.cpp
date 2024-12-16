#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       // b will be made of distinct numbers only
       vector<int> a(n),b(n,-1);
       vector<bool> wasUsed(n,0);
       for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--; // make 0-indexed
        // fil the 1st occurence of each Mode value
        if(!wasUsed[a[i]]){
            b[i]=a[i];
            wasUsed[a[i]]=1;
        }
       }
       int ptr=0;
        for(int i=0;i<n;i++){
            // fill the unfilled position with the first number which is not used till
            // this moment of building b
            if(b[i]==-1){
                while(wasUsed[ptr]){
                    ptr++;
                }
                b[i]=ptr;
                wasUsed[ptr]=1;
            }
        }
        for(auto e:b) cout<<e+1<<" ";
        cout<<"\n";
    }
    return 0;
}