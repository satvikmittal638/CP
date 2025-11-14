#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string op;cin>>op;
    if(op=="first"){
        int n;cin>>n;
        string s;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            s.push_back('a'+(x-1));
        }
        cout<<s<<endl;
    }
    else{
        string s;cin>>s;
        cout<<s.size()<<' ';
        for(auto e:s) cout<<(e-'a')+1<<' ';
        cout<<endl;
    }
    return 0;
}