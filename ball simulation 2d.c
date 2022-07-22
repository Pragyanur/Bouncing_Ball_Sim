#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

float cx=0,cy=0,LB=-11,RB=11,TB=4.5,BB=-4.5,speed=0.5,part=0.25;
/*
	cx is x coordinate of centre
	cy is y coordinate of centre
	LB is left bound, RB is right bound
	TB is top bound, BB is bottom bound
	speed is the magnitude by which the centre is updatetd
	part is the value by which iteration variable is updated
*/


void displaystyles(){									//function to display various available styles
	float i,j;
	//boundary and centre
	printf("CHOOSE A STYLE FROM THE FOLLOWING:\n\n1. centre and circumference painted\n");
	for(i=1.5;i>=-1.5;i-=part){
		for(j=LB/2;j<=RB/2;j+=part){
			if(sqrt(i*i+j*j)>=(1-0.08)&&sqrt(i*i+j*j)<=(1+0.08))
			printf("o ");
			else if(i>=(cy-0.1)&&i<=(cy+0.1)&&j>=(cx-0.1)&&j<=(cx+0.1))
			printf(". ");
			else printf("  ");
		}
		printf("\n");
	}
	for(i=LB;i<=RB;i+=part){
		printf("-");
	}
	printf("\n2. centre and outside of circumference painted\n");
	//outside boundary and centre
	for(i=1.5;i>=-1.5;i-=part){
		for(j=LB/2;j<=RB/2;j+=part){
			if(sqrt(i*i+j*j)>=(1-0.08))
			printf("o ");
			else if(i>=(cy-0.1)&&i<=(cy+0.1)&&j>=(cx-0.1)&&j<=(cx+0.1))
			printf(". ");
			else printf("  ");
		}
		printf("\n");
	}
	for(i=LB;i<=RB;i+=part){
		printf("-");
	}
	printf("\n3. inside of circumference painted\n");
	//inside boundary
	for(i=1.5;i>=-1.5;i-=part){
		for(j=LB/2;j<=RB/2;j+=part){
			if(sqrt(i*i+j*j)<=(1+0.08))
			printf("o ");
			else printf("  ");
		}
		printf("\n");
	}
	for(i=LB;i<=RB;i+=part){
		printf("-");
	}
	printf("\n");
}


void draw(float r, float cx, float cy, int a){				//function to draw the circle/ball in the console
	float i,j;
	if(a==1){
		for(i=TB;i>=BB;i-=part){
			for(j=LB;j<=RB;j+=part){
				if(sqrt((cy-i)*(cy-i)+(cx-j)*(cx-j))>=(r-0.08)&&sqrt((cy-i)*(cy-i)+(cx-j)*(cx-j))<=(r+0.08))
				printf("o ");
				else if(i>=(cy-0.1)&&i<=(cy+0.1)&&j>=(cx-0.1)&&j<=(cx+0.1))
				printf(". ");
				else printf("  ");
			}
		printf("\n");
		}
	}
	if(a==2){
		for(i=TB;i>=BB;i-=part){
			for(j=LB;j<=RB;j+=part){
				if(sqrt((cy-i)*(cy-i)+(cx-j)*(cx-j))>=(r-0.08))
				printf("o ");
				else if(i>=(cy-0.1)&&i<=(cy+0.1)&&j>=(cx-0.1)&&j<=(cx+0.1))
				printf(". ");
				else printf("  ");
			}
		printf("\n");
		}
	}
	if(a==3){
		for(i=TB;i>=BB;i-=part){
			for(j=LB;j<=RB;j+=part){
				if(sqrt((cy-i)*(cy-i)+(cx-j)*(cx-j))<=(r+0.08))
				printf("o ");
				else printf("  ");
			}
		printf("\n");
		}
	}
	
	for(i=LB;i<=RB;i+=part){
		printf("__");												//prints the ground
	}
	printf("\n");
}


void update(float r,float cx,float cy, int style){			//update the centre of the circle every iteration
	printf("\nLOAD SIMULATION?\n");
	system("pause");
	float y=cy,i;
	while(!kbhit()){		
		float flag=0;
		for(i=0;y>=(r+BB);i+=0.25){
			printf("\nPRESS ANY KEY TO EXIT THE SIMULATION\n\n");
			y=y-i*speed;
			draw(r,cx,y,style);
			flag+=0.25;
			system("cls");
		}
		for(i=flag;y<cy;i-=0.25){
			printf("\nPRESS ANY KEY TO EXIT THE SIMULATION\n\n");
			y=y+i*speed;
			draw(r,cx,y,style);
			system("cls");
		}
	}
}


int main(){																	//main function
	int choice;
	float radius;
s1: system("cls");
	printf("********************************************\n"
		   "**********BOUNCING BALL SIMULATION**********\n"
		   "********************************************\n"
		   "\nEnter radius of circle (0<floating number<3): ");
	scanf("%f",&radius);
	if(radius>=3||radius<=0){
		printf("\nWRONG INPUT");
		Sleep(2);
		goto s1;
	}
	printf("\nGENERATED BALL:\n");
	draw(radius,0,0,1);
	system("pause");
s2: system("cls");
	displaystyles();
	printf("\nCHOICE: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: update(radius,0,TB-radius-0.5,1);
				break;
		case 2: update(radius,0,TB-radius-0.5,2);
				break;
		case 3: update(radius,0,TB-radius-0.5,3);
				break;
		default: printf("\nWRONG INPUT\n");
				Sleep(2);
				goto s2;
				
	}
	printf("\nhave a great day!");
	return 0;
}
