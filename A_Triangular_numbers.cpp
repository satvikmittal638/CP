#include<iostream>
#include<math.h>
using namespace std;

int isSol(float s){
    return (s>0 && s==floor(s));
}

int main()
{
    int k;
    cin>>k;
    float D=sqrt(1+8*k);
    float s1=(D-1)/2, s2=(-D-1)/2;
    if(isSol(s1) || isSol(s2)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}