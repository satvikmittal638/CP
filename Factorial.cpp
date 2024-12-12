#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,i=5,count=0;
        cin>>n;
        while((n/i)>0){
            count+=n/i;
            i*=5;
        }
        cout<<count<<endl;;
    }
    return 0;
}