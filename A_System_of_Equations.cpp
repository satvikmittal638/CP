#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a=0,b=m-(a*a),numSol=0;
    // try values of a and find corr values of b
    // b decreases while a increases
    while(b>=0){
        if(a+(b*b)==n)
            numSol++;
        // cout<<a<<" "<<b<<endl;
        // update the variables
        a++;
        b=m-(a*a);
    }
    cout<<numSol;

    return 0;
}