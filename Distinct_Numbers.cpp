#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    cout<<s.size();
    return 0;
}