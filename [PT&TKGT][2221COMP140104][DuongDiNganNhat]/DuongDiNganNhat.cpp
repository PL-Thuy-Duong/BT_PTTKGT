
#include <iostream>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int xc,yc,xx,yy,dd[100][100];
char a[100][100];
int dong,cot;
int dem=0,kq=100;
void Nhap();
void Xuly(int x,int y);
int main()
{
    Nhap();
    cout<<kq;
}
void Xuly(int x,int y)
{
    if(x==1 && y==1){
        if(kq>dem) kq=dem;
    }
    else{
        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=1 && xx<=dong && yy>=1 && yy<=cot && dd[xx][yy]==0){
                dd[xx][yy]=1;
                dem++;
                Xuly(xx, yy);
                dem--;
                dd[xx][yy]=0;
            }
        }
    }
}
void Nhap()
{
    cin>>dong>>cot;
    for(int i=1; i<=dong; i++){
        for(int j=1; j<=cot; j++){
            cin>>a[i][j];
            if(a[i][j]=='C'){
                xc=i;
                yc=j;
            }
            if(a[i][j]=='*'){
                dd[i][j]=1;
            }
        }
    }
    dd[xc][yc]=1;
  
    Xuly(xc, yc);
    
}
