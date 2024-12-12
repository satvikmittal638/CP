#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        int x=0,y=a-x,hasSol=0;
        while(y>=x){
            // cout<<x<<" "<<y<<endl;
            if ((x^y)==b)
            {
                hasSol=1;
                break;
            }
            x++;
            y=a-x;
        }
        if(hasSol){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }
    return 0;
}