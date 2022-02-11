/****************************************************** STRUCT TO STORE VALUES IN FILE ******************************************************/

typedef struct per
{
	char rn[5];
	char name[50];
	char city[30];
	char email_id[50];
	char phnumb[11];
	char pc[7];
}per;

/**************************************************************** FUNCTION PROTOTPYES *******************************************************/

void enter_data();
void display();
void search();
void modify_data();
void delete_record();
void sort_record();
void search_n();
void search_c();
void search_pc();

void sort_c(per*[],int);
void sort_pc(per*[],int);
void sort_sln(per*[],int);

void delete_ph();
void delete_rn();
void delete_ei();

void initialise();
void swap();
void display_record();

/************************************************************** GLOBAL VARIABLES ************************************************************/

char name[50],city[30],email_id[50],phnumb[10],pc[6],rn[5];
static int serial=0;

per *p[100];
per a[100];

/**************************************************************** END ***********************************************************************/