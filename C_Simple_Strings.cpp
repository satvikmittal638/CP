#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int n=s.length();
    vector<pair<int,int>> rpt; // store start and end of repetitive character segments
    for(int i=0;i<n;){
        int start=i;
        char c=s[i];
        while(i<n && s[i]==c){
            i++;
        }
        if(i-start>1){
            rpt.push_back({start,i-1});
        }
    }
    for(auto p:rpt){
        set<char> st;
        st.insert('a');
        st.insert('b');
        st.insert('c');
        st.insert('d');
        int start=p.first,end=p.second;
        st.erase(s[start]);
        if(start>0) st.erase(s[start-1]);
        if(end<n-1) st.erase(s[end+1]);
        // now I have atleast 1 character remaining in the set
        char c=*st.begin();
        // alternate the unequal character
        for(int i=start+1;i<=end;i+=2){
            s[i]=c;
        }
    }
    cout<<s;
    return 0;
}