#include<bits/stdc++.h>
using namespace std;
int main(){
	printf("输入学分，百分比分数以0 0结束\n"); 
	double x,y;
	double num=0;
	double num1=0; 
	while(cin>>x>>y&&x!=0)
	{
		if(y>=60)
		num+=((4-3*(100-y)*(100-y)/1600)*x);
		num1+=x;
	}
	printf("GPA:%lf\n",num/num1);
	system("pause");
	return 0;
} 
