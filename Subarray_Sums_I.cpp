#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(n);
    for(auto &i:a) cin>>i;
    int i=0,j=-1;
    long long sum=0,count=0;
    while(j<n){
        if(sum>x){
            sum-=a[i];
            i++;
        }
        else if(sum<x){
            j++;
            sum+=a[j];
        }
        else{
            sum-=a[i];
            i++;
            j++;
            sum+=a[j];
            count++;
        }
    }
    cout<<count;
    return 0;
}