//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement:¾Å¾Å³Ë·¨±í
#include<stdio.h>
int main(){
	int r, c;
	for(r = 1; r <= 9; r++){
		for(c = 1; c <= r; c++){
			printf("%d * %d = %d", c, r, r * c);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
}
