#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<long long,long long> p1,pair<long long,long long> p2){
    return p1.second<p2.second; 
    // a movie that ends early allows us to watch another movie
}

int main()
{
    int n;
    cin>>n;
    vector<pair<long long,long long> > movies(n);
    for(auto &i:movies){
        cin>>i.first>>i.second; // starting,ending
    }
    sort(movies.begin(),movies.end(),comp);
    long long prev_e=movies[0].second,count=1; // will watch atleast 1 movie
    for(int i=1;i<n;i++){
        // this movie starts before the current movie has ended-> can't watch it
        if(movies[i].first<prev_e) continue;
        else{
            // can watch this movie also since it will start after the current movie has ended
            count++;
            prev_e=movies[i].second; // watch this movie also
        }
    }
    cout<<count;
    return 0;
}