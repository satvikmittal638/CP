#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> s(n),ctr(101,0),idx(101);
    for(int i=0;i<n;i++) {
        cin>>s[i];
        ctr[s[i]]++;
        idx[s[i]]=i;
    }
    vector<int> nice;
    int notNice=-1;
    for(int i=1;i<=100;i++){
        if(ctr[i]==1) nice.push_back(i);
        else if(ctr[i]>2) notNice=i;
    }
    if(nice.size()%2!=0 && notNice==-1){
        cout<<"NO\n";
        return 0;
    }

    vector<char> ans(n,'B');
    for(int i=0;i<nice.size()/2;i++){
        ans[idx[nice[i]]]='A';
    }
    if(nice.size()%2!=0){
        ans[idx[notNice]]='A';
    }
    cout<<"YES\n";
    for(auto e:ans) cout<<e;
    cout<<"\n";

    return 0;
}