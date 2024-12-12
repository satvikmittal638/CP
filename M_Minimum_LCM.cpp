#include<iostream>
using namespace std;

// gets max factor less than n
long long maxFactor(long long n){
    long long maxFactor=1;
    // skip checking from d=1 to exclude n as a factor 
    for(int d=2;d*d<=n;d++){
        if(n%d==0){
            long long div2=n/d,m1=d>div2?d:div2;
            maxFactor=maxFactor>m1?maxFactor:m1;
        }
    }
    return maxFactor;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a,b;
        if(!(n&1LL)){
            a=b=n/2;
        }else{
          a=maxFactor(n);b=n-a;  
        }
        cout<<a<<" "<<b<<endl;    
    }
    return 0;
}