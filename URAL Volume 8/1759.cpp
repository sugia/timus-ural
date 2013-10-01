#include <iostream>
#include <string>
using namespace std;
const int maxn=122;
struct Date{int year, month, day;};
int best, tmp, id, n;
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
Date bestb, bestd, tmpb, tmpd;
int leap(int year){return (year%4==0&&year%100!=0)||year%400==0;}
int datecmp(Date a, Date b){
   if(a.year != b.year)
	 return a.year - b.year;
   if(a.month != b.month)
	 return a.month - b.month;
   return a.day - b.day;
}
int date2int(Date a){
  int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400;
  days[1]+=leap(a.year);
  for(int i=0; i<a.month-1; ret+=days[i++]);
  days[1]=28;
  return ret+a.day;
}
void cal(string str, Date &d){
    d.day=(str[0]-'0')*10+(str[1]-'0');
    d.month=(str[3]-'0')*10+(str[4]-'0');
    d.year=(str[6]-'0')*1000+(str[7]-'0')*100+(str[8]-'0')*10+(str[9]-'0');     
}
int main(){
    string str;
    cin>>n>>str;
    cal(str, bestb);
    cin>>str>>str;
    cal(str, bestd);
    best=date2int(bestd)-date2int(bestb),id=1;
    for(int i=2;i<=n;++i){
        cin>>str;
        cal(str, tmpb);
        cin>>str>>str;
        cal(str, tmpd);
        tmp=date2int(tmpd)-date2int(tmpb);
        if(tmp>best || (tmp==best && datecmp(bestd, tmpd)>0)){bestb=tmpb,bestd=tmpd,best=tmp,id=i;}     
    }    
    cout<<id<<endl;
    return 0;
}