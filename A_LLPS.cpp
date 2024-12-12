#include<iostream>
#include<deque>
using namespace std;
int main()
{   
    int countMx=0;
    string s,t;
    cin>>s;
    char mx=0;
    for(int i=0;i<s.length();i++){
        if(mx<s[i]){
            mx=s[i];
            countMx=1; // reset Lexographically highest character count
        }else if(mx==s[i]){
            countMx++;
        }
    }
    while(countMx--){
        cout<<mx;
    }
    return 0;
}