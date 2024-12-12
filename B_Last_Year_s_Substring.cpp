#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        bool isPos=0;
        // traverse all substrings of length (n-4)
        for(int i=0;i<=4;i++){
            string tmp=s;
            tmp.erase(i,n-4);
            if(tmp=="2020"){
                isPos=1;
                break;
            }            
        }
        if(isPos) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}