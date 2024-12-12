#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,c,d;
        cin>>n>>c>>d;
        int b[n*n];
        for(int i=0;i<n*n;i++){
            cin>>b[i];
        }
        sort(b,b+n*n);
        int x[n*n];
        int k=0;
        int a=b[k];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                x[k++]=a+(i-1)*c + (j-1)*d;
            }
        }
        sort(x,x+n*n);
        bool isPos=1;
        for(int i=0;i<n*n;i++){
            if(b[i]!=x[i]){
                isPos=0;
                break;
            }
        }
        if(isPos){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}