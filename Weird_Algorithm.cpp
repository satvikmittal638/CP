#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        // even
        if(!(n&1)){
            n/=2;
        }else{
            n=n*3+1;
        }
    }
    cout<<"1";
    return 0;
}