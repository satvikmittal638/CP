#include<iostream>
#include<string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<(s[0]-'0')+(s[2]-'0')<<endl;
    }

    return 0;
}