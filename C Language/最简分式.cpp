//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement:求最简分式 
#include<stdio.h>
int main(){
	int a, b;
	
	printf("Please enter two number:");
	scanf("%d %d", &a, &b);
	int m = a, n = b;
	int t;
	while(b != 0){
		t = a % b;
		a = b;
		b = t;
	}
	printf("%d/%d", m / a, n / a);
	return 0;
} 
