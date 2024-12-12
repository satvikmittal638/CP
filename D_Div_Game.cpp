#include<iostream>
#include<math.h>
#include<map>
#include<set>
using namespace std;


long long nearestTriangularNum(long long e){
    return (long long)floor((sqrt(8*e+1)-1)/2);
}

int main()
{
    long long n,maxOp=0;
    cin>>n;
    for(long long d=2;d*d<=n;d++){
        long long e=0;
        while(n%d==0){
            e++;
            n/=d;
        }
        maxOp+=nearestTriangularNum(e);
    }
    if(n>1){
        maxOp+=1; // root n was also a prime factor of n
    }

    cout<<maxOp;
    return 0;
}