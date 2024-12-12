#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
bool comp(pair<bool,int> p1,pair<bool,int> p2){
    return p1.second<p2.second;
}

int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> c(n),length;
        vector<pair<bool,long long> > numLine; // 0 for start, 1 for end
        for(long long i=0;i<n;i++) {
            long long l;
            cin>>l;
            numLine.push_back(make_pair(0,l));
        }
        for(long long i=0;i<n;i++) {
            long long r;
            cin>>r;
            numLine.push_back(make_pair(1,r));
        }
        for(auto &i:c) cin>>i;
        sort(numLine.begin(),numLine.end(),comp);
        sort(c.begin(),c.end(),greater<int>());//give maximum c[i] to minimum length[i]
        
        // simulate opening and closing of by nearest free l and r
        stack<pair<bool,int> > st;
        for(long long i=0;i<2*n;i++){
            // close each interval with the nearest closing number(i.e match each l with nearest r to minimize interval length)
            if(numLine[i].first==0){
                // opening is encountered
                st.push(numLine[i]);
            }else{
            // top of the stack has opening is guaranteed
                length.push_back(numLine[i].second-st.top().second);
                st.pop();
            }

        }
        sort(length.begin(),length.end());
        unsigned long long cost=0;
        for(long long i=0;i<n;i++){
            cost+=length[i]*c[i];
        }

        cout<<cost<<"\n";
    }
    return 0;
}