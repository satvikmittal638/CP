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
    string s;cin>>s;
    vector<pair<int,int>> segs;
    int r=0;
    for(int i=0;i<n-1;i++){
        int start=i;
        while(s[i]==s[i+1])i++;
        if(start!=i) segs.push_back({start,i});
        r+=(i-start+1)/2;
    }
    auto getDiff=[](char c1,char c2){
        return 'R'^'G'^'B'^c1^c2;
    };
    for(auto &seg:segs){
        int start=seg.first, end=seg.second;
        char changeTo;
        if(start==0 && end<n-1){
            changeTo=getDiff(s[end+1],s[start]);
        }
        else if(start>0 && end==n-1){
            changeTo=getDiff(s[start-1],s[start]);
        }
        else if(start==0 && end==n-1){
            char c=s[start];
            if(c=='R') changeTo='G';
            else if(c=='G') changeTo='B';
            else if(c=='B') changeTo='R';
        }else{
            if(s[start-1]==s[end+1]) changeTo=getDiff(s[start-1],s[start]);
            else changeTo=s[start-1];
        }
        for(int i=start+1;i<=end;i+=2){
            s[i]=changeTo;
        }
    }
    cout<<r<<"\n"<<s;

    return 0;
}