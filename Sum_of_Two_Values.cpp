#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// could have used multi-map
bool comp(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

void print(vector<int> v){
    for(auto e:v){
        cout<<e<<" ";
    }
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<pair<int,int> > v(n);
    // elt->index
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v[i]=make_pair(tmp,i);
    }
    sort(v.begin(),v.end(),comp);
    // print(keys);
    // cout<<endl;
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[i].first+v[j].first<x){
            i++;
        }else if(v[i].first+v[j].first>x){
            j--;
        }
        else{ // sum is found
            break;
        }
    }
    if(i!=j){
        cout<<v[i].second+1<<" "<<v[j].second+1; // print 1 based indexing
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}