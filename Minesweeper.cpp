#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;
#define N 8


int r,c;
bool flag = true;

int openCell(int gameMatrix[N][N], int flagMatrix[N][N], int ridx, int cidx);
int printEnd(int gameMatrix[N][N], int flagMatrix[N][N]);
int generateBombs(int gameMatrix[N][N], int no_bombs)
{
	int selected[64] = {0}, bombMatrix[no_bombs] = {0}, bomb_row[no_bombs], bomb_col[no_bombs];
	
	srand(time(0));
	for(int i=0; i<no_bombs; i++)
	{
		int number = rand()%64+1;
		while(selected[number])
		{
			number = rand()%64+1;
		}
		selected[number] = 1;
		bombMatrix[i] = number;
	}
	
	for(int i=0; i<no_bombs; i++)
	{
		bomb_row[i] = bombMatrix[i]/8; 
		bomb_col[i] = bombMatrix[i]%8; 
		gameMatrix[bomb_row[i]][bomb_col[i]] = 100;
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(gameMatrix[i][j] !=100)
			{
				gameMatrix[i][j] = 0;
			}
		}
	}
	
	for(int b=0; b<no_bombs; b++)
    {
        for(int i=bomb_row[b]-1; i<=bomb_row[b]+1; i++)
        {
            if(i>=0 && i<N )
			{
				for(int j=bomb_col[b]-1; j<=bomb_col[b]+1; j++)
	            {
	                if(j>=0 && j<N)
	                {
	                    if(gameMatrix[i][j]==100)
	                    {
	                    	continue;
	                    }
	                    else
	                    {
	                        gameMatrix[i][j]+=1;
	                    }
	                }
	            }
			}
    	}
    }
}

int printCheck(int gameMatrix[N][N])
{
	cout<<"\n\n";
	for(int i=0; i<N; i++)
    {
    	for(int j=0; j<N; j++)
    	{
    		cout<<gameMatrix[i][j]<<"\t";
    	}
    	cout<<"\n";
	}
}


int printMatrix(int gameMatrix[N][N], int flagMatrix[N][N])
{
	system("CLS");
	//printCheck(gameMatrix);
	for(int i=0; i<N; i++)
	{
		cout<<"-------------------------------------------------\n";
		cout<<"|";
		for(int j=0; j<N; j++)
		{
			if(i == r && j == c && flagMatrix[i][j] != 0)
			{
				cout<<" "<<"#";
				if(flagMatrix[i][j] == 2)
				{
					cout<<"\033[0;32mF\033[0m"<<"  ";
				}
				else if(flagMatrix[i][j] == 1)
				{
					cout<<gameMatrix[i][j]<<"  ";
				}
				cout<<"|";
			}
			else
			{
				if(i==r && j==c)
				{
					cout<<"  "<<"#"<<"  ";
				}
				else if(flagMatrix[i][j] == 0)
				{
					cout<<"  "<<" "<<"  ";
				}
				else if(flagMatrix[i][j] == 2)
				{
					cout<<"  "<<"\033[0;32mF\033[0m"<<"  ";
				}
				else if(flagMatrix[i][j] == 1)
				{
					 cout<<"  "<<gameMatrix[i][j]<<"  ";
				}
				cout<<"|";
			}
		}
		cout<<"\n";
	}
	cout<<"-------------------------------------------------";
}

int loop(int gameMatrix[N][N], int flagMatrix[N][N], int i, int j)
{
	for(int k=i-1; k<=i+1; k++)
	{
		if(k>=0 && k<N )
		{
			for(int l=j-1; l<=j+1; l++)
			{
				if(l>=0 && l<N)
				{
					if(k==i && l==j)
					{
						continue;
					}
					else
					{
						if(gameMatrix[k][l] == 0 && flagMatrix[k][l] == 0)
						{
							flagMatrix[k][l] = 1;
							loop(gameMatrix,flagMatrix,k,l);
						}
						else
						{
							flagMatrix[k][l] = openCell(gameMatrix, flagMatrix, k, l);
						}
					}
				}
			}	
		}
	}		
}

