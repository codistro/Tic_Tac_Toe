#include<stdio.h>
char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
void print(){
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++)
			printf("%c ",board[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
void player1(){
	char choice;
	int ok = 1;
	printf("Player1's turn\n");
	do{
		printf("Enter number where you want insert X\n");
		scanf(" %c",&choice);
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(choice == board[i][j]){
					board[i][j] = 'X';
					ok = 0;
				}
				else
					continue;
			}
		}
	}while(ok);
}
void player2(){
	char choice;
	int ok = 1;
	printf("Player2's turn\n");
	do{
		printf("Enter number where you want insert O\n");
		scanf(" %c",&choice);
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(choice == board[i][j]){
					board[i][j] = 'O';
					ok = 0;
				}
				else
					continue;
			}
		}
	}while(ok);
}
int check(){
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X'){
		printf("Player1 won\n");
		return 1;
	}
	else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O'){
		printf("player2 won\n");
		return 2;
	}
}
int main(){
	printf("\n-----------\n");
	printf("TIC TAC TOE");
	printf("\n-----------\n\n");
	int result;
	print();
	do{
		player1();
		print();
		player2();
		print();
		result = check();
	}while(1);
	if(result == 1) printf("Player1 won\n");
	else if(result == 2) printf("player2 won\n");
	else printf("Draw\n");
	return 0;
}