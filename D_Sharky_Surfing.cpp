#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m,L;cin>>n>>m>>L;
       vector<int> l(n),r(n),x(m),v(m);
       for(int i=0;i<n;i++) cin>>l[i]>>r[i];
       for(int i=0;i<m;i++) cin>>x[i]>>v[i];

        // keeps maxm of all powerups seen on top
        priority_queue<int> pq; 
       int i=0,j=0,jump=1,cnt=0;
       // try passing all the obstacles
       while(i<n){
        // store all the powerups seen till current position
        while(j<m && x[j]<l[i]){
            pq.push(v[j]);
            j++;
        }
        // increase to enough jump power to cross the current obstacle
        while(!pq.empty() && r[i]-l[i]+2>jump){
            jump+=pq.top(); // take the maxm of all the power-ups seen till now greedily
            pq.pop();
            cnt++;
        }
        // can bypass the hurdle after picking up some power-ups
        if(r[i]-l[i]+2<=jump){
            i++; // now try passing the next obstacle
        }
        // pq was deemed empty and we couldn't increase jump to the required value
        // hence not possible to pass the current obstacle
        else{
            cnt=-1;
            break;
        }
       }
       cout<<cnt<<"\n";
    }
    return 0;
}