/************************************************************* HEADER FILES *****************************************************************/

#include<stdio.h>
#include<string.h>
#include<conio.h> 
#include<stdlib.h>
#include "head.h"

/********************************************************** INSERT FUNCTION *****************************************************************/

void enter_data()		//ACCEPT DATA INTO RECORDS
{
	FILE *fp=fopen("phonebook.csv","a+");
	/*serial++;
	char sln[5];
	itoa(serial,sln,10);
	fputs(sln,fp);
	fputc(',',fp);*/
	char line[500];
	int flag=1;
	while(flag)
	{
	int flag2=1;
	fflush(stdin);
	printf("\nEnter roll number :\t");
	gets(rn);
	rewind(fp);
	while(fgets(line,500,fp))
	{
		if(flag2==1)
		{
		char *token=strtok(line,",");
		if((strncmp(token,rn,5))==0)
		{
			printf("Roll number exists already\n");
			flag2=0;
		}
		}
	}
	if(flag2!=0)
		flag=0;
	}
	fputs(rn,fp);
	fputc(',',fp);
//First we take the name from the user
	printf("\nEnter name:\t");
	fflush(stdin);
	gets(name);
	fputs(name,fp);
	fputc(',',fp);
//We take the phone number from the user
	int f=1;
	char ch;
	int c=0;
	while(f)
	{
		c=0;
		printf("\nEnter the phone number:\t");
		fflush(stdin);
		gets(phnumb);
		while((ch=phnumb[c])!='\0')
		{
			c++;
		}
		if(c!=10)
		{
			printf("Please enter a valid 10 digit number\n");
		}
		else
		{
			int flag2=1;
			rewind(fp);
			while(fgets(line,500,fp))
			{
				if(flag2==1)
				{
					char *token=strtok(line,",");
					token=strtok(NULL,",");
					token=strtok(NULL,",");
					if(token=='\0')
					{
						fputs(phnumb,fp);
						fputc(',',fp);
						f=0;
						flag2=0;
						break;
					}
					else
					{
					if((strncmp(token,phnumb,10))==0)
					{
						printf("Phone number exists already\n");
						flag2=0;
					}
					}
				}
			}
			if(flag2!=0)
			{
				f=0;
				fputs(phnumb,fp);
				fputc(',',fp);
			}	
		}	
	}
//We take the city name from the user
	fflush(stdin);
	printf("\nEnter city:\t");
	gets(city);
	fputs(city,fp);
	fputc(',',fp);
//We take the email id from the user
	fflush(stdin);
	printf("\nEnter email id:\t");
	gets(email_id);
	fputs(email_id,fp);
	fputc(',',fp);
//We take the pin code from the user
	f=1;
	while(f)
	{
		c=0;
		printf("\nEnter pincode:\t");
		fflush(stdin);
		gets(pc);
		while((ch=pc[c])!='\0')
		{
			c++;
		}
		if(c!=6)
		{
			printf("\nPlease enter a valid 6 digit pincode\n");
		}
		else
		{
			fputs(pc,fp);
			fputc('\n',fp);
			f=0;
		}
	}
	fclose(fp);
}

/***************************************************** DISPLAY FUNCTION FOR SORTING *********************************************************/

void display(per *p[100],int n)
{
	FILE *fp=fopen("phonebook.csv","w");
	
	int sn;
	fflush(stdin);
	int i;
	
	printf("%-10s%-20s%-20s%-15s%-30s%-8s\n","Sl. no","Name","Phone number","City","Email id","Pincode\n");
	
	for(i=0;i<n;i++)
	{
		printf("%-10s",p[i]->rn);
		printf("%-20s",p[i]->name);
		printf("%-20s",p[i]->phnumb);
		printf("%-15s",p[i]->city);
		printf("%-30s",p[i]->email_id);
		printf("%-8s\n",p[i]->pc);
		
		fprintf(fp,"%s",p[i]->rn);
		fputc(',',fp);
		fprintf(fp,"%s",p[i]->name);
		fputc(',',fp);
		fprintf(fp,"%s",p[i]->phnumb);
		fputc(',',fp);
		fprintf(fp,"%s",p[i]->city);
		fputc(',',fp);
		fprintf(fp,"%s",p[i]->email_id);
		fputc(',',fp);
		fprintf(fp,"%s",p[i]->pc);
		fputc('\n',fp);
	}

	fclose(fp);
}

