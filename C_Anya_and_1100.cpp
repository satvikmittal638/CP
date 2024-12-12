#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
        string s;cin>>s;
        int n=s.size();
        set<int> a;
        // lambda function
        auto Update=[&](int i){
            if(0<=i && i<=n-4){
                if(s.substr(i,4)=="1100"){
                    a.insert(i);
                }else{
                    a.erase(i);
                }
            }
        };
        for(int i=0;i<=n-4;i++){
            Update(i);
        }
        int q;cin>>q;
        while(q--){
            int i,v;cin>>i>>v;
            i--; // convert to 1 based indexing
            s[i]='0'+v;
            // only a small ngbd is affected
            for(int j=i-3;j<=i;j++){
                Update(j);
            }
            cout<<(a.empty()?"NO":"YES")<<"\n";
        }
    }
    return 0;
}