#include<iostream>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--){
        string s,t;
        cin>>s>>t;
        // process the longest common substring(must start from beginning of both strings)
        int i=0,time=0;
        for(;i<s.length() && i<t.length() && s[i]==t[i];i++);
        if(i>0) time+=i+1; // write i-length string once and then copy it to another screen(if common substr exists)
        time+=s.length()+t.length()-2*i;
        cout<<time<<endl;
    }
    return 0;
}