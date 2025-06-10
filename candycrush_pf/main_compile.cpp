#include <graphics.h>
#include<iostream>
#include<stdlib.h>                           //library for srand & rand function
#include<time.h>

using namespace std;

int Level=0,Moves=2,yellcrush=60,hint=0;

void cgene(int X, int Y)  //Generates coordinates and fill colours in boxes
{
	
	int XX=12,YY=12,check=0;
	for(int m=0;m<10;m++)
    {
    	XX=12;
		for(int n=0;n<10;n++)
		{
			if (m==X && n==Y)
			{
				if (hint==1)
				{
					setfillstyle(SOLID_FILL,BROWN);
					floodfill(XX,YY,DARKGRAY);
					check=1;
					break;
				}
				else
				{
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(XX,YY,DARKGRAY);
					check=1;
					break;
				}
			}
			
			XX+=60;
		}
		if (check==1)
		break;
		YY+=60;
	}
}



int Lsearch(int array[][10],int &countbreak)   //Searches array for and matched candies and destroys them
{
	countbreak=0;
	int X,Y;
	for(int i=0;i<10;i++)
    {
		for(int j=0;j<8;j++)
		{
			if(array[i][j]==array[i][j+1]&&array[i][j]==array[i][j+2]&&array[i][j]!=6&&array[i][j]!=7&&array[i][j]!=8&&array[i][j]!=9)
		    {
		    	if(array[i][j]==array[i][j+1]&&array[i][j]==array[i][j+2]&&array[i][j]!=6&&array[i][j]!=9&&array[i][j]==array[i][j+3]&&j<7&&array[i][j]!=7&&array[i][j]!=8)
		       {
		       	if(array[i][j]==array[i][j+1]&&array[i][j]==array[i][j+2]&&array[i][j]!=9&&array[i][j]==array[i][j+3]&&array[i][j]!=6&&array[i][j]==array[i][j+4]&&j<6&&array[i][j]!=7&&array[i][j]!=8)
		    	{
		    		if (array[i][j]==2)
		    		yellcrush-=5;
		    		
		    		array[i][j]=6;
		         	array[i][j+1]=6;
		    	    array[i][j+2]=8;
		    	    array[i][j+3]=6;
		        	array[i][j+4]=6;
		        	cgene(i,j+2);
		        	j=j+5;
		        	countbreak++;
				}
				else
				{
					if (array[i][j]==2)
		    		yellcrush-=4;
				    array[i][j]=6;
		    	    array[i][j+1]=6;
		    	    array[i][j+2]=7;
		    	    array[i][j+3]=6;
		        	cgene(i,j+2);
		    	    j=j+4;
					countbreak++;
		    	}
		       }  
			    else
			    {
			    	if (array[i][j]==2)
		    		yellcrush-=3;
			        array[i][j]=6;
		    	    array[i][j+1]=6;
		         	array[i][j+2]=6;
		         	j=j+3;
					countbreak++;
		         }
	    	}
	   }
   }
   
for(int j=0;j<10;j++)
    {
		for(int i=0;i<8;i++)
		{
			if(array[i][j]==array[i+1][j]&&array[i][j]==array[i+2][j]&&array[i][j]!=6&&array[i][j]!=7&&array[i][j]!=8&&array[i][j]!=9)
		    {
		    	if(array[i][j]==array[i+1][j]&&array[i][j]==array[i+2][j]&&array[i][j]!=6&&array[i][j]!=9&&array[i][j]==array[i+3][j]&&i<7&&array[i][j]!=7&&array[i][j]!=8)
		       {
		       	if(array[i][j]==array[i+1][j]&&array[i][j]==array[i+2][j]&&array[i][j]!=9&&array[i][j]!=6&&array[i][j]==array[i+3][j]&&array[i][j]==array[i+4][j]&&i<6&&array[i][j]!=7&&array[i][j]!=8)
		    	{
		    		if (array[i][j]==2)
		    		yellcrush-=5;
		    		array[i][j]=6;
		         	array[i+1][j]=6;
		    	    array[i+2][j]=8;
		    	    array[i+3][j]=6;
		        	array[i+4][j]=6;
		        	cgene(i+2,j);
		        	i=i+5;
		        	countbreak++;
				}
				else
				{
					if (array[i][j]==2)
		    		yellcrush-=4;
				    array[i][j]=6;
		    	    array[i+1][j]=6;
		    	    array[i+2][j]=7;
		    	    array[i+3][j]=6;
		        	cgene(i+2,j);
		    	    i=i+4;
		    	    countbreak++;
		    	}
		       }  
			    else
			    {
			    	if (array[i][j]==2)
		    		yellcrush-=3;
			        array[i][j]=6;
		    	    array[i+1][j]=6;
		         	array[i+2][j]=6;
		         	i=i+3;
		         	countbreak++;
		         }
	    	}
	   }
   }
   return array[10][10];
}

