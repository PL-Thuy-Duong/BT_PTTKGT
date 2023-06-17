#include<iostream>
using namespace std;
const int Max=9999;
int sd, a[100][100],dd[100], Min=Max, vtMin, canh[100][2],tt,vt,v;
int main()
{   
    cin>>sd;//nhập số đỉnh
    for(int i=1;i<=sd;i++)
    {
        for(int j=1;j<=sd;j++)
        {
            cin>>a[i][j];//ma trận trọng số
            if(a[i][j] == 0 && i != j)//nếu như vị trí [i][j] chưa đc đánh dấu và không liền kè vs các đỉnh khác
                a[i][j] = Max;//gán cho giá trị MAX
        }
    }
    dd[1] = 1; chọn đỉnh 1 là điểm bắt đầu
    for(int k=1;k<sd;k++)
    {
        for(int i=1;i<=sd;i++)
        {
           if(dd[i] != 0)// lấy đỉnh trong mảng dd đã đánh dâu
           {
              for(int j=1;j<=sd;j++)
              {
                  if(dd[j] == 0)// tìm đỉnh chưa được đánh dấu một liền kề với đỉnh đã được chọn
                  {
                      if(a[i][j] < Min)
                        {
                            Min = a[i][j];//lưu giá trị nhỏ nhất và vị trí của nó
                            vt = j;
                            v = i;
                        }
                  }
              }
                
            }
        }
        dd[vt] = 1;// chọn đc vị trí đỉnh có giá trị nhỏ nhất và đánh dấu
        canh[k][0] = v;//lưu cạnh được chọn vào mảng
        canh[k][1] = vt;
        Min = Max;
    }
    int t = 0;
    for(int i=1;i<sd;i++)
    {
        t+=a[canh[i][0]][canh[i][1]];//tổng quảng đường đi
    }
    cout<<t;//trọng số nhỏ nhất của con đường
    return 0;
}
