// http://codevs.cn/problem/1160/
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	// 输入矩阵的长宽，均为n
	cin >> n;
	if(n == 1) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	// 将矩阵数组内容全置为0
	int arr[n][n];
	memset(arr,0,sizeof(arr));
	int x = n / 2;
	int y = x;
	// 分别是右，上，左，下四种方向
	int step[4][2] = {
		{0, 1},
		{-1, 0},
		{0, -1},
		{1, 0}
	};
	// 方向初始化为向右
	int step_i = 0;
	int len = n * n;
	int count = 1;
	arr[x][y] = count;
	while(count < len) {
		if(arr[x + step[step_i][0]][y + step[step_i][1]] == 0) {
			x += step[step_i][0];
			y += step[step_i][1];
			arr[x][y] = ++count;
			// 若此时方向为向下，则变更为向右
			step_i == 3 ? step_i = 0 : step_i++;
		} else {
			// 若此时方向为向右，则变更为向下（即回退为上一步的方向）
			step_i == 0 ? step_i = 3 : step_i--;
		}
	}
	// 输出矩阵
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1; j++) {
			cout << arr[i][j] << " ";
		}
		cout << arr[i][n-1] << endl;
	}
	// 计算对角线之和
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += arr[i][i];
	}
	int tx = n / 2;
	int ty = n / 2;
	while(!(tx == 0)) {
		tx--;
		ty++;
		sum += arr[tx][ty];
	}
	tx = n / 2;
	ty = n / 2;
	while(!(ty == 0)) {
		tx++;
		ty--;
		sum += arr[tx][ty];
	}
	// 输出和
	cout << sum << endl;
	return 0;
}