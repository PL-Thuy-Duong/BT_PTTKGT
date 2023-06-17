#include <iostream>
using namespace std;
int main(){
int n, a[n+1] = {0}, w;
int f[100][100];
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    // Xây dựng bảng f
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i]<=j) {
                f[i][j] = max(f[i - 1][j],f[i - 1][j-a[i]] +a[i]);// quy hoạch động
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    //xuất ra bảng f
    for(int i=1;i<=n;i++) {
        for (int j = 0; j <= w; j++) {
            cout<< f[i][j]<<" ";
        }
        cout<<endl;
    }   
    court<<f[n][w];//xuất khối lượng tối đa
    return 0;
}
