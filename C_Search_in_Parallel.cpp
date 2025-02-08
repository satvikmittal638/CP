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
       int n,s1,s2;cin>>n>>s1>>s2;
       vector<pair<int,int>> r(n);
       for(int i=0;i<n;i++){
        cin>>r[i].first;
        r[i].second=i+1;
       }
       sort(rall(r));
       vector<int> a,b;
       int top=0;
       while(top<n){
        // its better to put in b since it will have faster retrieval
        if((a.size()+1)*s1>=(b.size()+1)*s2){
            b.push_back(r[top].second);
        }
        else{
            a.push_back(r[top].second);
        }
        top++;
       }
       cout<<a.size()<<" ";
       for(auto e:a)cout<<e<<" ";
       cout<<"\n";
       cout<<b.size()<<" ";
       for(auto e:b)cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}