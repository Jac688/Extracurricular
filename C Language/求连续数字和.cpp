//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement:求连续数字和：a + aa + aaa + aaaa...(n个a) 
#include<stdio.h>
int main(){
	int a, n;
	printf("Please enter two numbers:");
	scanf("%d %d", &a, &n);
	int sum = 0;
	int t = 0;
	for(int i = 1; i <= n; i++){
		t = t*10 + a;
		sum = sum + t;
	}
	printf("%d", sum);
} 
