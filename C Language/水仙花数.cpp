//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer2 
//Reqirement: Get all the shuixianhuashu in a range, Like 153 = 1^3 + 5^3 + 3^3.
#include<stdio.h>
int main(){
	int n;
	printf("Please enter an integer:");
	scanf("%d", &n);  // Get the digits
	int i = 1, con = 1;
	while(con <= n){
		i *= 10;
		con++;
	}

	int x;
	for(x = i / 10; x < i ; x++){  //Travel
		int t = x;
		int sum = 0;
		while(t > 0){
			int t1 = t % 10;
			t /= 10;
			int t2 = 1;
			for(int m = 0; m < n; m++){
				t2 *= t1;
			}
			sum += t2;
		}
		if(sum == x){
			printf("%d\t", x);
		}
	}
	return 0; 
}

