#include <iostream>
using namespace std;
int x, y, xx, yy, step, lef, rig, ans=0;
int sqr(int x){return (x)*(x);}
void cal(int x, int &tmpx, int &tmpy){
    tmpx=1;
    while(x>sqr(tmpx))++tmpx;         
    tmpy=tmpx*2-1;
    tmpy-=sqr(tmpx)-x;  
}
int main(){
    cin>>lef>>rig;
    cal(lef, x, y),cal(rig, xx, yy);
    if(x==xx)
        ans=abs(y-yy);
    else{
        if(x>xx){swap(x, xx),swap(y, yy);}    
        if(y%2){step=(xx-x-1)*2+1,lef=y+1;}
            else{step=(xx-x)*2,lef=y;}
        rig=y+step;
        if(lef<=yy && yy<=rig)ans+=yy%2?step+1:step;
            else ans+=step+min(abs(yy-lef), abs(yy-rig));   
    } 
    cout<<ans<<endl;
    return 0;        
}