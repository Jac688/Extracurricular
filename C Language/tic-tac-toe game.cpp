//Progframmer: Jack
//Student ID: 1930026143i;
//Date: 2020/7/12 
//Task no: Summer3 
//Reqirement: tic-tac-toe game
#include<stdio.h>
int main(){
	int board[3][3];
	int i, j;
	int fX, fO;
	int result = -1;  // -1:ƽ��, 0: OӮ, 1: XӮ 
	//�������� 
	for( i = 0; i < 3; i++){
		for( j = 0; j < 3; j++){
			scanf("%d", &board[i][j]);
		}
	}
	// ������
	for( i = 0; i < 3 && result == -1; i++){
		fO = 0;
		fX = 0;
		for(j = 0; j < 3; j++){
			if(board[i][j] == 1)
				fX++;
			else
				fO++;
		}
		if(fX == 3)
			result = 1;
		else if(fO == 3)
			result = 0;	
	}
	//�����
	if(result == -1){
		for( j = 0; j < 3 && result == -1; j++){
			fO = 0;
			fX = 0;
			for(i = 0; i < 3; i++){
				if(board[i][j] == 1)
					fX++;
				else
					fO++;
			}
			if(fX == 3)
				result = 1;
			else if(fO == 3)
				result = 0;
		}
	}
	//����Խ���
		//���Խ��� 
	if(result == -1){ 
		for(i = 0; i < 3; i++){
			if(board[i][i] == 1)
				fX++;
			else
				fO++;
		}
		if(fX == 3)
			result = 1;
		else if(fO == 3)
			result = 0;
	}
		// ���Խ���
	if(result == -1){
		for(i = 0; i < 3; i++){
			if(board[i][2-i] == 1)
				fX++;
			else
				fO++;
		}
		if(fX == 3)
			result = 1;
		else if(fO == 3)
			result = 0;
	}
	if(result == 1)
		printf("\nThe winner is X.");
	if(result == 0)
		printf("\nThe winner is O.");
	else 
		printf("\nThe game is draw.");
	return 0;
} 








