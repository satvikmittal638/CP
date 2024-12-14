#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;string s;cin>>n>>s;
       int i=0,j=n-1;
       // skip any palindromic segments of original string
       while(i<j && s[i]==s[j]){
        i++;j--;
       }
    //    cout<<i<<" "<<j<<"\n";
       if(s[i]!=s[j]){
            // we can only delete either of s[i] or s[j] now
            int cnti=0,cntj=0;
            char ci=s[i],cj=s[j];
            // case 1- choose s[i] to delete
            int nowi=i,nowj=j;
            while(nowi<nowj){
                if(s[nowi]==s[nowj]) {nowi++;nowj--;} // skip palindromic segment
                else if(s[nowi]==ci) {nowi++;cnti++;}
                else if(s[nowj]==ci) {nowj--;cnti++;}
                // no palindromic segment+can't perform any deletion
                else{
                    cnti=INT_MAX;break;
                }
                
            }

            // case 2- choose s[j] to delete
            nowi=i;nowj=j;
            while(nowi<nowj){
                if(s[nowi]==s[nowj]) {nowi++;nowj--;} // skip palindromic segment
                else if(s[nowi]==cj) {nowi++;cntj++;}
                else if(s[nowj]==cj) {nowj--;cntj++;}
                // no palindromic segment+can't perform any deletion
                else{
                    cntj=INT_MAX;break;
                }
                
            }
            
            int ans=min(cnti,cntj);
            if(ans==INT_MAX){
                cout<<-1<<"\n";
            }
            else{
                cout<<ans<<"\n";
            }
       }else{
        cout<<"0\n"; // already a palindrome
       }
    }
    return 0;
}