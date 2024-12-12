#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<string> v(n);
        for(auto &i:v) cin>>i;
        string s="vika";
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(v[j][i]==s[k]){
                    k++;
                    break;
               } 
            }
        }
        if(k==4) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}