int action(int flagMatrix[N][N], int gameMatrix[N][N])
{
	cout<<"\nChoose O-open F-flag U-unFlag\n";
	char ch;
	ch = getch();
	switch(ch)
	{
		case 'o':
		case 'O': 	flagMatrix[r][c] = 1;
					
					if(gameMatrix[r][c] == 100)
					{
						printEnd(gameMatrix, flagMatrix);
						flag = false;
					}
					
					else if(gameMatrix[r][c] == 0)
					{
						loop(gameMatrix, flagMatrix, r, c);
					}
					break;//open
		case 'f':
		case 'F': if(flagMatrix[r][c] == 0)
					{
						flagMatrix[r][c] = 2;
					} 
					break;//flag
		case 'u':
		case 'U':  if(flagMatrix[r][c] == 2)
					{
						flagMatrix[r][c] = 0;
					} 
					break;//closed
	}
}

int printEnd(int gameMatrix[N][N], int flagMatrix[N][N])
{
	system("CLS");
	for(int i=0; i<8; i++)
	{
		cout<<"-------------------------------------------------\n";
		cout<<"|";
		for(int j=0; j<8; j++)
		{
			if(gameMatrix[i][j] == 100)
			{
				flagMatrix[i][j] = 1;
			}
			if(gameMatrix[i][j] != 100 && flagMatrix[i][j]==2)
			{
				flagMatrix[i][j] = 3;
			}
			
			if(flagMatrix[i][j] == 0)
			{
				cout<<"  "<<" "<<"  ";
			}
			else if(flagMatrix[i][j] == 2)
			{
				cout<<"  "<<"\033[0;32mF\033[0m"<<"  ";
			}
			else if(flagMatrix[i][j] == 3)
			{
				cout<<"  "<<"X"<<"  ";
			}
			else if(flagMatrix[i][j] == 1)
			{
				if(gameMatrix[i][j] == 100)
				{
					cout<<"  "<<"\033[0;31m*\033[0m"<<"  ";
				}
				else
				{
					cout<<"  "<<gameMatrix[i][j]<<"  ";
				}
			}
			cout<<"|";
		}
		cout<<"\n";
	}
	cout<<"-------------------------------------------------";
}

int openCell(int gameMatrix[N][N], int flagMatrix[N][N], int i, int j)
{
    if(i>=0 && i<N && j>=0 && j<N)
    {
        if(gameMatrix[i][j] == 100)
        {
        	return 0;
        }
        else
        {
          return 1;
      	}
    }
}

int countFunc(int flagMatrix[N][N], int gameMatrix[N][N])
{
	int a=0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(flagMatrix[i][j] == 1 )
			{
				a++;
			}
		}
	}
	return a;
}

int main()
{
	int level, no_bombs;
	int count;
	cout<<"1-> EASY  2-> MEDIUM  3-> HARD"<<endl;
	cin>>level;
	switch(level)
	{
		case 1: no_bombs=8;
				//N=8;
				break;
		case 2: no_bombs=12;
				//N=16;
				break;
		case 3: no_bombs=16;
				//N=24;
				break;;
			
	}
	int gameMatrix[N][N] = {0};
	int flagMatrix[N][N] = {0};
	
	generateBombs(gameMatrix, no_bombs);

	
	printMatrix(gameMatrix, flagMatrix);
	count = countFunc(flagMatrix, gameMatrix);
	int cells = N*N - no_bombs;
	while(count<cells)
	{
		char ch;
		cout<<"\nW-up\tA-left\t\tK-action(Open, Flag, Unflag)\nS-down\tD-right\n";
		ch = getch();
		switch(ch)
		{
			case 'w':
			case 'W':
						if(r != 0)
						{
							r=r-1; 
						}
						break;
			case 's':
			case 'S': 
						if(r != N-1)
						{
							r=r+1;
						}
						break;
			case 'a':
			case 'A': 
						if(c != 0)
						{
							c=c-1; 
						}
						break;
			case 'd':
			case 'D': 
						if(c != N-1)
						{
							c=c+1; 
						}
						break;
			case 'k':
			case 'K':
						count = action(flagMatrix, gameMatrix);
						break;
			default: break;
		}
		count = countFunc(flagMatrix, gameMatrix);
		if(count<cells && flag == true)
		{
			printMatrix(gameMatrix, flagMatrix);
		}
		else
		{ 
			break;
		}
	}
	if(flag == true)
	{
		printMatrix(gameMatrix, flagMatrix);
		cout<<"\n\n-----------------YOU WIN-----------------";
	}
	else
	{
		cout<<"\n\n-----------------YOU LOSE-----------------";
	}
}
