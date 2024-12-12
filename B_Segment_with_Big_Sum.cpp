#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    long long s;
    cin>>n>>s;
    vector<long long> a(n);
    for(auto &i:a) cin>>i;
    int i=0,j=-1,minWinSz=INT_MAX;
    long long sum=0;
    do{
        // try to decrease the window size
        if(sum>=s){
            minWinSz=min(minWinSz,j-i+1);
            sum-=a[i];
            i++;
        }
        else{
            j++;
            sum+=a[j];
        }
        
    }while(j<n && i<=j);
    minWinSz==INT_MAX?cout<<-1:cout<<minWinSz;
    return 0;
}