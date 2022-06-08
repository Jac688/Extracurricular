//Progframmer: Jack
//Student ID: 1930026143
//Date: 2020/6/22 
//Task no: Summer1 
#include<stdio.h>
int main(){
	int a;
	printf("Please enter an integer: ");
	scanf("%d", &a);
	int i, j, k;
	int n = 0;  // count the number
	i = a;
	while( i <= a + 3 ){
		j = a;
		while( j <= a +3){
			k = a;
			while(k <= a + 3){
				if ( i != j && i!= k && j != k){
					printf("%d", i*100 + j *10 + k);
					n++;
					if (n % 6 == 0)
						printf("\n");
					else
						printf("  ");	
				}
				k++;
			}
			j++;
		}
		i++;
	}	
	return 0;
}
/* If input is 2, output is:
234  235  243  245  253  254
324  325  342  345  352  354
423  425  432  435  452  453
523  524  532  534  542  543
*/
