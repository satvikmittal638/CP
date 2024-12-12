#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    cin.ignore(); // ignore newline character
    
    map<string,string> servers; // ip->name
    for(int i=0;i<n;i++){
        string name,ip;
        cin>>name>>ip;
        servers[ip]=name;
    }
    cin.ignore();// ignore newline character
    for(int i=0;i<m;i++){
        string s;
        getline(cin,s);
        // extract the ip
        int j;
        for(j=0; j<s.size() && s[j]!=' ';j++);
        
        string ip=s.substr(j+1,s.size()-j-2); // -2 to skip the semicolon
        // cout<<ip<<endl;
        s=s+" #"+servers[ip];
        cout<<s<<endl;
    }

    return 0;
}