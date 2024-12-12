#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> seq(n);
       
       if(n%2==0){
        int fill=1;
        for(int i=0;i<n-1;i+=2){
            seq[i]=fill;
            seq[i+1]=fill;
            fill++;
        }
       }else{
        int fill=1;
        for(int i=0;i<n-4;i++){
            if(seq[i]==0){
                seq[i]=fill;
                seq[i+4]=fill;  
            fill++;
            }

        }
       }
       if((n%2==0 && n>=4) || (n%2!=0 && n>=5))
        for(int s:seq) cout<<s<<" ";
        else cout<<-1;
        cout<<"\n";
    }
    return 0;
}