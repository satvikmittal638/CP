#include<bits/stdc++.h>
using namespace std;



int main()
{
    const int MOD=1e9+7;
    string s;cin>>s;
    vector<int> fib(s.size()+1);
    fib[0]=fib[1]=1;
    for(int i=2;i<=s.size();i++){
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]%=MOD;
    }
    long long ans=1,cnt_u=0,cnt_n=0;
    for(int i=0;i<s.size();){
        while(i<s.size() && s[i]=='u'){
            cnt_u++;
            i++;
        }
        while(i<s.size() && s[i]=='n'){
            cnt_n++;
            i++;
        }
        if(s[i]=='w' || s[i]=='m') {ans=0;break;}
        // cout<<cnt_u<<" "<<cnt_n<<"\n";
        if(cnt_u>=1 || cnt_n>=1){
            ans*=fib[cnt_u];
            ans%=MOD;
            ans*=fib[cnt_n];
            ans%=MOD;
            cnt_u=0;cnt_n=0;// reset for next segment
        }else{
            i++;
        }
        // cout<<ans<<" ";
    }
    cout<<ans;
    return 0;
}