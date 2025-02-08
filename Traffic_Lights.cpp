#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()



int main()
{
fastio;
    int x,n;cin>>x>>n;
    pair<int,int> mx1(0,x), mx2(0,x),mx3(0,x);
    for(int i=0;i<n;i++){
        int p;cin>>p;
        if(mx1.first<p && p<mx1.second){
            int seg1=p-mx1.first, seg2=mx1.second-p;
            if(seg1>seg2 && seg1>(mx2.second-mx2.first)){
                mx2=mx1;
                mx1.second=p;
            }
            else if(seg2>seg1 && seg2>(mx2.second-mx2.first)){
                mx2=mx1;
                mx1.first=p;
            }
            else{
                mx1=mx2;
            }

        }
    }

    return 0;
}