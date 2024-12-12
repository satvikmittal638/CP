#include<bits/stdc++.h>
using namespace std;

void solve(string s1,string s2,int i,int& cnt){
    // a permutation is made
    if(i==s2.length()){
        int sum1=0,sum2=0;
        for(int j=0;j<s1.length();j++){
            sum1+=(s1[j]=='+')-(s1[j]=='-');
            sum2+=(s2[j]=='+')-(s2[j]=='-');
        }
        cnt+=(sum1==sum2);
    }else{
        if(s2[i]=='?'){
            // explore both the possibilities
            s2[i]='+';
            solve(s1,s2,i+1,cnt);
            s2[i]='-';
            solve(s1,s2,i+1,cnt);
        }else{
            solve(s1,s2,i+1,cnt);
        }
    }
    
}

int main()
{
    string s1,s2;cin>>s1>>s2;
    int cnt_perm=0;
    double p=1;
    for(int i=0;i<s2.length();i++) {
        if(s2[i]=='?') p*=0.5;
    }
    solve(s1,s2,0,cnt_perm);
    // cout<<cnt_perm;
    p=p*cnt_perm;
    printf("%.9f",p);
    return 0;
}