int Hint (int a9[][10])  //Gives hint when asked by user
{
	
	hint=1;
	int count=0,CHECK=0;
	for(int i=0;i<10;i++)
    {
    	count=0;
		for(int j=0;j<7;j++)
		{
			count=0;
			if (a9[i][j]==a9[i][j+1])
			count++;
			if (a9[i][j]==a9[i][j+2])
			count++;
			if (a9[i][j]==a9[i][j+3])
			count++;
			if  (count==2)
			{
				cgene(i,j);
				
				cgene(i,j+1);
				
				cgene(i,j+2);
				
				cgene(i,j+3);
				
				CHECK=1;
				break;
			}
			else if (i!=0 && i!=9 && j!=0 && j+1!=9)
			{
				if (a9[i][j]==a9[i][j+1])
				{
					if (a9[i][j]==a9[i-1][j-1])
					{
						cgene(i,j);
						cgene(i,j+1);
						cgene(i-1,j-1);
						CHECK=1;
						break;
					}
					if (a9[i][j]==a9[i+1][j-1])
					{
						cgene(i,j);
						cgene(i,j+1);
						cgene(i+1,j-1);
						CHECK=1;
						break;
					}
					if (a9[i][j]==a9[i-1][j+2])
					{
						cgene(i,j);
						cgene(i,j+1);
						cgene(i-1,j+2);
						CHECK=1;
						break;
					}
					if (a9[i][j]==a9[i+1][j+2])
					{
						cgene(i,j);
						cgene(i,j+1);
						cgene(i+1,j+2);
						CHECK=1;
						break;
					}
				}
				
				
			}
			
		}
		if (CHECK==1)
		break;
	}
	
	if (CHECK!=1)
	{
		count=0;
		for(int j=0;j<10;j++)
	    {
	    	count=0;
			for(int i=0;i<7;i++)
			{
				count=0;
				if (a9[i][j]==a9[i+1][j])
				count++;
				if (a9[i][j]==a9[i+2][j])
				count++;
				if (a9[i][j]==a9[i+3][j])
				count++;
				if  (count==2)
				{
					cgene(i,j);
				
					cgene(i,j+1);
					
					cgene(i,j+2);
					
					cgene(i,j+3);
					
					CHECK=1;
					break;
				}
				
				else if (i!=0 && i+1!=9 && j!=0 && j!=9)
				{
					if (a9[i][j]==a9[i+1][j])
					{
						if (a9[i][j]==a9[i-1][j-1])
						{
							cgene(i,j);
							cgene(i+1,j);
							cgene(i-1,j-1);
							CHECK=1;
							break;
						}
						if (a9[i][j]==a9[i-1][j+1])
						{
							cgene(i,j);
							cgene(i+1,j);
							cgene(i-1,j+1);
							CHECK=1;
							break;
						}
						if (a9[i][j]==a9[i+2][j-1])
						{
							cgene(i,j);
							cgene(i+1,j);
							cgene(i+2,j-1);
							CHECK=1;
							break;
						}
						if (a9[i][j]==a9[i+2][j+1])
						{
							cgene(i,j);
							cgene(i+1,j);
							cgene(i+2,j+1);
							CHECK=1;
							break;
						}
					}
				}
				
			}
			if (CHECK==1)
			break;
		}
	}
	hint=0;
	return a9[10][10];
}

