#include<bits/stdc++.h>
using namespace std;

bool isIntersects(pair<int,int> I1,pair<int,int> I2){
    // sort in ascending
    if(I1.first>I2.first) swap(I1,I2);
    return I2.first<=I1.second;
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,x,m;cin>>n>>x>>m;
       pair<int,int> curI={x,x}; // boundary starts from a point
       while(m--){
        int l,r;cin>>l>>r;
        if(isIntersects(curI,{l,r})){
            curI.first=min(curI.first,l);
            curI.second=max(curI.second,r);
        }
       }
       
        cout<<(curI.second-curI.first+1)<<"\n";
       
    }
    return 0;
}