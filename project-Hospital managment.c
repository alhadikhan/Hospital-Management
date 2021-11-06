#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char Ans=0;
int okey;
int b,valid=0;

void Welcomescreen(void);
void title(void);
void Mainmenu(void);
void login_screen(void);
void add_reco(void);
void func_list();
void search_reco(void);
void Edit_reco(void);
//void delet_reco(void);
void ex_it(void);
void gotoxy(short x,short y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
struct patient
{
    int age;
    char first_name [20];
    char last_name [20];
    char gender;
    char address [30];
    char contact_no [20];
    char email [20];
    char problem [40];
};
struct patient p,temp_c;

main(void)
{
    system("COLOR 9");
    Welcomescreen();
    title();
    login_screen();


}
void Welcomescreen(void)
{
    int i;
    char ch;
    ch = 219;
    gotoxy(32,5);
    for(i = 0; i < 51; i++){

        printf("%c", ch);
    }
    printf("\n");
    printf("\t\t\t\t*\t\t\t\t\t\t  *\n\t\t\t\t*\t\t WELCOME\tTO\t\t  *\n");
    printf("\t\t\t\t*\t\t\t\t\t\t  *\n\t\t\t\t*\t   MEDICAL   CENTER   OF   MBSTU \t  *\n\n\n");
    gotoxy(32,11);
    for(i = 0; i < 51; i++){

        printf("%c", ch);
    }
    printf("\n");
    printf("\n\n\n\n\n\n \nPress any key to continue.......\n");
    getch();
    system("cls");
}
void title(void)
{
    printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t\t\tMEDICAL   CENTER   OF   MBSTU\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}
//main meanu declaration
void Mainmenu()
{
    system("cls");
    int choose;
    title();
    printf("\n\n\n\n\t\t\t\t1. Add Patient Record\n");
    printf("\n\t\t\t\t2. List Patient Record\n");
    printf("\n\t\t\t\t3. Search Patient Record\n");
    printf("\n\t\t\t\t4. Edit Patient Record\n");
   // printf("\n\t\t\t\t5. Delete Patient Record\n");
    printf("\n\t\t\t\t6.  Exit\n");
    printf("\n\n\n\t\t\tChoose from 1 to 5 :-");
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        add_reco();
        break;
    case 2:
        func_list();
        break;
    case 3:
        search_reco();
        break;
    case 4:
         Edit_reco();
        break;
   // case 5:
       // delet_reco();
       // break;
    case 5:
        ex_it();
        break;
    default:
        printf("\t\t\t Invalid entry.Please enter right option.....\n");
        getch();
    }
}
/***********************add record from  patient**********************/
void add_reco()
{
    system("cls");
    title();
    char ans;
    FILE *fl;
    fl=fopen("Record2.dat","a"); //open file in write mood

    printf("\n\n\n\t\t\t****** Add  Record *******\n");
    //first name part
A:
    printf("\n\t\t\tFrist Name-");
    getchar();
    scanf("%s",p.first_name);
    p.first_name[0]=toupper(p.first_name[0]);
    if(strlen(p.first_name)>20 ||strlen(p.first_name)<2 )
    {
        printf("\n\t\tInvalid first name!!!\t Max range of 20 and Min is 2.\n");
        goto A;
    }
    else
    {
        for(b=0; b<strlen(p.first_name); b++)
        {
            if(isalpha(p.first_name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\tFirst name contains invalid character.Enter again.");
            goto A;
        }
    }
// last name part
B:
    printf("\n\t\t\tLast Name-");
    getchar();
    scanf("%s",p.last_name);
    p.last_name[0]=toupper(p.last_name[0]);
    if(strlen(p.last_name)>20 ||strlen(p.last_name)<2 )
    {
        printf("\n\t\tInvalid last name!!!\t Max range of 20 and Min is 2.\n");
        goto B;
    }
    else
    {
        for(b=0; b<strlen(p.last_name); b++)
        {
            if(isalpha(p.last_name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\tLast name contains invalid character.Enter again.");
            goto B;
        }
    }
    //gender part

       t:
        printf("\n\t\t\tGender(F/M)-");
        getchar();
        scanf("%c",&p.gender);
        if(toupper(p.gender)=='M'||toupper(p.gender)=='F')
        {
            okey=1;
        }
        else
        {
            okey=0;
        }
        if(!okey)
        {
            printf("\n\t\tInvalid character.Enter F 0r M");
            goto t;
        }
    //age
    printf("\n\t\t\tAge-");
    scanf("%d",&p.age);
    //address
    c:
    printf("\n\t\t\tAddress-");
    scanf("%s",p.address);
    p.address[0]=toupper(p.address[0]);
    if(strlen(p.address)>20 ||strlen(p.address)<4 )
    {
        printf("\n\t\tInvalid Address!!!\t Max range of 20 and Min is 4.\n");
        goto c;
    }
    //contract no

    D:
    printf("\n\t\t\tContract no-");
    getchar();
    scanf("%s",p.contact_no);
    if(strlen(p.contact_no)>11 ||strlen(p.contact_no)!=11 )
    {
        printf("\n\t\t\tInvalid.Contract no must contain 11 numbers.Enter again\n");
        goto D;
    }
      else
    {
        for(b=0; b<strlen(p.contact_no); b++)
        {
            if(!isalpha(p.contact_no[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\tInvalid.Contract no must contain 11 numbers.Enter again");
            goto D;
        }
    }
   //email address
    E:
    printf("\n\t\t\tEmail address-");
    getchar();
    scanf("%s",p.email);
    if(strlen(p.email)>30 ||strlen(p.email)<8 )
    {
        printf("\n\t\t\tInvalid Email!\t Max range of 30 and Min is 8..Enter again\n");
        goto E;
    }
    //problem
    F:
    printf("\n\t\t\tProblem-");
    scanf("%s",p.problem);
    p.problem[0]=toupper(p.problem[0]);
    if(strlen(p.problem)<3 )
    {
        printf("\n\t\tInvalid !!!\tMin is 3.\n");
        goto F;
    }


    fprintf(fl,"%s %s %c %i %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem);
    printf("\n\n\t\t\t ..........Information Record Successfully..........\n");
    fclose(fl);//fl file closed
    sd:
        getch();
        printf("\n\n\t\t\tDo you add more[Y/N]???");
        getchar();
        scanf("%c",&Ans);
        if(toupper(Ans)=='Y')
        {
            add_reco();
        }
        else if(toupper(Ans)=='N')
        {
          printf("\n\t\tThank you......");
          getch() ;
          Mainmenu();
        }
    else
    {
        printf("\n\t\tInvailed.Enter again..\n");
        goto sd;
    }
}
/*******************Veiw record*************/
void func_list()
{
    int row;
     system("cls");
    title();   //call title function
    FILE *fl;
    fl=fopen("Record2.dat","r"); //open file in mood
    printf("\n\n\n\t\t\t****** List Patient  Record *******\n");
    gotoxy(1,15);
    printf("Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Contract No.");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Problem\n");
    printf("=====================================================================================================================\n");
    row=17;
    while(fscanf(fl,"%s %s %c %i %s %s %s %s\n",&p.first_name,&p.last_name,&p.gender,&p.age,&p.address,&p.contact_no,&p.email,&p.problem)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s",p.first_name,p.last_name);
        gotoxy(20,row);
        printf("%c",p.gender);
        gotoxy(32,row);
        printf("%i",p.age);
        gotoxy(37,row);
        printf("%s",p.address);
        gotoxy(49,row);
        printf("%s",p.contact_no);
        gotoxy(64,row);
        printf("%s",p.email);
        gotoxy(88,row);
        printf("%s",p.problem);
        row++;
    }
    fclose(fl);
    getch();
    Mainmenu();

}
/**********************search record*****************/
void search_reco(void)
{
     char number[20];
    system("cls");
    title(); //call title function
    FILE *fl;
    fl=fopen("Record2.dat","r"); //open file in read mood
    printf("\n\n\t\t\t!!!!!!!!!!!!!Search Patients Record !!!!!!!!!!");
    printf("\n\n\tEnter Patient Phone Number to viewed:");
    scanf("%s",number);
    fflush(stdin);
    while(fscanf(fl,"%s %s %c %i %s %s %s %s\n",&p.first_name,&p.last_name,&p.gender,&p.age,&p.address,&p.contact_no,&p.email,&p.problem)!=EOF)
    {
        if(strcmp(p.contact_no,number)==0)
        {
        gotoxy(1,15);
        printf("Full Name");
        gotoxy(25,15);
        printf("Gender");
        gotoxy(32,15);
        printf("Age");
        gotoxy(37,15);
        printf("Address");
        gotoxy(49,15);
        printf("Contrat No");
        gotoxy(64,15);
        printf("Email");
        gotoxy(88,15);
        printf("Problem\n");
       // gotoxy(95,15);
       // printf("Doctor");
       // printf("Prescribed Doctor\n");
        printf("=====================================================================================================================\n");
        gotoxy(1,18);
        printf("%s%s",p.first_name,p.last_name);
        gotoxy(20,18);
        printf("%c",p.gender);
        gotoxy(32,18);
        printf("%i",p.age);
        gotoxy(37,18);
        printf("%s",p.address);
        gotoxy(49,18);
        printf("%s",p.contact_no);
        gotoxy(64,18);
        printf("%s",p.email);
        gotoxy(88,18);
        printf("%s",p.problem);
        //gotoxy(95,18);
        //printf("%s",p.doctor);
        printf("\n");
        break;
        }
    }


  if(strcmp(p.contact_no,number)!=0)
{
    gotoxy(5,10);
    printf("Record not found!");
    getch();
}
fclose(fl);
L:
getch();
printf("\n\n\t\t\tDo you want to view more[Y/N]??");
  scanf("%c",&Ans);
if(toupper(Ans)=='Y')
        {
            search_reco();
        }
        else if(toupper(Ans)=='N')
        {
          printf("\n\t\tThank you......");
          getch() ;
          Mainmenu();
        }
    else
    {
        printf("\n\t\tInvailed.Enter again..\n");
        goto L;
    }

}
/************************Edit record***************/
 void Edit_reco(void)
{
    FILE *fl,*ek;
    int i,b,valid=0;
    char ch;
    char phon[30];
    system("cls");
    title();
    ek=fopen("temp2.dat","w+");
    fl=fopen("Record2.dat","r");
    if(fl==NULL)
    {
        printf("\n\t Can not open file!!");
        getch();
        Mainmenu();
    }
    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!Edit Patient Record!!!!!!!!!!\n");
    gotoxy(12,13);
    printf("Enter the number of the Patient :");
    scanf("%s",phon);
    fflush(stdin);
    gotoxy(12,15);
    if(ek==NULL)
    {
        printf("\nCan not open file");
        getch();
        Mainmenu();
    }
    while(fscanf(fl,"%s %s %c %i %s %s %s %s\n",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem)!=EOF)
    {
        if(strcmp(p.contact_no,phon)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("#### Existing Record ######");
            gotoxy(10,19);
        printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem);
        gotoxy(12,22);
        printf("Enter New First Name:");
        scanf("%s",p.first_name);
        gotoxy(12,24);
        printf("Enter New Last Name:");
        scanf("%s",p.last_name);
        gotoxy(12,26);
        printf("Enter Gender:");
        getchar();
        scanf("%c",&p.gender);
        p.gender=toupper(p.gender);
        gotoxy(12,28);
        printf("Enter Age:");
        scanf("%i",&p.age);
        gotoxy(12,30);
        printf("Enter Address:");
        getchar();
        scanf("%s",p.address);
        p.address[0]=toupper(p.address[0]);
        gotoxy(12,32);
        printf("Enter Contract No:");
        scanf("%s",p.contact_no);
        gotoxy(12,34);
        printf("Enter Email:");
        scanf("%s",p.email);
        gotoxy(12,36);
        printf("Enter Problem:");
        scanf("%s",p.problem);
        p.problem[0]=toupper(p.problem[0]);
        gotoxy(12,38);
        printf("\nPress U charecter for the Updating operation...");
        ch=getche();
        if(ch=='u'|| ch=='U')
        {

        fprintf(ek,"%s %s %c %i %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem);
         printf("\n\n\t\t\tPatient record updated successfully...");

        }

        }
        else
        {
            fprintf(ek,"%s %s %c %i %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem);
        }
    }
    if(!valid)
    {
        printf("\n\t\tNo Record Found...");
    }
    fclose(ek);
    fclose(fl);
    remove("Record2.dat");
    rename("temp2.dat","Record2.dat");
    getch();
    Mainmenu();
}
/*void delet_reco(void)
{
    char name[20];
    int found=0;
    system("cls");
    title();//call the title function
    FILE *fl,*ek;
    ek=fopen("temp_file2.dat","w+");
    fl=fopen("Record2.dat","r");
     printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!Delete Patient Record!!!!!!!!!!\n");
    gotoxy(12,8);
    printf("\nEnter the patient Name to delete:");
    //scanf("%s",name);
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);
    //gotoxy(12,15);
    while(fscanf(fl,"%s %s %c %i %s %s %s %s",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem)!=EOF)
  {
      if(strcmp(p.first_name,name)!=0)
        fprintf(ek,"%s %s %c %i %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem);
      else
      {
           fprintf(ek,"%s %s %c %i %s %s %s %s\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem);
           found=1;
    }
  }
  if(found==0)
  {
      printf("\n\n\t\t\t Record not found.....");
      getch();
      Mainmenu();
  }
  else
    {
        fclose(fl);
       fclose(ek);
  remove("Record2.dat");
  rename("temp_file2.dat","Record2.dat");
  printf("\n\n\t\t\t Record deleted successfully...");
  getch();
  Mainmenu();
    }
}*/
void ex_it(void)
{
    system("cls");
    title();
    printf("\n\n\n\n\n\t\t\tThank you for visiting...");
    getch();
}
void login_screen(void)
{
     int e=0;
    char username[25],password[25];
    char ar;
    char Orginal_username[25]="mbstu";
    char Orginal_password[25]="1902";
    do
    {
        printf("\n\n\t\t\t\t\tEnter Username and Password\n");
        printf("\n\n\t\t\tUsername:-");
        scanf("%s",&username);
        printf("\n\t\t\tPassword:-");
        int k=0;
        while(1)
        {
            ar=getch();
            if(ar==13)
            {
                break;
            }
            else{
                password[k]=ar;
                putch('*');
                k++;
            }
        }
        password[k]=NULL;
        printf("\n");
        int result=strcmp(username,Orginal_username);
        int result_2=strcmp(password,Orginal_password);
        if(result==0 && result_2==0)
        {
            printf("\n\n\t\t\t\t\t.......Login sucessfully........\n");
            getch();
            Mainmenu();
            break;
        }
        else
        {
            printf("\n\n\t\t\t\t\tPassword is incorrect.....\n");
            e++;
            getch();
        }
    }
    while(e<=2);
    if(e>2)
    {
        printf("\n\t\t\tYou have crossed the limt.You can't login.....\n\n\n\n\n");
        getch();
        ex_it();

    }
    system("cls");
   }