/****************************************************** SEARCH FUNCTION BY NAME *************************************************************/

void search_n()
	{
		FILE *fp=fopen("phonebook.csv","r");
		char s[500];
		char sn[2];
		int found=0;
		fflush(stdin);
		//char n[25];
		printf("Enter name to be found :\t");
		gets(name);
		if((fgets(s,500,fp)==NULL))
		{
			printf("Record does not exist");
		}
		else
		{
		rewind(fp);
		if(found==0)
		{
		printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
		while(fgets(s,500,fp))
		{
			char *token=strtok(s,",");
			strcpy(sn,token);
			token=strtok(NULL,",");
			if((strncmp(token,name,20))==0)
			{
				printf("%-10s",sn);
				printf("%-20s",token);
				token=strtok(NULL,",");
				printf("%-20s",token);
				token=strtok(NULL,",");
				printf("%-15s",token);
				token=strtok(NULL,",");
				printf("%-30s",token);
				token=strtok(NULL,",");
				printf("%-8s\n",token);
			}
		}
		}
		if(found==0)
		{
			printf("Record not found");
		}
		}
		fclose(fp);
	}
	
/****************************************************** SEARCH FUNCTION BY CITY *************************************************************/

void search_c()
	{
		FILE *fp=fopen("phonebook.csv","r");
		char n_[50],n[50],p[10],s[500];
		char sn[2];
		int found=0;
		fflush(stdin);
		//char n[25];
		printf("Enter city to be found :\t");
		gets(city);
		if((fgets(s,500,fp)==NULL))
		{
			printf("Record does not exist");
		}
		else
		{
		rewind(fp);
		if(found==0)
		{
		printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
		while(fgets(s,500,fp))
		{
			char *token=strtok(s,",");
			strcpy(sn,token);
			token=strtok(NULL,",");
			//printf("%s\n",token);
			strcpy(n,token);
			strcpy(n_,n);
			//printf("%s\n",n);
			token=strtok(NULL,",");
			strcpy(p,token);
			token=strtok(NULL,",");
			if((strncmp(token,city,20))==0)
			{
				found=1;
				printf("%-10s",sn);
				fflush(stdin);
				printf("%-20s",n_);
				printf("%-20s",p);
				printf("%-15s",token);
				token=strtok(NULL,",");
				printf("%-30s",token);
				token=strtok(NULL,",");
				printf("%-8s\n",token);
			}
		}
		}
		if(found==0)
		{
			printf("Record does not exist");
		}
		}
		fclose(fp);
	}

/****************************************************** SEARCH FUNCTION BY PIN CODE *********************************************************/

void search_pc()
	{
		FILE *fp=fopen("phonebook.csv","r");
		char n_[50],n[50],p[10],c[20],e[30],s[500];
		char ch;
		char sn[2];
		int found=0;
		fflush(stdin);
		printf("Enter pincode to be found :\t");
		gets(pc);
		if((fgets(s,500,fp)==NULL))
		{
			printf("Record does not exist");
		}
		else
		{
		rewind(fp);
		if(found==0)
		{
		printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
		while(fgets(s,500,fp))
		{
			found=1;
			char *token=strtok(s,",");
			strcpy(sn,token);
			token=strtok(NULL,",");
			strcpy(n,token);
			strcpy(n_,n);
			token=strtok(NULL,",");
			strcpy(p,token);
			token=strtok(NULL,",");
			strcpy(c,token);
			token=strtok(NULL,",");
			strcpy(e,token);
			token=strtok(NULL,",");
			if((strncmp(token,pc,6))==0)
			{
				printf("%-10s",sn);
				printf("%-20s",n_);
				printf("%-20s",p);
				printf("%-15s",c);
				printf("%-30s",e);
				printf("%-8s\n",token);
			}
		}
		}
		if (found==0)
		{
			printf("Record does not exist");
		}
		}
		fclose(fp);
	}
	
