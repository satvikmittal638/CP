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
       // find length of longest path as well as the starting point for it
       vector<int> len(n+1,0);
       for(int i=1;i<=n;i++){
        cout<<"? "<<i<<" "<<n<<" ";
        for(int j=1;j<=n;j++) cout<<j<<" ";
        cout<<endl;
        cin>>len[i];
       }
       int l=*max_element(all(len));
       vector<int> ans;
       ans.push_back(max_element(all(len))-len.begin());
       l--;
       while(l){
           int x;
           for(int i=1;i<=n;i++){
            if(len[i]==l){
                cout<<"? "<<ans.back()<<" 2 "<<ans.back()<<" "<<i<<endl;
                cin>>x;
                // x and i are connected
                if(x==2){
                    ans.push_back(i);
                    break;
                }
            }
           }
           l--;
       }
       cout<<"! "<<ans.size()<<" ";
       for(auto e:ans) cout<<e<<" ";
       cout<<endl;

    }
    return 0;
}