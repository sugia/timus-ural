#include<iostream>
#include<cstring>
using namespace std;
 
int const maxSize=35;
 
class ural1033{
public:
    ural1033(){ size=0; memset(f,0,sizeof f); }
    void input();
    void search(int i, int j);
    int size;
    int getn(){return N;}
private:
    char a[maxSize][maxSize];
    bool f[maxSize][maxSize];
    int N;
};
 
void ural1033::input(){
     cin>>N;
     int i,j;
     for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            cin>>a[i][j];
    for(i=2; i<=N+1; i++)a[0][i]='#';
    for(i=2; i<=N+1; i++)a[i][0]='#';
    for(i=1; i<=N-1; i++)a[N+1][i]='#';
    for(i=1; i<=N-1; i++)a[i][N+1]='#';
}
 
void ural1033:: search(int i, int j){
    if(i<1||i>N||j<1||j>N||a[i][j]=='#'||f[i][j]==1)return ;
    f[i][j]=1;
    if(a[i-1][j]=='#')size++;
       else search(i-1,j);
    if(a[i][j-1]=='#')size++;
       else search(i,j-1);
    if(a[i][j+1]=='#')size++;
       else search(i,j+1);
    if(a[i+1][j]=='#')size++;
       else search(i+1,j);
}

int main(){
    ural1033 ural;
    ural.input();
 
    ural.search(1,1);
    ural.search(ural.getn(),ural.getn());
    cout<<ural.size*9<<endl;
    return 0;
}
