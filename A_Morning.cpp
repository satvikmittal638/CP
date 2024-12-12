#include<iostream>
using namespace std;


int minTime(string s){
    int ptr=1,totalTime=0;
    for(int i=0;i<s.length();i++){
        int dig=s[i]-'0',time=0;
        if(dig==0){
            dig=10;
        }
        // shifting
        while(ptr>dig){
            ptr--;
            time++;
        }
        while(ptr<dig){
            ptr++;
            time++;
        }
        time++; // pressing
        totalTime+=time;
    }
    return totalTime;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<minTime(s)<<endl;
    }
    return 0;
}