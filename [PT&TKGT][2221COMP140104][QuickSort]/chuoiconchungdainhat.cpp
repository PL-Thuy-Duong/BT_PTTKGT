#include<iostream>
using namespace std;
/*Bài toán chuỗi con chung dài nhất (tạm gọi chuỗi A và B) sử dụng kỹ thuật quy hoạch động
Ta sẽ dùng một mảng hai chiều (F) để đánh dấu chuỗi con chung dài nhất của các chuỗi con từ 2 chuỗi ban đầu
với F[i][j] là chiều dài chuỗi con chung lớn nhất của chuỗi con A tính từ phần tử số 0 cho đến phần tử thứ i
và chuỗi con B tính từ phần tử thứ 0 cho đến phần tử thứ j.
Ta dùng Mảng F dời lên 1 đơn vị để tránh các tình huống F[i-1][] hay F[][j-1] bị dính
trọng số âm khi i hoặc j = 0;ví dụ nếu bình thường là F[i][j] thì bây giờ sẽ là F[i+1][j+1]
tất nhiên ta có thể setup trước cho việc i hoặc j = 0, tuy nhiên nó sẽ mất tính đồng bộ
*/
int f[1000][1000];
int main()
{
	string a,b;
	cin >> a >> b;// nhập 2 chuỗi a b
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
				f[i + 1][j + 1] = f[i][j] + 1;
			else
			{
				if (f[i][j + 1] > f[i + 1][j])
					f[i + 1][j + 1] = f[i][j + 1];
				else f[i + 1][j + 1] = f[i + 1][j];
			}
		}
	}
	cout << f[a.size()][a.size()];//độ dai chuỗi con chung dài nhất
	string c = "";
	int i = a.size() - 1, j = b.size() - 1;
	for (int k = 0; k < f[a.size()][b.size()]; k++) //Hàm truy vết chuỗi con dài nhất
	{
		while (a[i] != b[j])
		{
			if (f[i + 1][j + 1] == f[i][j + 1])
				i--;
			else j--;
		}
		c = a[i] + c;
		i--;
		j--;
	}
	cout << c;// cchuỗi con dài nhất là c

	return 0;
}
