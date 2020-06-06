#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char s[10]={'0','1','2','3','4','5','6','7','8','9'};
char comp[10]={'C','O','M','P','U','T','E','R'},p1[10],p2[10];
int move=0,pm,mm,cnt,i,mode;
int checkwin();
int computer();
void board();
int main()
{
	int player=1,i,c,choice;
	char mark;
	clrscr();
	printf("1.Player vs Computer\n2.Player vs Player\nEnter Your choice:");
	scanf("%d",&mode);
	switch(mode)
	{
		case 1:
		printf("Enter name of player\n");
		scanf("%s",&p2);
		do
		{
			board();
			player=(player%2)?1:2;
			if(player==2)
			{
				printf("%s, enter a pos: ", p2);
				scanf("%d", &choice);
			}
			else
				choice=computer();
			mark=(player==1)?'X':'O';
			if(choice==1&&s[1]=='1')
			{
				s[1]=mark;
				move++;
				pm=1;
			}
			else if(choice==2&&s[2]=='2')
			{
				s[2]=mark;
				move++;
				pm=2;
			}
			else if(choice==3&&s[3]=='3')
			{
				s[3]=mark;
				move++;
				pm=3;
			}
			else if(choice==4&&s[4]=='4')
			{
				s[4]=mark;
				move++;
				pm=4;
			}
			else if(choice==5&&s[5]=='5')
			{
				s[5]=mark;
				move++;
				pm=5;
			}
			else if(choice==6&&s[6]=='6')
			{
				s[6]=mark;
				move++;
				pm=6;
			}
			else if(choice==7&&s[7]=='7')
			{
				s[7]=mark;
				move++;
				pm=7;
			}
			else if(choice==8&&s[8]=='8')
			{
				s[8]=mark;
				move++;
				pm=8;
			}
			else if(choice==9&&s[9]=='9')
			{
				s[9]=mark;
				move++;
				pm=9;
			}
			else
			{
				printf("Invalid move ");
				player--;
				getch();
			}
			i=checkwin();
			player++;
		}while(i==- 1);
		board();
		if(i==1)
		{
			--player;
			if(player==1)
				printf("Player %s win ",comp);
			else
				printf("Player %s win ",p2);
		}
		else
			printf("Game draw");
		getch();
		return 0;
		case 2:
		printf("Enter the name of both the player\n");
		scanf("%s%s",p1,p2);
		do
		{
			board();
			player=(player%2)?1:2;
			if(player==1)
				printf("Player %s,Move: ",p1);
			else
				printf("Player %s,Move: ",p2);
			scanf("%d", &choice);
			mark=(player==1)?'X':'O';
			if(choice==1&&s[1]=='1')
				s[1]=mark;
			else if(choice==2&&s[2]=='2')
				s[2]=mark;
			else if(choice==3&&s[3]=='3')
				s[3]=mark;
			else if(choice==4&&s[4]=='4')
				s[4]=mark;
			else if(choice==5&&s[5]=='5')
				s[5]=mark;
			else if(choice==6&&s[6]=='6')
				s[6]=mark;
			else if(choice==7&&s[7]=='7')
				s[7]=mark;
			else if(choice==8&&s[8]=='8')
				s[8]=mark;
			else if(choice==9&&s[9]=='9')
				s[9]=mark;
			else
			{
				printf("Invalid move ");
				player--;
				getch();
			}
			i = checkwin();
			player++;
		}while(i==-1);
		board();
		if (i==1)
		{
			if(player==2)
				printf("%s win",p1);
			else
				printf("%s win ",p2);
		}
		else
			printf("Game draw");
		getch();
		return 0;
		default:printf("Invalid Choice\n");
		getch();
	}
	return 0;
}
int checkwin()
{
	if (s[1]==s[2]&&s[2]==s[3]) return 1;
	else if (s[4]==s[5]&&s[5]==s[6])return 1;
	else if (s[7]==s[8]&&s[8]==s[9])return 1;
	else if (s[1]==s[4]&&s[4]==s[7])return 1;
	else if (s[2]==s[5]&&s[5]==s[8])return 1;
	else if (s[3]==s[6]&&s[6]==s[9])return 1;
	else if (s[1]==s[5]&&s[5]==s[9])return 1;
	else if (s[3]==s[5]&&s[5]==s[7])return 1;
	else if (s[1]!='1'&&s[2]!='2'&&s[3]!='3'&&s[4]!='4'&&s[5]!='5'&&s[6]!='6'&&s[7]!='7'&&s[8]!='8'&&s[9]!='9')
		return 0;
	else
		return -1;
}
void board()
{
	clrscr();
	if(mode==1)
	{
	printf("Computer=X - %s=O\n\n\n",p2);
	}
	else
	printf("%s=X - %s=O\n\n\n",p1,p2);
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n",s[1],s[2],s[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n",s[4],s[5],s[6]);
	printf("_____|_____|_____\n");
	printf("     |     | \n");
	printf("  %c  |  %c  |  %c \n",s[7],s[8],s[9]);
	printf("     |     | \n\n");
}
int computer()
{
	int r,pr=0;
	if(s[1]==s[2]&&s[2]=='X'&&s[3]=='3')
	{
		pr++;
		return 3;
	}
	if(s[1]==s[3]&&s[3]=='X'&&s[2]=='2')
	{
		pr++;
		return 2;
	}
	if(s[2]==s[3]&&s[2]=='X'&&s[1]=='1')
	{
		pr++;
		return 1;
	}
	if(s[4]==s[5]&&s[5]=='X'&&s[6]=='6')
	{
		pr++;
		return 6;
	}
	if(s[5]==s[6]&&s[6]=='X'&&s[4]=='4')
	{
		pr++;
		return 4;
	}
	if(s[6]==s[4]&&s[6]=='X'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[7]==s[8]&&s[8]=='X'&&s[9]=='9')
	{
		pr++;
		return 9;
	}
	if(s[8]==s[9]&&s[8]=='X'&&s[7]=='7')
	{
		pr++;
		return 7;
	}
	if(s[9]==s[7]&&s[7]=='X'&&s[8]=='8')
	{
		pr++;
		return 8;
	}
	if(s[1]==s[4]&&s[4]=='X'&&s[7]=='7')
	{
		pr++;
		return 7;
	}
	if(s[4]==s[7]&&s[4]=='X'&&s[1]=='1')
	{
		pr++;
		return 1;
	}
	if(s[7]==s[1]&&s[1]=='X'&&s[4]=='4')
	{
		pr++;
		return 4;
	}
	if(s[2]==s[5]&&s[2]=='X'&&s[8]=='8')
	{
		pr++;
		return 8;
	}
	if(s[5]==s[8]&&s[8]=='X'&&s[2]=='2')
	{
		pr++;
		return 2;
	}
	if(s[8]==s[2]&&s[2]=='X'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[3]==s[5]&&s[5]=='X'&&s[7]=='7')
	{
		pr++;
		return 7;
	}
	if(s[5]==s[7]&&s[7]=='X'&&s[3]=='3')
	{
		pr++;
		return 3;
	}
	if(s[7]==s[3]&&s[3]=='X'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[3]==s[6]&&s[3]=='X'&&s[9]=='9')
	{
		pr++;
		return 9;
	}
	if(s[6]==s[9]&&s[9]=='X'&&s[3]=='3')
	{
		pr++;
		return 3;
	}
	if(s[9]==s[3]&&s[9]=='X'&&s[6]=='6')
	{
		pr++;
		return 6;
	}
	if(s[1]==s[5]&&s[5]=='X'&&s[9]=='9')
	{
		pr++;
		return 9;
	}
	if(s[5]==s[9]&&s[9]=='X'&&s[1]=='1')
	{
		pr++;
		return 1;
	}
	if(s[9]==s[1]&&s[9]=='X'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[1]==s[2]&&s[2]=='O'&&s[3]=='3')
	{
		pr++;
		return 3;
	}
	if(s[1]==s[3]&&s[3]=='O'&&s[2]=='2')
	{
		pr++;
		return 2;
	}
	if(s[2]==s[3]&&s[2]=='O'&&s[1]=='1')
	{
		pr++;
		return 1;
	}
	if(s[4]==s[5]&&s[5]=='O'&&s[6]=='6')
	{
		pr++;
		return 6;
	}
	if(s[5]==s[6]&&s[6]=='O'&&s[4]=='4')
	{
		pr++;
		return 4;
	}
	if(s[6]==s[4]&&s[6]=='O'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[7]==s[8]&&s[8]=='O'&&s[9]=='9')
	{
		pr++;
		return 9;
	}
	if(s[8]==s[9]&&s[8]=='O'&&s[7]=='7')
	{
		pr++;
		return 7;
	}
	if(s[9]==s[7]&&s[7]=='O'&&s[8]=='8')
	{
		pr++;
		return 8;
	}
	if(s[1]==s[4]&&s[4]=='O'&&s[7]=='7')
	{
		pr++;
		return 7;
	}
	if(s[4]==s[7]&&s[4]=='O'&&s[1]=='1')
	{
		pr++;
		return 1;
	}
	if(s[7]==s[1]&&s[1]=='O'&&s[4]=='4')
	{
		pr++;
		return 4;
	}
	if(s[2]==s[5]&&s[2]=='O'&&s[8]=='8')
	{
		pr++;
		return 8;
	}
	if(s[5]==s[8]&&s[8]=='O'&&s[2]=='2')
	{
		pr++;
		return 2;
	}
	if(s[8]==s[2]&&s[2]=='O'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[3]==s[5]&&s[5]=='O'&&s[7]=='7')
	{
		pr++;
		return 7;
	}
	if(s[5]==s[7]&&s[7]=='O'&&s[3]=='3')
	{
		pr++;
		return 3;
	}
	if(s[7]==s[3]&&s[3]=='O'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(s[3]==s[6]&&s[3]=='O'&&s[9]=='9')
	{
		pr++;
		return 9;
	}
	if(s[6]==s[9]&&s[9]=='O'&&s[3]=='3')
	{
		pr++;
		return 3;
	}
	if(s[9]==s[3]&&s[9]=='O'&&s[6]=='6')
	{
		pr++;
		return 6;
	}
	if(s[1]==s[5]&&s[5]=='O'&&s[9]=='9')
	{
		pr++;
		return 9;
	}
	if(s[5]==s[9]&&s[9]=='O'&&s[1]=='1')
	{
		pr++;
		return 1;
	}
	if(s[9]==s[1]&&s[9]=='O'&&s[5]=='5')
	{
		pr++;
		return 5;
	}
	if(pr==0)
	{
		if(move==0)
		{
			r=p2[0]+p2[1]+p2[2]+p2[3];
			r=r%5;
			if(r%2==0)
			{
				mm=5;
				pr++;
				return 5;
			}
			else
			{
				mm=1;
				pr++;
				return 1;
			}
		}
		if(move==2)
		{
			if(mm==5)
			{
				if(pm%2==0)
				{
					cnt=1;
					pr++;
					if(pm==2)
						return 7;
					if(pm==4)
						return 9;
					if(pm==6)
						return 1;
					if(pm==8)
						return 3;
				}
				else
				{
					pr++;
					if(pm==1)
					{
						cnt=2;
						return 9;
					}
					if(pm==3)
					{
						cnt=3;
						return 7;
					}
					if(pm==7)
					{
						cnt=4;
						return 3;
					}
					if(pm==9)
					{
						cnt=5;
						return 1;
					}
				}
			}
			else
			{
				if(pm==5)
				{
					pr++;
					cnt=6;
					return 9;
				}
				else if(pm%2!=0)
				{
					if(pm==9)
					{
						pr++;
						cnt=7;
						return 5;
					}
					else if(pm==3||pm==7)
					{
						pr++;
						cnt=8;
						return 9;
					}
				}
				else
				{
					pr++;
					cnt=9;
					return 5;
				}
			}
		}
		if(move==4)
		{
			if(cnt==2)
			{
				if(pm==6)
				return 7;
				if(pm==8)
				return 3;
			}
			if(cnt==3)
			{
				if(pm==4)
				return 9;
				if(pm==8)
				return 1;
			}
			if(cnt==4)
			{
				if(pm==2)
				return 4;
				if(pm==4)
				return 2;
			}
			if(cnt==5)
			{
				if(pm==6)
				return 2;
				if(pm==2)
				return 6;
			}
			if(cnt==7)
			{
				if(pm==4)
				{
					pr++;
					return 3;
				}
				if(pm==2)
				{
					pr++;
					return 7;
				}
			}
			if(cnt==9)
			{
				pr++;
				if(s[2]=='O')
					return 7;
				if(s[4]=='O')
					return 3;
			}
		}
	}
	if(pr==0)
	{
		if(s[1]=='1')
			return 1;
		if(s[2]=='2')
			return 2;
		if(s[3]=='3')
			return 3;
		if(s[4]=='4')
			return 4;
		if(s[5]=='5')
			return 5;
		if(s[6]=='6')
			return 6;
		if(s[7]=='7')
			return 7;
		if(s[8]=='8')
			return 8;
		if(s[9]=='9')
			return 9;
	}
	return 0;
}