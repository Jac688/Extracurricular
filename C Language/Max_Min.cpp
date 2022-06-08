//Progframmer: Jack
//Student ID: 1930026143i;
//Date: 2020/7/20 
//Task no: Summer4 
//Reqirement: max_min
#include<stdio.h>

void maxmin(int a[], int n, int *max, int *min);
int main(){
	int a[10];
	int n;
	for(n = 0; n < 20; n++){
		scanf("%d", &a[n]);
		if(a[n] == -1){
			break;
		}
	}
	int max, min;
	maxmin(a, n, &min, &max);
	printf("max = %d\n, min = %d\n", max, min);
	return 0;
}

void maxmin(int a[], int n, int *max, int *min){
	int i;
	*min = *max = a[0];
	for(i = 1; i < n; i++){
		if(a[i] < *min){
			*min = a[i]; 
		}
		if(a[i] > *max){
			*max = a[i];
		}
	}
}


