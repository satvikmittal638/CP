#include<iostream>
#include<set>
using namespace std;

set<string> permute(string base,string s){
   static set<string> ps;
  
}

int main()
{
    string s;
    cin>>s;
    set<string> permutations=permute("",s);
    for(auto s:permutations){
        cout<<s<<endl;
    }
    return 0;
}