#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string s,t;cin>>s>>t;
    if(t.size()==1 || s.size()==1){
        cout<<-1;
        return 0;
    }

    vector<int> pos_t_end(26,-1);
    // prevent the use of last character of T
    for(int i=t.size()-2;i>=0;i--){
        int pos=pos_t_end[t[i]-'a'];
        if(pos==-1){
            pos_t_end[t[i]-'a']=i;
        }
    }
    int len=INT_MAX,p_end=-1,s_end=-1;
    // prevent the use of 1st char of s
    for(int i=1;i<s.size();i++){
        int pos=pos_t_end[s[i]-'a'];
        if(pos!=-1 && ((i+t.length()-pos)<=len)){
            p_end=i;
            s_end=pos;
            len=i+t.length()-pos;
        }
    }
    if(p_end==-1){
        cout<<-1;
    }else{
        // cout<<p_end<<" "<<s_end<<" "<<len<<"\n";
        // cout<<s.substr(0,p_end)<<" "<<t.substr(s_end);
        string ans=s.substr(0,p_end)+t.substr(s_end);
        cout<<ans;
    }

    return 0;
}