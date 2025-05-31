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
       vector<int> dig;
       for(int i=0;i<n;i++){
        char c;cin>>c;
        int d=c-'0';
        dig.push_back(d);
       }
       vector<int> ans(n);
       auto isColorFine=[&](){
        vector<int> bag1,bag2;
        for(int i=0;i<n;i++){
            if(ans[i]==1) bag1.push_back(dig[i]);
            else bag2.push_back(dig[i]);
        }
        bag1.insert(bag1.end(),all(bag2));
        return is_sorted(all(bag1));
       };
       bool ok=0;
       for(int x=0;x<10;x++){
        // find position of 1st element>x
        int pos;
        for(pos=0;pos<n;pos++){
            if(dig[pos]>x) break;
        }
        // perform coloring
        for(int i=0;i<n;i++){
            if(dig[i]>x) ans[i]=2;
            else if(dig[i]<x)  ans[i]=1;
            else{
                if(i>pos) ans[i]=1;
                else ans[i]=2;
            }
        }
        // found a valid coloring
        if(isColorFine()){
            ok=1;
            break;
        }
       }
       if(ok){
        for(auto e:ans) cout<<e;
        cout<<"\n";
       }
       else{
        cout<<"-\n";
       }
    }
    return 0;
}