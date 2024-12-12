#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       string a,b,s;cin>>a>>s;
        int i=s.length()-1,j=a.length()-1;
        bool ok=1;
        // construct b in reverse
        while(j>=0){
            // follows normal addition
            if(s[i]-'0'>=a[j]-'0'){
                b.push_back('0'+s[i]-a[j]);
                i--;j--;
            }
            // follows modified addition
            else{
                // use last 2 digits of s
                int num=(s[i-1]-'0')*10 + (s[i]-'0');
                int diff=num-(a[j]-'0');
                i-=2;j--;
                // check for valid digit
                if(0<=diff && diff<=9){
                    b.push_back('0'+diff);
                }else{
                    ok=0;break;
                }
            }
        }

        // add remaining digits
        while(i>=0){
            b.push_back(s[i]);
            i--;
        }

        // cout<<i<<" "<<j; 
        if(ok){
            reverse(b.begin(),b.end());
            // skip printing leading 0s
            for(i=0;i<b.length() && b[i]=='0';i++);
            for(;i<b.length();i++) cout<<b[i];
        } else cout<<-1;
        cout<<"\n";

    }
    return 0;
}