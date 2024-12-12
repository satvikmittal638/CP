#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int k=1;
    long long tmp=n;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        if(tmp-x<=0){
            tmp+=n-k;
            k++;
        }
        tmp-=x;
        // cout<<tmp<<" ";
    }
    while(n-k){
        tmp+=n-k;
        k++;
    }
    // tmp+=(n-k)*(n-k-1)/2;
    cout<<tmp;
    return 0;
}