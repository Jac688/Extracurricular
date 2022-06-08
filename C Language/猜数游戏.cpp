//Progframmer: Jack
//Student ID: 1930026143i;
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement: ²ÂÊıÓÎÏ·
#include<stdio.h>
int main(){
	int i, n;
	printf("Please enter the number and the frequency:");
	scanf("%d %d", &i, &n);
	int m = 1, j, k = 0;
	do{
		printf("Please begin to guess:");
		scanf("%d", &j);
		if(j == i){
			break;
		}
		if(j < 0){
			printf("Game over!");
			k = 1;
			break;
		}
		m++;
		if(j > i){
			printf("Too big.\n");
		}
		if(j < i){
			printf("Too small.\n");
		}
	}while(m <= n);
	
	if( k == 0 & m == 1 ){
		printf("Bingo!");
	}
	else if(m > 1 && m <= 3){
		printf("Lucky you!");
	}
	else if(m > 3 && m < n){
		printf("Good guess!");
	}
	else if(m == n){
		printf("Game over!"); 
	}
	return 0;
}
