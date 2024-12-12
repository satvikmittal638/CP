#include<bits/stdc++.h>
using namespace std;

int daysInMonth(int month,int year){
    month--; // 0 based indexing
    int calendar[]={31,year%4==0?29:28,31,30,31,30,31,31,30,31,30,31};
    return calendar[month];
}
int daysInYear(int year){
    return year%4==0?366:365;
}

bool isValidDate(int *date){
    return (1<=date[1] && date[1]<=12) &&
        date[0]<=daysInMonth(date[1],date[2]);
}



int main()
{
    // d1->birth, d2->contest
    string d1,d2;cin>>d1>>d2;
    int date1[]={stoi(d1.substr(0,2)),stoi(d1.substr(3,2)),stoi(d1.substr(6,2))};
    int date2[]={stoi(d2.substr(0,2)),stoi(d2.substr(3,2)),stoi(d2.substr(6,2))};
    sort(date1,date1+3);
    int maxDiff=0;
    do{
        if(isValidDate(date1)){
            int curDiff=(date1[0] + daysInMonth(date1[1],date1[2]) + daysInYear(date1[2]))-
            (date2[0] + daysInMonth(date2[1],date2[2]) + daysInYear(date2[2])); 

            maxDiff=max(maxDiff,curDiff);
        }
    }while(next_permutation(date1,date1+3)); 
    cout<<maxDiff;
    if(maxDiff>=18*365) cout<<"YES";
    else cout<<"NO";
    return 0;
}