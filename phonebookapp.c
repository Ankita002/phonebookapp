#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
 struct person
 {

     char name[35];
     char address[50];
     char father_name[35];
     char mother_name[30];
     long int mobile_no[10];
     char mail[100];
     char profession[30];
     char detail[200];

 };
 void menu();
 void got();
 void start();
 void back();
 void listrecord();
 void modifyrecord();
 void deleterecord();
 void searchrecord();
 int main()
 {

     system("color 6f");
     start();
     return 0;
 }
 void back()
 {

     start();
 }
 void start(){

 menu();
 }
 void menu()
 {
  system("cls");
  printf("**************************Phone Book Application*****************");
  printf("\n\n\n\t\t\t\t MENU \t\t\n\n");
  printf("*********************************************************************\n");
  printf("\t 1. Add New Contact \n");
  printf("\t 2. List\n");
  printf("\t 3. Exit\n");
  printf("\t 4. Modify \n");
  printf("\t 5. Search \n");
  printf("\t 6. Delete \n");
printf("*********************************************************************\n");
  switch(getch())
  {

      case '1':
         {

          addrecord();
          break;
          }
      case '2':
        {listrecord();
        break;
        }
      case '3':
        {

          exit(0);
          break;}
      case '4':
         {

          modifyrecord();
          break;}
      case '5':
       {

        searchrecord();
        break;
       }
     case '6': {deleterecord();
     break;}
     default:{
        system("cls");
        printf("\n Enter your choice from 1 to 6 only ");
        printf("\n Enter any key");
        getch();
  }

  }



  }

void addrecord()
{

    system("cls");
    FILE *f;
    struct person p;
    f= fopen("project.dat","ab+");
    printf("Enter name:");
    got(p.name);
    printf("\n Enter the address:");
    got(p.address);
    printf("\n Enter father's name:");
    got(p.father_name);
    printf("\n Enter mother's name:");
    got(p.mother_name);
    printf("\n Enter Phone number:");
    scanf("%ld",&p.mobile_no);
    printf("\n Enter e-mail:");
    got(p.mail);
    printf("\n Enter profession:");
    got(p.profession);
    printf("\n Enter any other detail:");
    got(p.detail);
    fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
    printf("\n record saved");

    fclose(f);

    printf("\n Enter any key:");
     getch();
     system("cls");
     menu();


}

void listrecord()
{

    struct person p;
    FILE *f;
    f=fopen("project.dat","rb");
    if(f==NULL)
    {

        printf("\n File is Empty.");
        exit(1);
    }


    while(fread(&p,sizeof(p),1,f)==1)
    {

printf("\n\n\n YOUR RECORD :\n\n ");
printf("*********************************************************************\n");
  printf("\n Name=%s\n Address=%s\n Father name=%s\n Mother name=%s\n Mobile no.=%ld\n E-mail=%s\n Profession=%s\n Details=%s",p.name,p.address,p.father_name,p.mother_name,p.mobile_no,p.mail,p.profession,p.detail);
printf ("\n Press any key to see next record \n");

getch();
system("cls");

    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();

}

void searchrecord(){
struct person p;
FILE *f;
char name[100];
f=fopen("project.dat","rb");
if(f==NULL)
{

    printf("\n Error opening file.\a\a\a\a");
    exit(1);

}

printf("\n Enter name of person to search \n");
got(name);
int a=0;
while(fread(&p,sizeof(p),1,f)==1)
{

    if(strcmp(p.name,name)==0)
    {

        printf("\n Details About %s",name);
             printf("\n Name=%s\n Address=%s\n Father name=%s\n Mother name=%s\n Mobile no.=%ld\n E-mail=%s\n Profession=%s\n Details=%s",p.name,p.address,p.father_name,p.mother_name,p.mobile_no,p.mail,p.profession,p.detail);
    a=1;
    }

    }
    if(a!=1)
    {printf(" \nContact not found.");
    }
    fclose(f);
    printf("\n Enter any key:");
    getch();
    system("cls");
    menu();
}

void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project.dat","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("tempo.dat","wb+");
		if(ft==NULL)

            printf("file opening error");
		else

        {


		printf("Enter CONTACT'S NAME:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("tempo.dat");
	}
		else
		{
			remove("project.dat");
			rename("tempo.dat","project.dat");
			printf("\n \t RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

    void modifyrecord(){

    int c;
    FILE *f;

    int flag=0;

    struct person p,s;
    char name[50];
    f=fopen("project.dat","rb+");

    if(f==NULL)
    {

        printf("Contact's data is not added yet.");
        exit(1);

    }

    else{
        system("cls");
        printf("\n Enter contact's name to modify: \n");
        got(name);
        while(fread(&p,sizeof(p),1,f)==1){

            if(strcmp(name,p.name)==0)
            {
                 printf("Enter name:");
    got(s.name);
    printf("\n Enter the address:");
    got(s.address);
    printf("\n Enter father's name:");
    got(s.father_name);
    printf("\n Enter mother's name:");
    got(s.mother_name);
    printf("\n Enter Phone number:");
    scanf("%ld",&s.mobile_no);
    printf("\n Enter e-mail:");
    got(s.mail);
    printf("\n Enter profession:");
    got(s.profession);
    printf("\n Enter any other detail:");
    got(s.detail);
    fseek(f,-sizeof(p),SEEK_CUR);
    fwrite(&s,sizeof(p),1,f);
    flag=1;
    break;

            }



            fflush(stdin);
        }

        if(flag=1)
        {


        printf("\n Your data is modified.");
    }

    else{
        printf("\n Data is not found.");



    }

    fclose(f);





    }

    printf("\n Enter any key:");
    getch();
    system("cls");
    menu();

}


void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}

