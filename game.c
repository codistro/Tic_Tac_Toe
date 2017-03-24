#include<stdio.h>
#include<stdlib.h>
char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
int count = 0;
void print(){
	system("clear");
	printf("\n\t\t\t-----------\n");
	printf("\t\t\tTIC TAC TOE");
	printf("\n\t\t\t-----------");
	printf("\n\n");
	printf("\t\t\t %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
	printf("\n\n");
}
int check(int x,int y){
	if(board[0][y] == board[1][y] && board[1][y] == board[2][y] ||
	   board[x][0] == board[x][1] && board[x][1] == board[x][2])
		return 1;
	if(x == y && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return 1;
	if(x+y == 2 && board[2][0] == board[1][1] && board[1][1] == board[0][2])
		return 1;
	return 0;
}
int player1(){
	char choice;
	int ok = 1;
	printf("\t\t\t||Player 1||\n\n");
	do{
		printf("\t\tEnter number where you want insert X: ");
		scanf(" %c",&choice);
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(choice == board[i][j]){
					board[i][j] = 'X';
					ok = 0;
					if(check(i,j)){
						print();
						printf("\t\t\t-------------\n");
						printf("\t\t\tPlayer 1 won\n");
						printf("\t\t\t-------------\n");
						return 1;
					}
				}
				else
					continue;
			}
		}
	}while(ok);
	++count;
	if(count == 9){
		print();
		printf("\t\t\t    ----\n");
		printf("\t\t\t    DRAW\n");
		printf("\t\t\t    ----\n");
		return 1;
	}
	return 0;
}
int player2(){
	char choice;
	int ok = 1;
	printf("\t\t\t||Player 2||\n\n");
	do{
		printf("\t\tEnter number where you want insert O: ");
		scanf(" %c",&choice);
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(choice == board[i][j]){
					board[i][j] = 'O';
					ok = 0;
					if(check(i,j)){
						print();
						printf("\t\t\t-------------\n");
						printf("\t\t\tPlayer 2 won\n");
						printf("\t\t\t-------------\n");
						return 2;
					}
				}
				else
					continue;
			}
		}
	}while(ok);
	++count;
	if(count == 9){
		print();
		printf("\t\t\t----\n");
		printf("\t\t\tDRAW\n");
		printf("\t\t\t----\n");
		return 1;
	}
	return 0;
}
int main(){
	print();
	int res;
	do{
		res = player1();
		if(res) break;
		print();
		res = player2();
		if(res) break;
		print();
	}while(res == 0);
	return 0;
}