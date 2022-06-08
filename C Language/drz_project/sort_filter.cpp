#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

int main(){
	
	int m = 12;
	int n = 6;
	// matrix size
	double d[m][n];
	
	// year
	d[0][0] = d[1][0] = d[2][0] = d[3][0] = d[4][0] = d[5][0] = d[6][0] = d[7][0] = d[8][0] = d[9][0] = d[10][0] = d[11][0] = 2020.0; 
	
	// month
	d[0][1] = d[1][1] = d[2][1] = d[3][1] = d[4][1] = d[5][1] = d[6][1] = d[7][1] = 8.0;
	d[8][1] = d[9][1] = d[10][1] = d[11][1] = 9.0;
	
	// day 
	d[0][2] = d[1][2] = 28;
	d[2][2] = d[3][2] = 29;
	d[4][2] = d[5][2] = 30;
	d[6][2] = d[7][2] = 31;
	d[8][2] = d[9][2] = 1;
	d[10][2] = d[11][2] = 2;
	
	// location
	d[0][3] = d[2][3] = d[4][3] = d[6][3] = d[8][3] = d[10][3] = 18.0;
	d[1][3] = d[3][3] = d[5][3] = d[7][3] = d[9][3] = d[11][3] = 22.0;
	
	// min_temp
	d[0][4] = 6.7;
	d[1][4] = 12.7;
	d[2][4] = 7.6;
	d[3][4] = 13.4;
	d[4][4] = 7.3;
	d[5][4] = 13.2;
	d[6][4] = 7.3;
	d[7][4] = 13.2;
	d[8][4] = 9.4;
	d[9][4] = 16.1;
	d[10][4] = 8.7;
	d[11][4] = 14.2;
	
	//max_temp
	d[0][5] = 12.9;
	d[1][5] = 19.1;
	d[2][5] = 15.3;
	d[3][5] = 21.9;
	d[4][5] = 21.8;
	d[5][5] = 23.2;
	d[6][5] = 21.8;
	d[7][5] = 23.2;
	d[8][5] = 15.9;
	d[9][5] = 27.2;
	d[10][5] = 16.3;
	d[11][5] = 21.4;
	
	int a, b, c;
	printf("Please enter the order: ");
	scanf("%d d %d", &a, &b, &c);
	
	// first line
	if(c == 0)
		printf("\t\t\t year");
	else if(c == 1)
		printf("\t\t\t month");
	else if(c == 2)
		printf("\t\t\t day");
	else if(c == 3)
		printf("\t\t\t location");
	else if(c == 4)
		printf("\t\t\t mintemp");
	else if(c == 5)
		printf("\t\t\t maxtemp");
	else
		printf("Waring! You should enter zero to five!");
		
	// second line
	if(b == 0)
		printf("\t\t year");
	else if(b == 1)
		printf("\t\t month");
	else if(b == 2)
		printf("\t\t day");
	else if(b == 3)
		printf("\t\t location");
	else if(b == 4)
		printf("\t\t mintemp");
	else if(b == 5)
		printf("\t\t maxtemp");
	else
		printf("Waring! You should enter zero to five!");
		
	// third line
	if(a == 0)
		printf("\t\t year");
	else if(a == 1)
		printf("\t\t month");
	else if(a == 2)
		printf("\t\t day");
	else if(a == 3)
		printf("\t\t location");
	else if(a == 4)
		printf("\t\t mintemp");
	else if(a == 5)
		printf("\t\t maxtemp");
	else
		printf("Waring! You should enter zero to five!");
	
	int i = 0;		
	double temp1 = 0;
	// first_sort: ascending order 		
	for(int k = 0; k <= m - 2; k++){
		for(int j = k + 1; j <= m - 1; j++)
			if(d[k][a] < d[j][a]){
				for(i = 0; i < n; i++){
					temp1 = d[j][i];
					d[j][i] = d[k][i];
					d[k][i] = temp1;
				}
			}
	}
	
	// second_sort: ascending order
	for(int k = 0; k <= m - 2; k++){
		for(int j = k + 1; j <= m - 1; j++)
			if(d[k][a] == d[j][a] & d[k][b] < d[j][b]){
				for(i = 0; i < n; i++){
					temp1 = d[j][i];
					d[j][i] = d[k][i];
					d[k][i] = temp1;
				}
			}
	}
	
	// third_sort: ascending order
	for(int k = 0; k <= m - 2; k++){
		for(int j = k + 1; j <= m - 1; j++)
			if(d[k][b] == d[j][b] & d[k][c] < d[j][c]){
				for(i = 0; i < n; i++){
					temp1 = d[j][i];
					d[j][i] = d[k][i];
					d[k][i] = temp1;
				}
			}
	}
	
	int cnt[m];
	// initial
	for(int k = 0; k < m; k++){
		cnt[k] == 0;
	}
	int cn = 0;
	for(int k = 0; k < m-1; k++){
		if(k == 0){
			if(d[k][a] == d[k+1][a] && d[k][b] == d[k+1][b] && d[k][c] == d[k+1][c]){
				cnt[k] = 0;
		    }
		    else
		    	cnt[k];
		}
		if(k >= 1 && k < m){
			if(d[k][a] == d[k-1][a] && d[k][b] == d[k-1][b] && d[k][c] == d[k-1][c]){
				cn++;
				cnt[t-cn]++;
				if(d[k][a] == d[k+1][a] && d[k][b] == d[k+1][b] && d[k][c] == d[k+1][c]){
					
				}
				else{
					cn = 0;
				}
			}
			else{
				if(d[k][a] == d[k+1][a] && d[k][b] == d[k+1][b] && d[k][c] == d[k+1][c]){
					
				}
				else{
					cnt[k] = 0;
					cn = 0;
				}	
			}
		}
	}
	
	// printf
	for(i = 0; i < m; i += (cnt[i]+1)){
		printf("%d\t%d\t%d", d[i][a], d[i][b], d[i][c]);
		if(cnt[i] >= 1){
			printf("\t( %d instances)", cnt[i]);
		}
	} 

	return 0;
}
