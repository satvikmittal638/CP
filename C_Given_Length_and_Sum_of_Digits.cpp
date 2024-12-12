#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s;cin>>m>>s;
    if(s>9*m || (s==0 && m>1) || (m==0)){
        cout<<"-1 -1";
    }else{
        int cnt_9=s/9,otherDig=s%9,cnt_0=m-(cnt_9+(otherDig>0)); // use 0 otherwise if more digits reqd
        string large="";
        for(int i=1;i<=cnt_9;i++){
            large+="9";
        }
        if(otherDig>0) large+=to_string(otherDig);
        for(int i=1;i<=cnt_0;i++){
            large+="0";
        }

        string small=large;
        reverse(small.begin(),small.end());
        int i=0;
        //find first non-0 digit
        while(i<small.size() && small[i]=='0'){
            i++;
        }
        if(i<small.size()){
            small[i]--;
            small[0]+=1;
        }
        cout<<small<<" "<<large;
    }
    return 0;
}