void Frame()   //  Displays the frame of game i.e. squares
{
	int j=10,x=70,i=10,y=70,c=20;
	
	for(int m=0 ; m<10 ; m++)
	{
	i=10;
	x=70;
	for(int n=0 ; n<10 ; n++)
	{
		setcolor(DARKGRAY);
		rectangle(i,j,x,y);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(i+30,j+30,DARKGRAY);
		
		i=i+60;
		x=x+60;
		
	}
	j=j+60;
	y=y+60;
}
	
}
void Candies(int a[][10])   //Displays text and candies of different colours and shapes
{
	char move[16];
	
	settextstyle(3,0,3);
	sprintf(move, " Moves Left : %d  ", Moves);
	
	outtextxy (620,50,move);
	
	if (Level!=1)
	{
		char yellow[30];
		settextstyle(3,0,3);
		sprintf(yellow, " Remaining Yellow Candies : %d  ",yellcrush );
		
		outtextxy (620,80,yellow);
	}
	
	if (Level==1)
	{
		settextstyle(3,0,3);
		outtextxy (620,110,"To win the game bring the triangle");
		outtextxy (620,140,"candies to the last row !");
		outtextxy (620,200,"Enjoy the Game !");
		outtextxy (620,260,"Good Luck!");
		outtextxy (620,400,"For Hint press Spacebar!");
	}
	
	if (Level==2)
	{
		settextstyle(3,0,3);
		outtextxy (620,140,"To win the game crush 60 yellow");
		outtextxy (620,170,"candies !");
		outtextxy (620,230,"Enjoy the Game !");
		outtextxy (620,290,"Good Luck!");
		outtextxy (620,400,"For Hint press Spacebar!");
	}
	
	if (Level==3)
	{
		settextstyle(3,0,3);
		outtextxy (620,140,"To win the game bring the triangle");
		outtextxy (620,170,"candies to last row and crush 60");
		outtextxy (620,200,"yellow candies");
		outtextxy (620,260,"Enjoy the Game !");
		outtextxy (620,320,"Good Luck!");
		outtextxy (620,400,"For Hint press Spacebar!");
	}
	
	int xc=40,yc=40;
	for (int m=0 ; m<10 ; m++)
	{
		xc=40;
		for (int n=0 ; n<10 ; n++)
		{
			if (a[m][n]==0){
			setcolor(LIGHTGRAY);
			line(xc,yc-20,xc-20,yc);
			line(xc-20,yc,xc,yc+20);
			line(xc,yc+20,xc+20,yc);
			line(xc+20,yc,xc,yc-20);
			setfillstyle(SOLID_FILL,RED);
			floodfill(xc,yc,LIGHTGRAY);}
			else if (a[m][n]==1)
			{
			setcolor(LIGHTGRAY);
			rectangle (xc-17,yc-17,xc+17,yc+17);
			setfillstyle(SOLID_FILL,GREEN);
		  	floodfill(xc,yc,LIGHTGRAY);
	}
			else if (a[m][n]==2)
			{
			setcolor(LIGHTGRAY);
			ellipse (xc,yc,0,360,13,20);
			setfillstyle(SOLID_FILL,YELLOW);
			floodfill(xc,yc,LIGHTGRAY);
	}
			else if (a[m][n]==3)
			{
			setcolor(LIGHTGRAY);
			ellipse (xc,yc+20,0,180,20,40);
			line(xc-20,yc+19,xc+20,yc+19);
			setfillstyle(SOLID_FILL,BLUE);
			floodfill(xc,yc,LIGHTGRAY);
	}
			else if (a[m][n]==4)
			{
			setcolor(LIGHTGRAY);
			circle (xc,yc,20);
			setfillstyle(SOLID_FILL,MAGENTA);
			floodfill(xc,yc,LIGHTGRAY);
			}
			
			else if (a[m][n]==6)
			{
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(xc,yc,DARKGRAY);
			}	
			
			else if (a[m][n]==7)
			{
				
			setcolor(LIGHTGRAY);
			line(xc,yc-20,xc-20,yc);
			line(xc-20,yc,xc,yc+20);
			line(xc,yc+20,xc+20,yc);
			line(xc+20,yc,xc,yc-20);
			setfillstyle(SLASH_FILL,RED);
			floodfill(xc,yc,LIGHTGRAY);
			}
			
			else if (a[m][n]==8)
			{
			setcolor(LIGHTGRAY);
			circle (xc,yc,20);
			setfillstyle(CLOSE_DOT_FILL,RED);
			floodfill(xc,yc,LIGHTGRAY);
			}
			
			else if (a[m][n]==9)
			{
				
			setcolor(LIGHTGRAY);
			line(xc,yc-20,xc-20,yc+20);
			line(xc-20,yc+20,xc+20,yc+20);
			line(xc+20,yc+20,xc,yc-20);
			setfillstyle(XHATCH_FILL,MAGENTA);
			floodfill(xc,yc,LIGHTGRAY);
			}
			
			xc+=60;
		}	
		yc+=60;
	}
}

