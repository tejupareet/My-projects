//BROUGHT TO YOU BY code-projects.org//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#define MAX_ROWS 32
#define MAX_COLS 100
#define MAX_NAME_LENGTH 99 // Maximum length for each string (99 characters)

char ch[10][130]={"Cardiff Express","Belfast Express","Derby Express","Chester Express","Newport Express","Truro Express"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno=0;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
int booking();//for booking the tickets
int read_number(int trno);//for reading the number from the file
int read_name(int trno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
int cancle();
void login();

int main()
{
	login();
    int num=0,i=0;
    do{
    system("cls");
    printf("\n\n\n");
   printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> View Bus List\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Book Tickets\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Cancle Booking\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Bus Status Board\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    //scanf("%d",&num);
	if (scanf("%d", &num) >0) {
		printf("you want %d num.\n", num);
	} 
	else printf("You did not enter any number.\n");
    switch(num)
    {
    case 1:
        bus();//for list of bus
        break;
    case 2:
        booking();//for booking the tickets
        break;
    case 3:
        cancle();
        break;
    case 4:
        status();
        break;
    }
	getch();
    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t Brought To You By code-projects.org");
    getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

int booking()
{

    int i=0;
    char numstr[100]="\n";
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering train number
bus();//for seeing train least
printf("Enter the Bus number:--->");
if(scanf("%d",&trno)>0){
	printf("You want bus no %d\n",trno);
}
else printf("No input provided\n");
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
status_1(trno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4]="\n",str3[4]="\n";
 int seat1=0,seat2=0,booking=0;
if(trno == 1)
{
 if (!(f1 = fopen("tr1.txt","r+"))) return 0;
 if(f1!=NULL){
 fgets(str1,80,f1);
 fclose(f1);
 }
}else if(trno == 2)
{
 if (!(f1 = fopen("tr2.txt","r+"))) return 0;
 if(f1!=NULL){
 fgets(str1,80,f1);
 fclose(f1);
 }
}else if(trno == 3)
{
 if (!(f1 = fopen("tr3.txt","r+"))) return 0;
 if(f1!=NULL){
 fgets(str1,80,f1);
 fclose(f1);
 }
}
else if(trno == 4)
{
 if (!(f1 = fopen("tr4.txt","r+"))) return 0;
 if(f1!=NULL){
 fgets(str1,80,f1);
 fclose(f1);
 }
}
else if(trno == 5)
{
 if(!(f1 = fopen("tr5.txt","r+"))) return 0;
 if(f1!=NULL){
 fgets(str1,80,f1);
 fclose(f1);
 }
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
//scanf("%d",&booking);
if (scanf("%d", &booking) >0) {
printf("you want %d booking.\n", booking);
} 
else printf("You did not enter any number.\n");
printf("\n");

seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
itoa(seat1, str1, 10);
//for reading the seats from the user.
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 if(f1!=NULL){
 fputs(str1,f1);
 fclose(f1);
 }
}
else if(trno == 2)
{
 if (!(f1 = fopen("tr2.txt","w"))) return 0;
 if(f1!=NULL){
 fputs(str1,f1);
  fclose(f1);
 }
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 if(f1!=NULL){
 fputs(str1,f1);
  fclose(f1);
 }
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 if(f1!=NULL){
 fputs(str1,f1);
  fclose(f1);
 }
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 if(f1!=NULL){
 fputs(str1,f1);
 fclose(f1);
 }
}
}
return 0;
}



void name_number(int booking,char numstr[100])
{
char tempstr[100]="\n",tempstr1[12]="status",tempstr2[12]="number";
int number=0;
    FILE *a,*b;
    
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//for open the file to write the name in the file
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file
for(int i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:--->");
      if(scanf("%d",&number)>0){
		  printf("you want %d number\n",number);
		  if(number>1){
			  number= number-1;
		  }
	  }
	  else printf("No input provided\n");
      printf("\t\t\t\tEnter the name of person:--->");
      if(scanf("%100s",name[number])>0){
		  printf("You want name %s\n",name[number]);
	  }
	  else printf("No input provided");
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
	  if((a!=NULL)&&(b!=NULL)){
		fprintf(a,"%s ",name[number]);
		fprintf(b,"%s ",tempstr);
	  }

}
if(a!=NULL){
	fclose(a);
}
if(b!=NULL){
	fclose(b);
}
}



int read_number(int trno)//for putting the numeric value in the array
{
char tempstr[100]="\n",tempstr2[12]="number";
FILE *a,*b;
char numstr[100]="\n";
int i=0,j=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
int c=0;
if (a != NULL){
  while(!feof(a))//while(c = fgetc(a)) != EOF)
   {
	  
		c = fgetc(a);
		number[i][j] = (char) ((c > CHAR_MAX) ? (c - (UCHAR_MAX + 1)) : c);
      //number[i][j] = fgetc(a);
	  

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
	 
   }
}
   /*my code
    while ((c = fgetc(a)) != EOF) {
        // Check if the maximum length for the string is reached
        if (j >= MAX_NAME_LENGTH) {
            printf("Maximum length reached for string %d. Skipping remaining characters.\n", i + 1);
            break;
        }

        if (c == ' ' || c == '\n') {
            // If a space or newline is encountered, null-terminate the string
            number[i][j] = '\0';
            j = 0; // Reset column index
            i++;   // Move to the next row
            if (i >= MAX_ROWS) {
                printf("Maximum number of strings reached. Skipping remaining characters.\n");
                break;
            }
        } else {
            number[i][j++] = (char)c; // Store the character in the array
        }
    }
   my code end*/
   int k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   if(a!=NULL){
   fclose(a);
   }
   return k;
}


int read_name(int trno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100]="\n";
int i=0,j=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
if(!(b = fopen(tempstr1,"a+"))) return 0;//for open the file to write the name in the file
int c=0;
//if (b != NULL){
   while(!feof(b))
   {
	  // ((ch = fgetc(stream)) != EOF) && (ch != '\n')); i++)
	 // buf = (char) ((c > CHAR_MAX) ? (c - (UCHAR_MAX + 1)) : c);
	  c = fgetc(b);
	  name[i][j] = (char) ((c > CHAR_MAX) ? (c - (UCHAR_MAX + 1)) : c);
     //name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
//}
   name[i][j]='\0';
   //int k=i;
   //if(b!=NULL){
   fclose(b);
   //}
   return 0;
}

void status()
{
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int trno=0,index=0,j=0;
    printf("Enter the number of bus:---->");
    if(scanf("%d",&trno)>0){
		printf("you want bus no.:%d\n",trno);
	}
	else printf("No intiger entered here\n");
    j=read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(int i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(int i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i=0,index=0,j=0;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


int cancle()
{
 int seat_no=0,i=0,j=0;
 char numstr[100]="\n",tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 if(scanf("%d",&trno)>0){
	 printf("you want bus no %d\n",trno);
 }
 else printf("No input provided\n");
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 printf("Enter the seat number:--->");
 //scanf("%d",&seat_no);
  if(scanf("%d",&seat_no)>0){
	 printf("you want seat no %d\n",seat_no);
 }
 else printf("No input provided\n");
 FILE *a,*b;
 //if(!(a = fopen(tempstr1,"w+"))) return 0;
 
 a = fopen(tempstr1,"w+");
 if (!(b = fopen(tempstr2,"w+"))) return 0;
// b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
				 if((a!=NULL)&&(b!=NULL)){
					fprintf(b,"%d ",num1[j]);
					fprintf(a,"%s",name[j]);
				 }
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
 if((a!=NULL)&&(b!=NULL)){
fclose(a);
fclose(b);
 }
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
	return 0;
}


void login()
{
	int a=0,i=0;
    char uname[10]="\n",c=' '; 
    char pword[10]="\n",code[10]="\n";
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");
	
    printf("\n  =========================  LOGIN FORM  =========================  ");
    printf(" \n                       ENTER USERNAME:-");
	//scanf("%s", &uname);
	 if(scanf("%9[^\n]",uname)>0){
	 printf("you want name %s\n",uname);
 }
 else printf("No input provided\n");
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
		
}
