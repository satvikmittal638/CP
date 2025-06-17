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
       string t;cin>>t;
       int n;cin>>n;
       vector<string> s(n);for(auto &i:s) cin>>i;
       int c_r=-1;
       int st=0;
       vector<int> pos,str;
       pos.push_back(1);
       // handle 1st opn
       int str_pos;
       for(int i=0;i<n;i++){
            int len=s[i].length();
            // ending index out of bounds, so skip
            if(st+len-1>=t.size()) continue;
            string sub_t=t.substr(st,len);
            if(s[i]==sub_t){
                if(st+len-1>c_r){
                    c_r=st+len-1;
                    str_pos=i+1;
                }
            }
        }
        str.push_back(str_pos);
        // no valid coloring
        if(c_r==-1){
            cout<<"-1\n";
            continue;
        }
        bool ok=1;
        // handle subsequent opn
       while(c_r!=t.size()-1){
        int old_c_r=c_r,str_pos;
        while(st<=old_c_r){
            for(int i=0;i<n;i++){
                int len=s[i].length();
                // ending index out of bounds, so skip
                if(st+len-1>=t.size()) continue;

                string sub_t=t.substr(st,len);
                if(st+len-1>c_r){
                    c_r=st+len-1;
                    str_pos=i+1;
                }
            }
            st++;
        }
        // no update->no valid coloring
        if(old_c_r==c_r){
            ok=0;
            break;
        }
        pos.push_back(st);
        str.push_back(str_pos);
        st=0;// reset for next pass
       }
       if(ok){
            cout<<str.size()<<"\n";
            for(int i=0;i<str.size();i++){
                cout<<str[i]<<" "<<pos[i]<<"\n"; 
            }
       }
       else{
        cout<<"-1\n";
       }
    }
    return 0;
}