int Drop(int a1[][10])  //Drops candies in free spacing
{
	int X,Y;
	
	for (int j=0 ; j<10 ; j++)
	{
		for (int i=9 ; i>=1 ; i--)
		{
			if (a1[i][j]==6)
			{
			
				while (i>=1)
				{
					swap(a1[i][j],a1[i-1][j]);
					cgene(i,j);
					cgene(i-1,j);
					Candies(a1);
					i--;
				}
			}
		}
	}

	return a1[10][10];	
}

int cand5ies(int a4[][10], int i, int j, int x, int y)
{
	if ((a4[i][j]==7 && a4[x][y]==8)||(a4[i][j]==8 && a4[x][y]==7))  //Feature of swapping bomb with striped candy
	{
		for (int limit=0 ; limit<6 ; limit++)
		{
			int s=rand()%10;
			int t=rand()%10;
			if ((s==i&&t==j)||(s==x&&t==y)||(a4[s][t]==7)||(a4[s][t]==8)||(a4[s][t]==9))
			{
				limit--;
			}
			else
			{
				if (a4[s][t]==2)
				yellcrush--;
				a4[s][t]=7;
				cgene(s,t);
			}
		}
		a4[i][j]=6;
		a4[x][y]=6;
		Moves--;
	}
	
	else if (a4[i][j]==8 && a4[x][y]==8) //Feature of swapping two bombs
	{
		for(int s=0;s<10;s++)
	    {
			for(int t=0;t<10;t++)
			{
				if (a4[s][t]!=9)
				{
					if (a4[s][t]==2)
					yellcrush--;
					a4[s][t]=6;
				}
			}
		}
		Moves--;
	}
	else if (a4[i][j]==8)  //Feature of swapping bomb with a candy
	{
		for(int s=0;s<10;s++)
	    {
			for(int t=0;t<10;t++)
			{
				if (a4[x][y]==a4[s][t] && (s!=x || t!=y))
				{
					if (a4[s][t]==2)
					yellcrush--;
					a4[s][t]=6;
				}
			}
		}
		if (a4[i][j]==2)
		yellcrush--;
		if (a4[x][y]==2)
		yellcrush--;
		a4[i][j]=6;
		a4[x][y]=6;
		Moves--;
	}
	
	else if (a4[x][y]==8)   //Feature of swapping bomb with a candy
	{
		for(int s=0;s<10;s++)
	    {
			for(int t=0;t<10;t++)
			{
				if (a4[i][j]==a4[s][t] && (s!=i || t!=j))
				{
					if (a4[s][t]==2)
					yellcrush--;
					a4[s][t]=6;
				}
			}
		}
		if (a4[i][j]==2)
		yellcrush--;
		if (a4[x][y]==2)
		yellcrush--;
		a4[i][j]=6;
		a4[x][y]=6;
		Moves--;
	}
	return a4[10][10];
}

