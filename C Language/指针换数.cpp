//Progframmer: Jack
//Student ID: 1930026143i;
//Date: 2020/7/20 
//Task no: Summer4 
//Reqirement: Ö¸Õë»»Êý
#include<stdio.h>
void swap(int *a, int *b);

int main(){
	int a, b;
	printf("Please enter two numbers: ");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
} 
