#include<bits/stdc++.h>
using namespace std;

bool comp(string s1,string s2){
    int i,j;
    for(i=0;i<s1.length();i++){
        if(!isalpha(s1[i])) continue;
        if(isupper(s1[i])) break;
    }
    for(j=0;j<s2.length();j++){
        if(!isalpha(s2[j])) continue;
        if(isupper(s2[j])) break;
    }
    return s1.substr(i)<s2.substr(j);
}

int main()
{
    int n;cin>>n;
    cin.ignore();
    vector<string> names(n);for(auto &i:names) getline(cin,i);
    sort(names.begin(),names.end(),comp);
    for(auto name:names) cout<<name<<"\n";
    return 0;
}