/****************************************************** SEARCH FUNCTION MAIN ****************************************************************/

void search()		//SEARCH FOR DATA IN RECORDS
{
	int n,dummy;
	char a;
	do
	{
		
	printf("1.SEARCH BY NAME\n2.SEARCH BY CITY\n3.SEARCH BY PINCODE\n");
	printf("\n\n Enter any one of the options : ");
	scanf("%d",&n);
	//clears screen	
	//getch();
	system("cls");
	
	switch(n)
		{
			case 1: search_n();
			break;
			
			case 2: search_c();
			break;
			
			case 3: search_pc();
			break;
			
			default: printf("\n Enter choice between 1 to 3 ");
		}
	printf("\n Do you want to search by any other option ? (y/n): ");
	scanf("%d",&dummy);
	scanf("%c",&a);
	
	//getch();
	system("cls");
	}
	while(a=='y'||a=='Y');
}

/****************************************************** MODIFY FUNCTION *********************************************************************/

void modify_data()                   //TAKE DATA TO MODIFIFY EXISTING RECORD
{
	FILE *fp=fopen("phonebook.csv","r");
	char s[500],n[25],t[500],z[500];
	char sn[2];
	int flag=0;
	fflush(stdin);
	//char n[25];
	
	printf("\n\nEnter roll no of record to be modified: ");
	gets(sn);
	
	fflush(stdin);
	
	while(fgets(s,500,fp))
	{
		char *token=strtok(s,",");
			
		//printf("%d",strncmp(token,phnumb,10));
			
		if((strncmp(token,sn,10))==0)
		{
			printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
			
			printf("%-10s",token);
			token=strtok(NULL,",");
			printf("%-20s",token);
			token=strtok(NULL,",");
			printf("%-20s",token);
			token=strtok(NULL,",");
			printf("%-15s",token);
			token=strtok(NULL,",");
			printf("%-30s",token);
			token=strtok(NULL,",");
			printf("%-8s\n",token);
				
			flag=1;
		}
	}
		
	fclose(fp);
	
	if(flag==0)
		printf("\nRecord not found\n");
	
	else
	{
	
	char chk[2],t[500];
	FILE *fn=fopen("new.csv","w");
	FILE *fp1=fopen("phonebook.csv","r"),*fp2=fopen("phonebook.csv","r");
	
	fflush(stdin);
	
	printf("\nEnter new data for modification : ");
	
	fflush(stdin);
	
	printf("\nEnter name to be changed to: ");
	gets(name);
	
	fflush(stdin);
	
	printf("Enter name of the city: ");
	gets(city);
	
	fflush(stdin);

	printf("Enter the email id: ");
	gets(email_id);
	
	printf("Enter the phone number: ");
	gets(phnumb);

	printf("Enter the pincode: ");
	gets(pc);
				
	printf("\nAre you sure u want to modify this record? Enter y/n: ");
	gets(chk);
				
	fflush(stdin);
				
	if(strcmp(chk,"y")==0)
	{
		//rewind(fp);
		while(fgets(t,500,fp1))
		{
			char *token=strtok(t,",");
			
			if((strncmp(token,sn,10))!=0)
				{
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
				}
		}
		
		while(fgets(z,500,fp2))
		{
			char *tok=strtok(z,",");
			
			if((strncmp(tok,sn,10))==0)
			{
				fputs(sn,fn);
				fputc(',',fn);
				fputs(name,fn);
				fputc(',',fn);
				fputs(phnumb,fn);
				fputc(',',fn);
				fputs(city,fn);
				fputc(',',fn);
				fputs(email_id,fn);
				fputc(',',fn);
				fputs(pc,fn);
			}	
		}
			
	printf("\nRecord modified\n");
			
	fclose(fp1);
	fclose(fn);
	fclose(fp2);
		
	remove("phonebook.csv");
	rename("new.csv","phonebook.csv");
		
	}
	}
}

