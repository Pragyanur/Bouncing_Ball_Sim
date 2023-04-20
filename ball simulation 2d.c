#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

float centerX = 0, centerY = 0, leftBound = -11, rightBound = 11, topBound = 4.5, bottomBound = -4.5, speed = 0.5, part = 0.25;
/*
	centerX is x coordinate of centre
	centerY is y coordinate of centre
	leftBound is left bound, rightBound is right bound
	topBound is top bound, bottomBound is bottom bound
	speed is the magnitude by which the centre is updatetd
	part is the value by which iteration variable is updated for justified visibility of the drawing
*/


//function to display various available styles
void displaystyles(){
	float i, j;
	
	//boundary and centre
	printf("CHOOSE A STYLE FROM THE FOLLOWING:\n\n1. centre and circumference painted\n");
	for(i = 1.5; i >= -1.5; i -=  part){
		for(j = leftBound / 2; j <= rightBound / 2; j += part){
			if(sqrt(i * i + j * j) >= (1 - 0.08) && sqrt(i * i + j * j) <= (1+0.08))
			printf("o ");
			else if(i >= (centerY - 0.1) && i <= (centerY + 0.1) && j >= (centerX - 0.1) && j <= (centerX + 0.1))
			printf(". ");
			else printf("  ");
		}
		printf("\n");
	}
	
	for(i = leftBound; i <= rightBound; i += part){
		printf("-");
	}
	
	printf("\n2. centre and outside of circumference painted\n");
	//outside boundary and centre
	for(i = 1.5; i >= -1.5; i -= part){
		for(j=leftBound/2;j<=rightBound/2;j+=part){
			if(sqrt(i*i+j*j)>=(1-0.08))
			printf("o ");
			else if(i>=(centerY-0.1)&&i<=(centerY+0.1)&&j>=(centerX-0.1)&&j<=(centerX+0.1))
			printf(". ");
			else printf("  ");
		}
		printf("\n");
	}
	
	for(i=leftBound;i<=rightBound;i+=part){
		printf("-");
	}
	
	printf("\n3. inside of circumference painted\n");
	//inside boundary
	for(i=1.5;i>=-1.5;i-=part){
		for(j=leftBound/2;j<=rightBound/2;j+=part){
			if(sqrt(i*i+j*j)<=(1+0.08))
			printf("o ");
			else printf("  ");
		}
		printf("\n");
	}
	
	for(i=leftBound;i<=rightBound;i+=part){
		printf("-");
	}
	printf("\n");
}


void draw(float r, float centerX, float centerY, int a){				//function to draw the circle/ball in the console
	float i,j;
	if(a==1){
		for(i=topBound;i>=bottomBound;i-=part){
			for(j=leftBound;j<=rightBound;j+=part){
				/*
				if the point(j,i) of the screen satisfies the equation the euclidean distance:
									radius = sqrt(a^2 + b^2)
				a = (centerX - j)
				b = (centerY - i)
				taking a range of freedom of the point for which we can make the point visible 
				(range of freedom as 0.16 = 0.08 + 0.08)
				*/
				if(sqrt((centerY-i)*(centerY-i)+(centerX-j)*(centerX-j))>=(r-0.08) && sqrt((centerY-i)*(centerY-i)+(centerX-j)*(centerX-j))<=(r+0.08))
				printf("o ");
				else if(i>=(centerY-0.1)&&i<=(centerY+0.1)&&j>=(centerX-0.1)&&j<=(centerX+0.1))
				printf(". ");
				else printf("  ");
			}
		printf("\n");
		}
	}
	if(a==2){
		for(i=topBound;i>=bottomBound;i-=part){
			for(j=leftBound;j<=rightBound;j+=part){
				if(sqrt((centerY-i)*(centerY-i)+(centerX-j)*(centerX-j))>=(r-0.08))
				printf("o ");
				else if(i>=(centerY-0.1)&&i<=(centerY+0.1)&&j>=(centerX-0.1)&&j<=(centerX+0.1))
				printf(". ");
				else printf("  ");
			}
		printf("\n");
		}
	}
	if(a==3){
		for(i=topBound;i>=bottomBound;i-=part){
			for(j=leftBound;j<=rightBound;j+=part){
				if(sqrt((centerY-i)*(centerY-i)+(centerX-j)*(centerX-j))<=(r+0.08))
				printf("o ");
				else printf("  ");
			}
		printf("\n");
		}
	}
	
	for(i=leftBound;i<=rightBound;i+=part){
		printf("__");																							//prints the ground
	}
	printf("\n");
}


void update(float r,float centerX,float centerY, int style){													//update the centre of the circle every iteration
	printf("\nLOAD SIMULATION?\n");
	system("pause");
	float y=centerY,i;
	while(!kbhit()){		
		float flag=0;
		for(i=0;y>=(r+bottomBound);i+=0.25){
			printf("\nPRESS ANY KEY TO EXIT THE SIMULATION\n\n");
			y -= i*speed;
			draw(r,centerX,y,style);
			flag+=0.25;
			system("cls");
		}
		for(i=flag;y<centerY;i-=0.25){
			printf("\nPRESS ANY KEY TO EXIT THE SIMULATION\n\n");
			y += i*speed;
			draw(r,centerX,y,style);
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
		   "\nEnter radius of circle (0 < radius(0.1f) < 3): ");
	scanf("%f",&radius);
	if(radius>=3||radius<=0){
		printf("\nWRONG INPUT");
		_sleep(2);
		goto s1;
	}
	printf("\nGENERATED BALL with radius %0.1f:\n", radius);
	draw(radius,0,0,1);
	system("pause");
s2: system("cls");
	displaystyles();
	printf("\nCHOICE: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: update(radius,0,topBound-radius-0.5,1);
				break;
		case 2: update(radius,0,topBound-radius-0.5,2);
				break;
		case 3: update(radius,0,topBound-radius-0.5,3);
				break;
		default: printf("\nWRONG INPUT\n");
				_sleep(2);
				goto s2;
				
	}
	printf("\nhave a great day!");
	return 0;
}