int cand4ies(int a3[][10], int i, int j, int x, int y)  //Feature of swapping striped candy with a candy
{
	if ((a3[i][j]==7 || a3[x][y]==7) && (a3[i][j]!=8 && a3[x][y]!=8))
	{
		if (a3[i][j]==7 && a3[x][y]==7)
		{
				for (int a=0; a<10 ; a++)
			{
				if (a3[i][a]==7 && a!=j && a!=y)
				{
					for (int b=0; b<10 ; b++)
					{
						if (a3[b][a]==7 && b!=i)
						{
							cand4ies(a3,b,a,b,a+1);
						}
						if (a3[b][a]!=8 && a3[b][a]!=9)
						{
							if (a3[b][a]==2)
							yellcrush--;
							a3[b][a]=6;
						}	
					}	
				}
				if (a3[i][a]!=8 && a3[i][a]!=9)
				{
					if (a3[i][a]==2)
					yellcrush--;
					a3[i][a]=6;
				}
			}
			for (int a=0; a<10 ; a++)
			{
				if (a3[a][y]==7 && a!=i && a!=x)
				{
					for (int b=0; b<10 ; b++)
					{
						if (a3[a][b]==7 && b!=y)
						{
							cand4ies(a3,a,b,a+1,b);
						}
						if (a3[a][b]!=8 && a3[a][b]!=9)
						{
							if (a3[a][b]==2)
							yellcrush--;
							a3[a][b]=6;
						}
					}	
				}
				if (a3[a][y]!=8 && a3[a][y]!=9)
				{
					if (a3[a][y]==2)
					yellcrush--;
					a3[a][y]=6;
				}
			}
		}
		
		if (i==x)
		{
			for (int a=0; a<10 ; a++)
			{
				if (a3[i][a]==7 && a!=j && a!=y)
				{
					for (int b=0; b<10 ; b++)
					{
						if (a3[b][a]==7 && b!=i)
						{
							cand4ies(a3,b,a,b,a+1);
						}
						if (a3[b][a]!=8 && a3[b][a]!=9)
						{
							if (a3[b][a]==2)
							yellcrush--;
							a3[b][a]=6;
						}	
					}	
				}
				if (a3[i][a]!=8 && a3[i][a]!=9)
				{
					if (a3[i][a]==2)
					yellcrush--;
					a3[i][a]=6;
				}
			}
		}
		
		if (j==y)
		{
			for (int a=0; a<10 ; a++)
			{
				if (a3[a][y]==7 && a!=i && a!=x)
				{
					for (int b=0; b<10 ; b++)
					{
						if (a3[a][b]==7 && b!=y)
						{
							cand4ies(a3,a,b,a+1,b);
						}
						if (a3[a][b]!=8 && a3[a][b]!=9)
						{
							if (a3[a][b]==2)
							yellcrush--;
							a3[a][b]=6;
						}
					}	
				}
				if (a3[a][y]!=8 && a3[a][y]!=9)
				{
					if (a3[a][y]==2)
					yellcrush--;
					a3[a][y]=6;
				}
			}
		}
		Moves--;
	}
	return a3[10][10];
}

int Dropper(int a2[][10], int countbreak) //Drops candies and check for any matches and continues dropping till no match available
{
	
	int stopper=0;
	while (stopper==0){
	
	while (stopper==0)
		{
		label:	stopper=1;
			delay(500);
			Drop(a2);
			for(int j=0;j<10;j++)
		{
			if (a2[0][j]==6)
			{
				a2[0][j]=rand()%5;
			}
		}
			Candies(a2);
			for(int i=1;i<10;i++)
		    {
				for(int j=0;j<10;j++)
				{
					if (a2[i][j]==6)
					{
						if (a2[i-1][j]!=6)
						{
							stopper=0;
						}
					}
				}
			}		
		}
		Lsearch(a2,countbreak);
		Candies(a2);
		if (countbreak!=0)
		{
			goto label;
		}
	}
		return a2[10][10];
}

int game()  //Main function which runs game

