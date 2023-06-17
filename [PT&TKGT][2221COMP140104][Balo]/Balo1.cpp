#include <iostream>
using namespace std;
/**************************************************************************************************************
* Bài toán Balo một theo giải thuật quy hoạch động
* Ý tưởng :
* Nếu ta có một balo đựng được W Kg mà trước đó ta đã biết cách đựng giá trị tối ưu của các balo có thể tích nhỏ hơn
* có thể đựng được từ 1 cho đến W Kg thì ta sẽ có thể dễ dàng giải quyết bài toán gốc.
***************************************************************************************************************/
int main(){
int n, a[n+1] = {0}, w;
int f[100][100];
    cin>>n>>w;// nhập tổng số món và số kg balo tối đa
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];// nhập số món đồ
    }
    // Xây dựng bảng f
    for (int i = 1; i <= n; i++) {// xét lần lượt các món đồ
        for (int j = 1; j <= w; j++) { // xét các ba lo có khối lượng tối đa từ bé đến lớn
            if (a[i]<=j) {// nếu vật thứ i có thể bỏ được vào balo
                f[i][j] = max(f[i - 1][j],f[i - 1][j-a[i]] +a[i]);
                 // khối lượng tốt nhất của ba lô có khối lượng tối đa j có thể mang được hoặc bằng lựa chọn trước đó (f[i - 1][j])
                // hoặc bằng lựa chọn tối ưu ở ba lô có khối lượng j - a[i] cộng với khối lượng a[i] đang xét
            } else {
                f[i][j] = f[i - 1][j];// nếu không thì sẽ bằng lựa chọn tối ưu trc đó.
            }
        }
    }
    for(int i=1;i<=n;i++) {//xuất bảng f
        for (int j = 0; j <= w; j++) {
            cout<< f[i][j]<<" ";
        }
        cout<<endl;
    }   
    cout<< f[n][w];// xuất ra vị trí món đồ đc chọn
    return 0;
}
