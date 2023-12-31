﻿#include<iostream>
using namespace std;
/**************************************************************************************************************
* Bài toán Balo một theo giải thuật quy hoạch động
* Ý tưởng :
* Nếu ta có một balo đựng được W Kg mà trước đó ta đã biết cách đựng giá trị tối ưu của các balo có thể tích nhỏ hơn
* có thể đựng được từ 1 cho đến W - 1 Kg thì ta sẽ có thể dễ dàng giải quyết bài toán gốc như bài balo1
***************************************************************************************************************/
int n, w;
int a[100],b[100], f[100][101]; // mảng f[i][j] sẽ chứa giá trị tối ưu của balo có trọng lượng tối đa j ở lượt chọn vật thứ i
int p[100], o = 0;
int main() {
    cin >> n >> w; // nhập tổng số món và số kg balo tối đa
    for (int i = 1; i <= n; ++i) // nhập số món đồ và giá trị món đó
        cin >> a[i] >> b[i];

    for (int i = 1; i <= n; i++) // xét lần lượt các món đồ
    {
        for (int j = 1; j <= w; v++) // xét các ba lo có khối lượng tối đa từ bé đến lớn
        {
            if (j >= a[i]) // nếu vật thứ i có thể bỏ được vào balo
            {
                f[i][j] = max(b[i] + f[i - 1][j - a[i]], f[i - 1][j]);
                // khối lượng tốt nhất của ba lô có khối lượng tối đa j có thể mang được hoặc bằng lựa chọn trước đó (f[i - 1][j])
                // hoặc bằng lựa chọn tối ưu ở ba lô có khối lượng j - a[i] cộng với khối lượng a[i] đang xét
            }
            else f[i][j] = f[i - 1][j]; // nếu không thì sẽ bằng lựa chọn tối ưu trc đó.
        }
    }
    cout << f[n][w];
    for (int i = n; i >= 0; --i) // hàm truy vết nếu
    {
        if (f[i][w] != f[i - 1][w]) // nếu bằng nhau thì chứng tỏ vật a[i] không được chọn và ngược lại
        {
            p[o++] = i;
            w -= a[i];
        }
    }
    for (int i = o - 1; i >= 0; --i)
        cout << p[i] << " ";// xuất ra vị trí món đồ đc chọn
    return 0;
}
