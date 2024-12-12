#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    stack<int> st;
    for(int i=0;i<n;i++){
        cin>>x;
        while(!st.empty() && st.top()>x){
            st.pop();
        }
        if(st.empty()){
            cout<<"0 ";
            st.push(x);
        }else{
            cout<<st.top();
        }
    }

    return 0;
}