#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<pair<int,int> > a(n);
    for(int i=0;i<n;i++) {
        int val;
        cin>>val;
        a[i]=make_pair(i+1,val);// store 1 based indexing
    }
    for(int i=0;i<n-3;i++){
        for(int j=1;j<n-2;j++){
            int k=2,l=n-1;
            while(k<l){
                if(a[k].first+a[l].first>(x-a[i].first-a[j].first)) l--;
                else if(a[k].first+a[l].first<(x-a[i].first-a[j].first)) k++;
                else {
                    cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<" "<<a[l].second;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}