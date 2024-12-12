#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

long long numOfDiv(long long n){
    long long count=0;
    for(long long d=1;d*d<=n;d++){
        if(n%d==0){
            long long div2=n/d;
            count+=1+(d!=div2); // remove any duplicate divisor count
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    for(auto &i:v) cin>>i;
    long long hcf=v[0];
    for(int i=1;i<n;i++){
        hcf=gcd(hcf,v[i]); // works in C++17 or greater
    }
    cout<<numOfDiv(hcf);

    return 0;
}