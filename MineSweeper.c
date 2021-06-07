#ifndef __GAME_H__
#define __GAME_H_
#define ROW 9
#define COL 9	//Plan the board
#define ROWS ROW+2
#define COLS COL+2
#define MINE_NUM 20		//Set the limit of the mines
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void Menu();//The menu of the game
void Game();//The main game function
void Mine(char mine_map[ROWS][COLS]);//Setting the mine's position
void Print(char mine_map[ROWS][COLS]);//Printing the board in the game
void Init(char mine_map[ROWS][COLS],char mine_map_show[ROWS][COLS]);//Initializing the board
void Clear_Mine(char mine_map[ROWS][COLS], char mine_map_show[ROWS][COLS]);//Function for players to sweep
int Go_on(char mine_map_show[ROWS][COLS]);//To judge whether the game would coutinue
int Mine_num(char mine_map[ROWS][COLS], int row, int col);//Judging how many mines are around the position the player chosen
int Is_win(char mine_map_show[ROWS][COLS]);//Determining if the player wins
#endif//Game.h

#pragma once //Ensure that the header file is compiled only once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASILY 0//The quantity of mines

//Initialization
void initzeboard(char mine[ROWS][COLS], int rows, int cols, char val);

//Display the board
void Display_board(char mine[ROWS][COLS], int row, int col);

//Bury mines
void random_mine(char mine[ROWS][COLS], int row, int col);

//Sweep mines
void mine_sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

extern void game();	//Quote the game function

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));	//Generate a random number sequence and set a random seed

	do
	{
		printf("**************************\n");
		printf("***      0. exit       ***\n");
		printf("***      1. play       ***\n");
		printf("***      2. clear      ***\n");
		printf("**************************\n");
		printf("Please select:>");
		scanf("%d", &input);	//Display the choices for the player

		switch (input)	//Explanation of the choices
		{
		case 1:
			game();//Achieve the game
			break;
		case 2://Clean the screen
			system("cls");
			break;
		case 0://Quit the program
			printf("Quit the program!\n");
			break;
		default://Reinput the selection
			printf("Input error,please input again!\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

int count = 0;//Counting how many attices were left


void game()//Achieve the game
{
	char mine[ROWS][COLS] = { 0 };//For burying the mines
	char show[ROWS][COLS] = { 0 };//For the screen display of the game

	//Initialization
	initzeboard(show, ROWS, COLS, '*');
	initzeboard(mine, ROWS, COLS, '0');

	//Display the board
	Display_board(show, ROW, COL);
	//Display_board(mine, ROW, COL);

	//Bury mines
	random_mine(mine, ROW, COL);
	//Display_board(mine, ROW, COL);
	
	//Sweep mines
	mine_sweeping(mine, show, ROW, COL);
}

//Initialization
void initzeboard(char mine[ROWS][COLS], int rows, int cols, char val)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = val;
		}
	}
}

//Display the board
void Display_board(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	printf("            Mine Sweeper\n");
	printf("---------------------------------\n");
	for (j = 0; j <= col; j++)	//Print the ordinate label
	{
		printf("%d ", j);
	}

	printf("\n");

	for (i = 1; i <= row; i++)	//Column labels are printed on the outer layer
	{							//and each column is printed on the inner layer
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", mine[i][j]);
		}

		printf("\n");

	}
}

//Bury mines
void random_mine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASILY;

	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//Counting how many attices were left
static int statistics_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}


//Sweep mines
void mine_sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	while (count < row * col - EASILY)
	{
		system("cls");
		Display_board(show, COL, ROW);
		printf("Please input coordinate:>");
		scanf("%d %d", &x, &y);

		//Determine whether the input coordinates are out of bounds
		//The array after filling the bounds starts at 1 and ends at 10
		if ((1 <= x && x <= row) && (1 <= y && y <= col))
		{
			if (mine[x][y] == '0')
			{
				int leng = statistics_mine(mine, x, y);
				show[x][y] = leng + '0';
				count++;
			}
			else
			{
					printf("Sorry,you've been blown\n");
					Display_board(mine, ROW, COL);
					break;
			}
		}
		else
		{                       
				printf("Please input valid numbers!\n");
		}
	}

	if (count == row * col - EASILY)
	{
		printf("Congratulations!\n");
		Display_board(mine, ROW, COL);
	}
}