/************************************************************* HEADER FILES *****************************************************************/

#include<stdio.h>
#include"head.h"
#include<string.h>
#include<stdlib.h>
#include<conio.h>

/********************************************************* MAIN FUNCTION ********************************************************************/

int main()
{
	int choice,dummy;	
	char ans;
	do
	{
		printf("\n=*=*=*=*=*=*=*=*=* PHONEBOOK *=*=*=*=*=*=*=*=*=*");

		printf("\n\n 1.INSERT RECORD \n 2.DISPLAY RCEORD \n 3.SEARCH RECORD \n 4.MODIFY RECORD \n 5.DELETE PREVIOUS ENTERED RECORD \n 6.SORT RECORDS \n 7.EXIT  ");
		printf("\n\n Enter any one of the options : ");
		scanf("%d",&choice);
		
		//clears screen
		system("cls");

		switch(choice)
		{
			case 1: enter_data();
			break;
			
			case 2: display_record();
			break;
			
			case 3: search();
			break;
			
			case 4: modify_data();
			break;

			case 5: delete_record();
			break;
			
			case 6: sort_record();
			break;
				
			case 7: exit(0);
			break;
			
			default: printf("\n Enter choice between 1 to 7 ");
		}
		
	printf("\n Do you want to choose any other option on main screen ? (y/n): ");
	scanf("%d",&dummy);
	scanf("%c",&ans);
	
	system("cls");
	
	}while(ans=='y'||ans=='Y');
	return(0);
}

/**************************************************************** END ***********************************************************************/