/******************************************************* DELETE FUNCTION MAIN ***************************************************************/

void delete_record()
{
	int n,dummy;
	char a;
	do
	{
		
	printf("1.DELETE BY PHONE NO\n2.DELETE BY ROLL NO\n3.DELETE BY EMAIL ID");
	printf("\n\n Enter any one of the options : ");
	scanf("%d",&n);
	//clears screen	
	//getch();
	system("cls");
	
	switch(n)
		{
			case 1: delete_ph();
			break;
			
			case 2: delete_rn();
			break;
			
			case 3: delete_ei();
			break;
			
			default: printf("\n Enter choice between 1 to 3 ");
		}
	printf("\n Do you want to delete any other record by any other option ? (y/n): ");
	scanf("%d",&dummy);
	scanf("%c",&a);
	
	//getch();
	system("cls");
	}
	while(a=='y'||a=='Y');
}

/***************************************************** DELETE FUNCTION BY PHONE NO **********************************************************/

void delete_ph()
{
	FILE *fp=fopen("phonebook.csv","r");
	char s[500],n[25];
	char sn[2];
	fflush(stdin);
	//char n[25];
	
	printf("Enter phone no. of record to be deleted :\t");
	gets(phnumb);
	fflush(stdin);
	
	int flag=0;
		
	while(fgets(s,500,fp))
	{
		char *token=strtok(s,",");
		strcpy(sn,token);
		token=strtok(NULL,",");
		strcpy(n,token);
		token=strtok(NULL,",");
			
		//printf("%d",strncmp(token,phnumb,10));
			
		if((strncmp(token,phnumb,10))==0)
		{
			printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
			
			printf("%-10s",sn);
			printf("%-20s",n);
			printf("%-20s",token);
			token=strtok(NULL,",");
			printf("%-15s",token);
			token=strtok(NULL,",");
			printf("%-30s",token);
			token=strtok(NULL,",");
			printf("%-8s\n",token);
				
			flag=1;
		}
	}
		
	fclose(fp);
	
	if(flag==0)
		printf("\nRecord not found\n");
	
	else
	{
	
	char chk[2],t[500];
	FILE *fn=fopen("new.csv","w");
	FILE *fp1=fopen("phonebook.csv","r");
				
	printf("\nAre you sure u want to delete this record? Enter y/n: ");
	gets(chk);
				
	fflush(stdin);
				
	if(strcmp(chk,"y")==0)
	{
		//rewind(fp);
		while(fgets(t,500,fp1))
		{
			char *token=strtok(t,",");
			strcpy(sn,token);
			token=strtok(NULL,",");
			strcpy(n,token);
			token=strtok(NULL,",");
				
			if((strncmp(token,phnumb,10))!=0)
			{
				fputs(sn,fn);
				fputc(',',fn);
				fputs(n,fn);
				fputc(',',fn);
				fputs(token,fn);
				fputc(',',fn);
				token=strtok(NULL,",");
				fputs(token,fn);
				fputc(',',fn);
				token=strtok(NULL,",");
				fputs(token,fn);
				fputc(',',fn);
				token=strtok(NULL,",");
				fputs(token,fn);
			}	
		}
			
	printf("\nRecord deleted\n");
			
	fclose(fp1);
	fclose(fn);
		
	remove("phonebook.csv");
	rename("new.csv","phonebook.csv");
		
	}
	}
}

/***************************************************** DELETE FUNCTION BY ROLL NO **********************************************************/

