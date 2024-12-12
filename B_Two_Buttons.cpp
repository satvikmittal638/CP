#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    int steps=0;
    // reach to n from m rather than reaching m from n
    while(n<m){
        if(m%2==0){
            m/=2;
        }else{
            m--;
        }
    }
    cout<<steps;
    return 0;
}