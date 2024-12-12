#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> odd,even;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a%2==0) even.emplace_back(i);
        else odd.emplace_back(i);
    }
    cout<<((odd.size()==1)?odd[0]:even[0]);
    return 0;
}