void delete_rn()
{
	FILE *fp=fopen("phonebook.csv","r");
	char s[500];
	char sn[2];
	fflush(stdin);
		
	printf("Enter roll no. of record to be deleted :\t");
	gets(rn);
	fflush(stdin);
		
	int flag=0;
		
	while(fgets(s,500,fp))
	{
		char *token=strtok(s,",");
		//strcpy(rn,token);
		//token=strtok(NULL,",");
			
		if((strncmp(token,rn,5))==0)
		{
			printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
			//fflush(stdin);
				
			printf("%-10s",rn);
			token=strtok(NULL,",");
			printf("%-20s",token);
			token=strtok(NULL,",");
			printf("%-20s",token);
			token=strtok(NULL,",");
			printf("%-15s",token);
			token=strtok(NULL,",");
			printf("%-30s",token);
			token=strtok(NULL,",");
			printf("%-8s\n",token);
				
			flag=1;	
		}
	}
		
	fclose(fp);
		
	if (flag==0)
		printf("\nRecord not found\n");
		
	else
	{
		char chk[2],t[500];
		FILE *fn=fopen("new.csv","w");
		FILE *fp1=fopen("phonebook.csv","r");
				
		printf("\nAre you sure u want to delete this record? Enter y/n: ");
		gets(chk);
				
		fflush(stdin);
				
		if(strcmp(chk,"y")==0)
		{
			//rewind(fp);
			while(fgets(t,500,fp1))
			{
				char *token=strtok(t,",");
				//strcpy(rn,token);
				
				if((strncmp(token,rn,10))!=0)
				{
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
				}
				
			}
			
			printf("\nRecord deleted\n");
		
			system("cls");
		
			fclose(fp1);
			fclose(fn);
		
			remove("phonebook.csv");
			rename("new.csv","phonebook.csv");
		}
	}
}

/***************************************************** DELETE FUNCTION BY EMAIL ID **********************************************************/

void delete_ei()
{
	FILE *fp=fopen("phonebook.csv","r");
	char s[500],t[500];
	char sn[2],n[50],p[10],c[30];
		
	printf("Enter email id of record to be deleted :\t");
	fflush(stdin);
	scanf("%[^\n]%*c",email_id);
	
	fflush(stdin);
		
	int flag=0;
		
	while(fgets(s,500,fp))
	{
		char *token=strtok(s,",");
		strcpy(rn,token);
		fflush(stdin);
		token=strtok(NULL,",");
		strcpy(name,token);
		token=strtok(NULL,",");
		strcpy(p,token);
		token=strtok(NULL,",");
		strcpy(c,token);
		token=strtok(NULL,",");
		
		fflush(stdin);
			
		if((strncmp(token,email_id,5))==0)
		{
			printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
			fflush(stdin);
				
			printf("%-10s",rn);
			printf("%-20s",name);
			printf("%-20s",p);
			printf("%-15s",c);
			printf("%-30s",token);
			token=strtok(NULL,",");
			printf("%-8s\n",token);
			
			fflush(stdin);
				
			flag=1;	
		}
	}
		
	fclose(fp);
		
	if (flag==0)
		printf("\nRecord not found\n");
		
	else
	{
		char chk[2],t[500];
		FILE *fn=fopen("new.csv","w");
		FILE *fp1=fopen("phonebook.csv","r");
				
		printf("\nAre you sure u want to delete this record? Enter y/n: ");
		gets(chk);
				
		fflush(stdin);
				
		if(strcmp(chk,"y")==0)
		{
			//rewind(fp);
			while(fgets(t,500,fp1))
			{
				char *token=strtok(t,",");
				strcpy(sn,token);
				token=strtok(NULL,",");
				strcpy(name,token);
				token=strtok(NULL,",");
				strcpy(p,token);
				token=strtok(NULL,",");
				strcpy(c,token);
				token=strtok(NULL,",");
				
				fflush(stdin);
				
				if((strncmp(token,email_id,10))!=0)
				{
					fputs(sn,fn);
					fputc(',',fn);
					
					fputs(name,fn);
					fputc(',',fn);
					
					fputs(p,fn);
					fputc(',',fn);
					
					fputs(c,fn);
					fputc(',',fn);

					fputs(token,fn);
					fputc(',',fn);
					
					token=strtok(NULL,",");
					fputs(token,fn);
				}
				
			}
			
			printf("\nRecord deleted\n");
		
			system("cls");
		
			fclose(fp1);
			fclose(fn);
		
			remove("phonebook.csv");
			rename("new.csv","phonebook.csv");
		}
	}
}

