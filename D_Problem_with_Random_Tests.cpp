#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// removes leading 0s
string normalize(const string &v){
    int cnt=0;
    while(cnt<v.size() && v[cnt]=='0') cnt++;
    if(cnt==v.size()) return "0"; // all 0s
    return v.substr(cnt,(int)v.size()-cnt);// n-1-cnt+1=n-cnt
}

// calculates bitwise or of 2 given strings
string operator |(const string &a,const string &b){
    int sz=max(a.size(),b.size());
    string ans(sz,'0');
    for(int i=0;i<a.size();i++) if(a[i]=='1') ans[i+(sz-a.size())]='1';
    for(int i=0;i<b.size();i++) if(b[i]=='1') ans[i+(sz-b.size())]='1';
    return normalize(ans);
}
// @return  true if a>b
bool better(const string &a,const string &b){
    if(a.size()!=b.size()) return a.size()>b.size();
    return a>b;
}

int main()
{
fastio;
    int n;cin>>n;
    string s;cin>>s;
    s=normalize(s);
    n=s.size();
    string ans=s;
    int pos1=s.find('0');
    if(pos1!=string::npos){
    int len=n-pos1; // length of substring needed
    int st=0;
    while(st+len-1<n && s[st]=='1'){
        string cur_ans=s|s.substr(st,len);
        if(better(cur_ans,ans)) ans=cur_ans;
        st++;
    }
    }
   
    cout<<ans;
    return 0;
}