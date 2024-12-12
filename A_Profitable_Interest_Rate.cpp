#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a<b){
        long long cost=(2*a-b);
        if(cost>0) cout<<cost;
        else cout<<0;
        }
        else
        cout<<a;
        cout<<"\n";
    }
    return 0;
}