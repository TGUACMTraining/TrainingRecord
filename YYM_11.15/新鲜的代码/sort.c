#include <stdio.h>
#include <stdlib.h>
void s(int *, int, int);

int main() {
	int *p;
	int n;
	int index;
	int time;
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int));
	for (index = 0; index < n; index++) {
		scanf("%d", &p[index]);
	}
	s(p, 0, n - 1);
	time = 1;
	for (index = 1; index < n; index++) {
		if (p[index] != p[index - 1])
			time++;
	}
	printf("%d\n", time);
	printf("%d ", p[0]);
	for (index = 1; index < n; index++) {
		if (p[index] != p[index - 1])
			printf("%d ", p[index]);
	}
	free(p);
	return 0;
}

void s(int *p, int left, int right) {
	int pivot;
	int lf;
	int rf;
	if (left < right) {
		lf = left;
		rf = right;
		pivot = p[lf];
		while (lf < rf) {
			while (p[rf] >= pivot && lf < rf) {//此处还有判断所是否与右重合的条件
				rf--;
			}
			p[lf] = p[rf];
			while (p[lf] <= pivot && lf < rf) {
				lf++;
			}
			p[rf] = p[lf];
		}
		p[lf] = pivot;
		s(p, left, lf - 1);
		s(p, rf + 1, right);
	} else
		return;
}