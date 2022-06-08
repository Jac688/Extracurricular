//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement:求序列前n项和：2/1 + 3/2 + 4/3 + ... + n+1/n
#include<stdio.h>
int main(){
	int n;
	printf("Please enter an enteger:");
	scanf("%d", &n);
	float i = 1, j;
	j = i + 1;
	float sum = 0;
	while(i <= n){
		float k = j / i;
		sum += k;
		i = j;
		j++;
	}
	printf("%f", sum);
	return 0; 
}
