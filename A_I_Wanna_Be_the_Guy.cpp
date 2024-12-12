#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    int n,p,q,inp;
    cin>>n;
    cin>>p;
    for(int i=0;i<p;i++){
        cin>>inp;
        s.insert(inp);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>inp;
        s.insert(inp);
    }
    if(s.size()==n){
        cout<<"I become the guy.";
    }else{
        cout<<"Oh, my keyboard!";
    }


    return 0;
}