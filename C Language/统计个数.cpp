//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/7/10 
//Task no: Summer3 
//Reqirement: 统计个数
#include<stdio.h>
int main(){
	int a[10];
	int x;
	int i;
	for(i = 0; i <= 9; i++){
		a[i] = 0;
	} 
	do{
		scanf("%d", &x);
			if(x >= 0 && x <= 9){
				a[x]++;
			}
	 }while(x != 1);
	
	for(i = 0; i <= 9; i++){
		printf("%d:%d\t", i, a[i]);
	}
	return 0;
}

