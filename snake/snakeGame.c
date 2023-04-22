#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int height=20, width=20;
int x,y, fruitX, fruitY, score, gameOver, flag;
int tailX[100], tailY[100];
int tails=0;
void drawBoard();
void initialSetup();
void logic();
void getKeys();

int main()
{
	int m, n;
	int c;
	level5:
	initialSetup();
	while(gameOver!=1)
	{
		drawBoard();
		getKeys();
		logic();
		for(m=0;m<10000;m++)
		{
			for(n=0;n<10000;n++)
			{
			}
		}
		for(m=0;m<1000;m++)
		{
			for(n=0;n<10000;n++)
			{
			}
		}
	}
	printf("Press Y to continue again:");
	scanf("%c",&c);
	if(c == 'y' || c == 'Y'){
	goto level5;
}
	return 0;
}

void drawBoard()
{
	int i,j, k;
	system("cls");
	for(i=0;i<=width;i++)
	{
		for(j=0;j<=height;j++)
		{
			if(i == 0 || i == width || j == 0 || j == height)
			{
				printf("*");
			}
			else
			{
				if(i == x && j == y)
				{
					printf("O");
				}
				else if(i == fruitX && j == fruitY)
				{
					printf("F");
				}
				else
				{
					int ch = 0;
				    for(k=0;k<tails;k++)
					{
						if(i == tailX[k] && j == tailY[k])
						{
						printf("o");
						ch = 1;
						}	
					}
					if(ch==0)
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	printf("Score=%d",score);
}

void initialSetup()
{
	gameOver=0;
	x=width/2;
	y=height/2;
	score=0;
	level1:
	fruitX=rand()%20;
	if(fruitX==0)
	goto level1;
		level2:
	fruitY=rand()%20;
	if(fruitY==0)
	goto level2;
}

void getKeys()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 72:
				flag = 1;
				break;
			case 80:
				flag = 2;
				break;
			case 75:
				flag = 3;
				break;
			case 77:
				flag = 4;
				break;
			case 'x':
				gameOver = 1;
				break;
		}
	}
}

void logic()
{
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X;
	int prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(i=1;i<tails;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;	
	}	
	
	switch(flag)
	{
		case 1:
			x--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y--;
			break;
		case 4:
			y++;
		 	break;
		defualt:
			break;
	}
	if(x<=0 || x >= width || y <= 0 || y >= height)
	gameOver = 1;
	for(i=0;i<tails;i++)
	{
		if(x == tailX[i] && y == tailY[x])
		gameOver = 1;
	}
	if(x == fruitX && y == fruitY)
	{
		level3:
		fruitX=rand()%20;
		if(fruitX==0)
		goto level3;
		level4:
		fruitY=rand()%20;
		if(fruitY==0)
		goto level4;
		score += 10;
		tails++; 
	}
}
