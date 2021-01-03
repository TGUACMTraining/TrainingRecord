#include<bits/stdc++.h>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
} 
int main() {
	double a = 0, b = 0, c = 0;
	double x1, x2, x3, y1, y2, y3;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	a = dis(x1, y1, x2, y2);
	b = dis(x1, y1, x3, y3);
	c = dis(x2, y2, x3, y3);
	printf("%.2lf", a + b + c);
	return 0;
}