{
	
	int countbreak=0;
	initwindow(1000,4000);
	
	Frame();
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(700,12,DARKGRAY);
	int arr[10][10];
	srand(time(NULL));
	for(int i=0;i<10;i++)  //Storing values in array and avoiding matches at start
	{
		int randomnum,repeat=9,count=0;
		for(int j=0;j<10;j++)
		{
			randomnum=rand()%5;
			if (i==0)
			{
				if (randomnum==repeat)
				{	
					count++;
				}
				else if (randomnum!=repeat){
					count=0;
				}
				if (count<=1)	
				{
					arr[i][j]=randomnum;
					repeat=randomnum;
				}
				else
				{
			 		j=j-1;
			    }
		  	}
			else
			{
				if (randomnum==repeat)
				{
					count++;
				}
				else {
					count=0;
				}
				if ((count<2) && (randomnum!=arr[i-1][j]) && (arr[i][j-2] !=randomnum))	
				{
					arr[i][j]=randomnum;
					repeat=randomnum;
				}
				else
				{
					j =j-1;
				}
				 
				
			} 
		
	}
}
	if (Level==1)
	{
		arr[0][2]=9;
		arr[0][7]=9;
	}
	
	if (Level==3)
	{
		arr[0][0]=9;
		arr[0][9]=9;
		arr[0][4]=9;
	}
	
	Candies(arr);
	int xco=12,yco=12,row=0,col=0;
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	floodfill(xco,yco,DARKGRAY);
	Candies(arr);
	if ((GetAsyncKeyState(VK_RETURN) & 0x8000) != 0)
		{
			delay(500);
		}
	
	
	while (1)  //Using keys to run game
	{
		if ((GetAsyncKeyState(VK_RETURN) & 0x8000) != 0)
		{
		delay(200);
		setfillstyle(SOLID_FILL,LIGHTRED);
		floodfill(xco,yco,DARKGRAY);
		Candies(arr);
		while(1){
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0  && col<9)
		{
		swap(arr[row][col],arr[row][col+1]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco+60,yco,DARKGRAY);
		Candies(arr);
		delay(500);
		cand4ies(arr, row, col, row, col+1);
		if (arr[row][col]!=9 && arr[row][col+1]!=9)
		cand5ies(arr, row, col, row, col+1);
		Lsearch(arr,countbreak);
		if (countbreak==0)
		{
		swap(arr[row][col],arr[row][col+1]);
		setfillstyle(SOLID_FILL,WHITE);
	    floodfill(xco,yco,DARKGRAY);
		floodfill(xco+60,yco,DARKGRAY);
		}
		else
		Moves--;
		Candies(arr);
		Dropper(arr,countbreak);
		delay(500);
		break;
		}
		
		else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0 && col>0)
		{
		swap(arr[row][col],arr[row][col-1]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco-60,yco,DARKGRAY);
		Candies(arr);
		delay(500);
		cand4ies(arr, row, col, row, col-1);
		if (arr[row][col]!=9 && arr[row][col-1]!=9)
		cand5ies(arr, row, col, row, col-1);
		Lsearch(arr,countbreak);
		if (countbreak==0)
		{
		swap(arr[row][col],arr[row][col-1]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco-60,yco,DARKGRAY);
		}
		else
		Moves--;
		Candies(arr);
		Dropper(arr,countbreak);
		delay(500);
		break;
		}
		
		else if ((GetAsyncKeyState(VK_UP) & 0x8000) != 0 && row>0)
		{
		swap(arr[row][col],arr[row-1][col]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco,yco-60,DARKGRAY);
		Candies(arr);
		delay(500);
		cand4ies(arr, row, col, row-1, col);
		if (arr[row][col]!=9 && arr[row-1][col]!=9)
		cand5ies(arr, row, col, row-1, col);
		Lsearch(arr,countbreak);
		if (countbreak==0)
		{
		swap(arr[row][col],arr[row-1][col]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco,yco-60,DARKGRAY);
		}
		else
		Moves--;
		Candies(arr);
		Dropper(arr,countbreak);
		delay(500);
		break;
		}
		
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0 && row<9)
		{
		swap(arr[row][col],arr[row+1][col]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco,yco+60,DARKGRAY);
		Candies(arr);
		delay(500);
		cand4ies(arr, row, col, row+1, col);
		if (arr[row][col]!=9 && arr[row+1][col]!=9)
		cand5ies(arr, row, col, row+1, col);
		Lsearch(arr,countbreak);
		if (countbreak==0)
	    {
		swap(arr[row][col],arr[row+1][col]);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		floodfill(xco,yco+60,DARKGRAY);
		}
		else
		Moves--;
		Candies(arr);
		Dropper(arr,countbreak);
		delay(500);
		break;
		}
			
	
	
}
		}
		
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) != 0)
		{
			
			Hint(arr);
			Candies(arr);
			delay(2000);
			Frame();
			Candies(arr);
		}
		
		
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) != 0  && xco<500)
		{
	    
		delay(200);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		
		xco+=60;
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		floodfill(xco,yco,DARKGRAY);
		Candies(arr);
		col++;}
		
		else if ((GetAsyncKeyState(VK_LEFT) & 0x8000) != 0 && xco>15)
		{
		
		
		delay(200);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		
		xco-=60;
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		floodfill(xco,yco,DARKGRAY);
		Candies(arr);
		col--;}
		
		else if ((GetAsyncKeyState(VK_UP) & 0x8000) != 0 && yco>15)
		{
		
	
		delay(200);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		yco-=60;
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		floodfill(xco,yco,DARKGRAY);
		Candies(arr);
		row--;}
		
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) != 0 && yco<500)
		{
		
		delay(200);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(xco,yco,DARKGRAY);
		yco+=60;
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		floodfill(xco,yco,DARKGRAY);
		Candies(arr);
		row++;}
		
		int lc=0;
		if (Level==1)  //Levels win or lost check
		{
			for (int i=0 ; i<10 ; i++)
			{
				for (int j=0 ;j<10 ; j++)
				{
					if (arr[i][j]==9 && i==9)
					lc++;
				}
			}
			if (lc==2)
			{
				cleardevice();
				settextstyle(3,0,3);
				outtextxy (350,350,"CONGRATS!   YOU WON");
				delay(2000);
				
				return 0;
			}
			
			if (lc!=2 && Moves==0)
			{
				cleardevice();
				settextstyle(3,0,3);
				outtextxy (350,350,"ALAS!   YOU LOST");
				delay(2000);
				
				return 0;		
			}
		}
		
		if (Level==2)
		{
			if (yellcrush<=0)
			{
				cleardevice();
				settextstyle(3,0,3);
				outtextxy (350,350,"CONGRATS!   YOU WON");
				delay(2000);
				
				return 0;
			}
			
			if (yellcrush>0 && Moves==0)
			{
				cleardevice();
				settextstyle(3,0,3);
				outtextxy (350,350,"ALAS!   YOU LOST");
				delay(2000);
				
				return 0;		
			}
			
		}
		
		if (Level==3)
		{
			for (int i=0 ; i<10 ; i++)
			{
				for (int j=0 ;j<10 ; j++)
				{
					if (arr[i][j]==9 && i==9)
					lc++;
				}
			}
			
			if (lc==3 && yellcrush<=0)
			{
				cleardevice();
				settextstyle(3,0,3);
				outtextxy (350,350,"CONGRATS!   YOU WON");
				delay(2000);
				
				return 0;
			}
			
			
			if ((yellcrush>0 || lc<3) && Moves==0)
			{
				cleardevice();
				settextstyle(3,0,3);
				outtextxy (350,350,"ALAS!   YOU LOST");
				delay(2000);
				
				return 0;
			}
			
}
}
getch();

}

