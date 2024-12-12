#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sz=n*(n-1)/2;
        int b[sz];
        for(int i=0;i<sz;i++){
            cin>>b[i];
        }
        sort(b,b+sz);
        int count=n;
        // print the minimum of the subarray of size n-k
        for(int i=0,k=1;i<sz;i+=n-k,k++){
            cout<<b[i]<<" ";
            count--;
        }
        while(count--){
            cout<<1000000000;
        }
        cout<<endl;
    }

    return 0;
}