/************************************************************* SWAP FUNCTION ****************************************************************/

//swaping 2 values using pointers
void swap(per **p,per **q)
{
	per *temp;
	
	temp=*p;
	*p=*q;
	*q=temp;
}

/********************************************************** INITIALISE FUNCTION *************************************************************/

void initialise(per a[100],per *p[100],int n)
{
	int i;	
	for (i=0;i<n;i++)
		p[i]=&a[i];
}

/********************************************************* SORT FUNCTION BY NAME ************************************************************/

void sort_n(per *p[100],int n)
{
		int i,j,pos;
	
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(p[pos]->name,p[j]->name)>0)
				pos=j;
		}
		
		if(pos!=i)
			swap(&p[pos],&p[i]);
	}
}

/********************************************************* SORT FUNCTION BY CITY ************************************************************/

void sort_c(per *p[100],int n)
{
	int i,j,pos;
	
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(p[pos]->city,p[j]->city)>0)
				pos=j;
		}
		
		if(pos!=i)
			swap(&p[pos],&p[i]);
	}
}

/******************************************************* SORT FUNCTION BY ROLL NO ***********************************************************/

void sort_rn(per *p[100],int n)
{
	int i,j,pos;
	
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(p[pos]->rn,p[j]->rn)>0)
				pos=j;
		}
		
		if(pos!=i)
			swap(&p[pos],&p[i]);
	}
}	

/********************************************************* SORT FUNCTION MAIN ***************************************************************/

void sort_record()
{
	FILE *fp=fopen("phonebook.csv","r");
	
	int choice,i=0;
		
	char line[500],*item;
	
	//reading everything in the file
	while(fgets(line,500,fp))
	{
		item=strtok(line,",");
		strcpy(a[i].rn,item);
		
		item=strtok(NULL,",");	
		strcpy(a[i].name,item);
		
		item=strtok(NULL,",");	
		strcpy(a[i].phnumb,item);
		
		item=strtok(NULL,",");	
		strcpy(a[i].city,item);
		
		item=strtok(NULL,",");	
		strcpy(a[i].email_id,item);
		
		item=strtok(NULL,",\n");	
		strcpy(a[i].pc,item);
		
		i++;
	}
	
	//i is no of records
	
	fclose(fp);
	
	initialise(a,p,i);
	
	int n,dummy;
	char a;	

	do
	{
		
	printf("1.SORT BY NAME\n2.SORT BY CITY\n3.SORT BY ROLL NO.");
	printf("\n\n Enter any one of the options : ");
	scanf("%d",&n);
	//clears screen
	system("cls");
	
	switch(n)
		{
			case 1: sort_n(p,i);
					display(p,i);
			break;
			
			case 2: sort_c(p,i);
					display(p,i);
			break;
			
			case 3: sort_rn(p,i);
					display(p,i);
			break;
			
			
			default: printf("\n Enter choice between 1 to 4 ");
		}
	printf("\n Do you want to sort by any other option ? (y/n): ");
	scanf("%d",&dummy);
	scanf("%c",&a);
	
	//getch();
	system("cls");
	}while(a=='y'||a=='Y');
	
}

/********************************************************* DISPLAY FUNCTION *****************************************************************/

void display_record()
{
	FILE *fp=fopen("phonebook.csv","r");
	char s[500];
	int sn;
	fflush(stdin);
	
	printf("%-10s%-20s%-20s%-15s%-30s%-8s","Sl. no","Name","Phone number","City","Email id","Pincode\n");
	fflush(stdin);
	
	while(fgets(s,500,fp))
		{
			char *token=strtok(s,",");
			strcpy(rn,token);
			token=strtok(NULL,",");
				printf("%-10s",rn);
				printf("%-20s",token);
				token=strtok(NULL,",");
				printf("%-20s",token);
				token=strtok(NULL,",");
				printf("%-15s",token);
				token=strtok(NULL,",");
				printf("%-30s",token);
				token=strtok(NULL,",");
				printf("%-8s\n",token);
			
		}
		fclose(fp);
}

/**************************************************************** END ***********************************************************************/