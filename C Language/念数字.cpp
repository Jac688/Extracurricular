//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement:ÄîÊý×Ö
#include<stdio.h>
int main(){
	int i;
	printf("Please enter an number:");
	scanf("%d", &i);
	if(i < 0){
		i = -i;
		printf("fu ");
	}
	int j = i, k = 1;
	while(j >= 10){
		j /= 10;
		k *= 10;
	}
	int x;
	while(k > 0){
		x = i / k;
		switch (x){
			case 0: printf("ling ");
			break;
			case 1: printf("yi ");
			break;
			case 2: printf("er ");
			break;
			case 3: printf("san ");
			break;
			case 4: printf("si ");
			break;
			case 5: printf("wu");
			break;
			case 6: printf("liu ");
			break;
			case 7: printf("qi ");
			break;
			case 8: printf("ba ");
			break;
			case 9: printf("jiu ");
			break;
		}
		i %= k;
		k /= 10;
	}
	return 0;
} 
