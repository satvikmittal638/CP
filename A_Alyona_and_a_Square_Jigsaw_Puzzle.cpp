#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       int cnt_total=0,cnt_happy=0;
       while(n--){
        int a;cin>>a;
        cnt_total+=a;
        int total_sqrt=sqrt(cnt_total);
        if(total_sqrt*total_sqrt==cnt_total && total_sqrt%2==1){
            cnt_happy++;
        }
       }
       cout<<cnt_happy<<"\n";
    }
    return 0;
}