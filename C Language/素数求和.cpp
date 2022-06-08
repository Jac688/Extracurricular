//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement: ËØÊıÇóºÍ
#include<stdio.h>
int main (){
	int m, n;
	printf("Please enter two integer(range):"); 
	scanf("%d %d", &m, &n);
	int i = m;
	int sum = 0;
	while(i <= n){
		int j, k = 0;
		for(j = 2; j < i; j++){
			if(i % j == 0){
				k ++;
			}
		}
		if(k != 0){
			sum += i;
		}
		i++;
	}
	printf("%d", sum);
	return 0;
}

