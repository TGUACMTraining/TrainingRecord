#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	float ans = 0, maxNum = -1, minNum = 100;
	int p = n;
	while (n--) {
		float x;
		cin >> x;
		ans += x;
        // 记录最大值和最小值，最后再减去这两个值
		maxNum = max(x, maxNum), minNum = min(x, minNum);
	}
	cout<<ans;
	cout<<ans - maxNum - minNum<<endl;
	printf("%.2f", (ans - maxNum - minNum) / (p - 2.0));
	return 0;
}
