#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    int X=0;
    for(auto e:v){
        X^=e;
    }
    for(auto e:v){
        cout<<(X^e)<<" ";
    }
    return 0;
}