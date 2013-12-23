//#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
struct node{
    int n,t;
    node* next,*prev;
    node(){n=t=0;next=prev=this;}
};
node a[65700];//time
node *b[30010]={0};//space
bool d[65700]={false};
int curtime=0,minua=0,lasttime=599;
const int T=600;
int max(int a,int b){return a>b?a:b;}
void addnode(int time,int num){
    node* p=a[time].prev;
    p->next=new node();
    p->next->prev=p;
    p=p->next;
	p->next=&a[time];
	a[time].prev=p;
    p->n=num;
    p->t=time;
    b[num]=p;
}
int main(){
    while(cin>>curtime){
        char t;
        cin>>t;
        if(!d[curtime]){
            if(curtime>=600){
                for(int i=curtime-600;i>lasttime-600;i--)
                    if(a[i].next!=0){
                        node* p=a[i].next,*q;
                        while(p!=&a[i]){
                            q=p;p=p->next;
                            b[q->n]=0;
                            if(q->n<minua)minua=q->n;
                            delete q;
                        }
                        a[i].next=a[i].prev=&a[i];
                    }
		    lasttime=curtime;
	    }
            d[curtime]=true;
        }
        if(t=='+'){
            cout<<minua+1<<endl;
            addnode(curtime,minua);
            do{
                minua++;
            }while(b[minua]);
        }
        else{
            int num;cin>>num;num--;
            if(!b[num])cout<<'-'<<endl;
            else{
                node* p=b[num];
                p->prev->next=p->next;
                p->next->prev=p->prev;
                addnode(curtime,num);
                delete p;
                cout<<'+'<<endl;
            }
        }
    }
    return 0;
}
