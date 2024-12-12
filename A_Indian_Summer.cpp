#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<pair<string,string> > s;
    for(int i=0;i<n;i++){
        string specie,color;
        cin>>specie>>color;
        s.insert(make_pair(specie,color));
    }
    cout<<s.size();

    return 0;
}