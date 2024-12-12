#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0,j=1,visible=n;
    while(i<j && j<v.size()){
        if(v[j]>v[i]){
            visible--;
            i++;
        }
        // v[i]==v[j]
        j++;
    }
    cout<<visible;
    return 0;
}