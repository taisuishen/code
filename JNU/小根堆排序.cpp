#include<stdio.h>
#define ex(a,b) a^=b^=a^=b 
void heapify(int a[], int i, int n) {
	if (i >n)return;
	int ls = 2 * i+1;
	int rs = 2 * i + 2;
	int min = i;
	if (ls <= n && a[ls] < a[min])	min = ls;
	if (rs <= n && a[rs] < a[min])	min = rs;
	if (min-i) 
	{
		ex(a[i],a[min]);
		heapify(a, min, n);
	}	
}
void heapSort(int a[], int n) {
	for (int j = (n-1)/ 2; j >= 0; j--) {
		heapify(a, j, n);
	}
	for (int i = n; i >= 0; i--) {
		if(i)ex(a[i],a[0]);
		printf("%d ", a[i]);
		heapify(a, 0, i-1);  //已经输出最小的or 最大的 下次转移从0-i-1区间 
	}
}
int main() {
	int a[] = {0,1,3,2,5,4,6,7,8};
	heapSort(a, 8);
	return 0; 
}

