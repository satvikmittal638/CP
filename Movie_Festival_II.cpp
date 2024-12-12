#include<iostream>
#include<vector>
using namespace std;

bool comp(pair<long long,long long> p1,pair<long long,long long> p2){
    return p1.second<p2.second; // end early
    // a movie that ends early allows us to watch another movie
}

int main()
{
    int n,k,tmp;
    cin>>n>>k;
    tmp=k;
    vector<pair<long long,long long> > movies(n),person(k);
    for(auto &i:movies){
        cin>>i.first>>i.second; // starting,ending
    }
    sort(movies.begin(),movies.end(),comp);
    long long count=1; // will watch atleast 1 movie
    person[0]=movies[0]; // first person starts watching
    
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            // ending time for person[j] is before starting of movie[i]
            // so this person can watch movie[i] as well
            if(
                person[j].second<=movies[i].first
                ){
                count++;
            }
            // person[j] can't watch movie[i]
            else{
                if(k>0 && j<k-1){
                    person[j+1]=movies[i];
                    tmp--; // person[j+1] can watch this movie
                    count++;
                }else{
                    // do nothing
                    // can't watch this movie
                }
            }
        }
    }
    cout<<count;
    return 0;
}