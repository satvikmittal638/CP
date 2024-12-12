#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> quality(n+1);
    while(n--){
        int a,b;cin>>a>>b;
        quality[a]=b;
    }
    // check presence of inversion
    if(is_sorted(quality.begin()+1,quality.end())){
        cout<<"Poor Alex";
    }else{
        cout<<"Happy Alex";
    }
    return 0;
}