int main()
{   //Instructions
	cout<<"Game instructions:\n\n *Use arrow keys to move  i.e. (RIGHT ARROW KEY) to move right, (LEFT ARROW KEY) to move left,(UP AROOW KEY) to move upward, (DOWN ARROW KEY) to move downward.\n";     
	cout<<"*If you want to select a particular candy, then simply press (ENTER) and then your candy will be selected and then if you want to move the selected candies then use the same arrow keys.\n";
	cout<<"*If 3 similar candies are being matched then the 3 candies will be destroyed\n *If 4 similar candies will be matched then it will result in a new candy i.e.(SPECIAL RHOMBUS STRIPED CANDY)\n";
	cout<<"*If 5 similar candies are being matched then it will result in a bomb candy i.e. (SPECIAL DOTTED BOMB)\n";
	cout<<"*If you swap a special rhombus candy with a candy in a row then the row will be cleared and same if you swap the special rhombus candy with a candy in a column then that column will be cleared.\n";
	cout<<"*If you swap the dotted candy with a candy then all the similar shaped candies in the window will be cleared.\n";
	cout<<"*If you swap two special rhombus candies then both the row and column will be cleared.\n";
	cout<<"*If you swap two dotted bombs then the entire window will be cleared.\n";
	cout<<"* If you swap a special rhombus candy with a special dotted bomb then it will result in the formation of 6 special rhombus candies at random positions.\n\n\n";
	cout<<"Level instructions:\n\n";
	cout<<"*If you choose an easy level then you have to take the two colored triangles down to the end of the window in the given moves.\n";
	cout<<"*If you choose medium level then you have to destroy the sixty yellow colored candies in the given moves.\n";
	cout<<"*If you choose a hard level then you have to take the three colored triangles down and also have to destroy the sixty yellow colored candies in the given moves\n\n";
	cout<<"*To get hint press (space bar)"<<endl<<endl;
	char level,intent;
	int tried=1;
	do
	{
		Moves=25;
		yellcrush=60;
		tried=1;
		while (tried>0)
		{
			cout << endl <<"Which level do you want to play; enter:"<< endl;
			cout << "E for Easy Level\nM for Medium Level\nH for Hard Level\nLevel: ";
			cin >> level;
			Sleep(1000);
			tried=0;
			if (level=='E'||level=='e')
				Level=1;
			else if (level=='M'||level=='m')
				Level=2;
			else if (level=='H'||level=='h')
				Level=3;
			else
			{
				cout << "\nInvalid Entry\nPlease Enter Again !" << endl;
				tried++;
			}
		}
		
		game();
		closegraph();
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "Do you want to play again (Y/N) : ";
		cin >> intent;	
	}while (intent=='y'||intent=='Y');  //Checking if user wants to play again	
}
