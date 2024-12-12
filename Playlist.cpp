#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long i=0,j=1,mxLen=0;
    while(i<=j && j<n){
        if(v[j]!=v[i]){
            j++;
        }
        else{
            i++;
        }
        mxLen=max(mxLen,j-i);
    }
    cout<<mxLen;
    return 0;
}