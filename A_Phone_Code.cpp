#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // traverse column wise
    int len=0,count=0;
    for(int j=0;j<a[0].length();j++){
        for(int i=0;i<n-1;i++){
            if(a[i][j]==a[i+1][j]){
                count++;
                // cout<<"count="<<count<<endl;
            }
        }
        if(count==n-1){
            count=0;
            len++;
        }else{
            break;
        }

    }
    cout<<len;
    

    return 0;
}