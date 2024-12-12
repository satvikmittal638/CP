#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int N,X,S;
        cin>>N>>X>>S;
        while(S--){
            int A,B;
            cin>>A>>B;
            if(X==A){
                X=B;
            }else if(X==B){
                X=A;
            }
        }
        cout<<X<<endl;
    }
    return 0;
}