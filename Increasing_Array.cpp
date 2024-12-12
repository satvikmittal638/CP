#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int maxSoFar=a[0],moves=0;
    for(int i=1;i<n;i++){
        if(a[i]<maxSoFar){
            moves+=maxSoFar-a[i];
        }else{
            maxSoFar=a[i];
        }
    }
    cout<<moves;

    return 0;
}