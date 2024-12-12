#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       string s;cin>>s;
       map<char,int> freq;
       for(auto c:s){
        freq[c]++;
       }
       int maxFreq=0;char cmax;
       int minFreq=INT_MAX;char cmin;
       // get maxm and minm frequency character
       for(auto p:freq){
        if(p.second>maxFreq){
            maxFreq=p.second;cmax=p.first;
        }
        if(p.second<minFreq){
            minFreq=p.second;cmin=p.first;
        }
       }
       if(cmin!=cmax){
        for(int i=0;i<s.length();i++){
            if(s[i]==cmin){
                s[i]=cmax;break;
            }
        }
       }else{
        for(int i=0;i<s.length();i++){
            // replace any other character since all charactaers have same freq
            if(s[i]!=cmin){
                s[i]=cmax;break;
            }
        }
       }
       cout<<s<<"\n";

    }
    return 0;
}