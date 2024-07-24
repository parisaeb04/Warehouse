#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

char username[10] ;          //the one which choose for account or user enter

struct inf {
          char f_name[20];
          char l_name[20];
          char id[10];
          char email[50];
          char t_number[10];
          char u_name[10];
          char pass[10] ;
          struct inf *next;
        };

struct product {
         char kind [5];
         char model [15];
         char n_taste [5];
         char brand [15];
         char s_date [10];
         char e_date [10];
         char price [10];
         char barcode [10];
         char number [10];
         struct product *next;
       } ;

struct inf *beginning = NULL;
struct product *first = NULL;
struct product *temp;

int start(void);              // main menu
void sign_in(void);           // sing up new user
void log_in(void);            // log in for a user who have account
int program_parts(void);       // program part menu
int new_product(void);         // adding new item to products
int need_fridge(void);          // first category for products
int not_need_fridge(void);       //second category for products
int continue_new_product(void);  // common field of products
void add_product(void);          // add number of a product
void decrease_product(void);      //reduce number of a product
int reports(void);               //reports menu
int n_product(void);              // report for number of products
int more_products(void);           //reporting products with more than 50 number
int less_products(void);          //reporting products with less than 10 number
int v_all(void);                  //reporting whole value of products
int v_product(void);               //reporting value of a special product
int added(void);                  //report adding number of all products
int reduced(void);                 //report reducing number of all products
int add_reduced(void);                  //report adding & reducing number of special products
int u_transaction(void);           //reporting user transaction
int u_list(void);                  //reporting list of users
int account_setting(void);

void main()
{
    start();
}

int start(void)
    {
        int c=1 , part ;

        printf("~~~ This is a food warehouse ~~~\n~~~~~~~~~~~ Welcome ~~~~~~~~~~~~\n\n\n");
        printf(" If you are a new user !! \n 1 - Sign in\n\n");
        printf(" Do you have an account ??\n 2 - Log in\n\n");
        printf(" 3 - Exit\n\n");

        printf(" Which part do you want\n Please enter the number : ");

        for(c=1;c<=5;c++)         //giving chance to user to enter the correct answer
       {
           if(c == 5)
           {
              printf("This is your last chance . If wrong again the program will be close\n");          //treating user
           }

           scanf("%d",&part);
           fflush(stdin);

           if(part == 1 || part == 2 || part == 3)
           {
              system("cls");

              if(part == 1)
              {
                 sign_in();
                 program_parts();
              }

              if(part == 2)
              {
                 log_in();
                 program_parts();
              }

              if(part == 3)
                 exit(0);
           }
          else
            printf("Wrong number\n");

       }
    }

void sign_in(void)
    {
        FILE *u ;
        struct inf *temp , *ptr , *temp2;
        int x , c ;
        char ch_pass[10] ;
        int not_bot , not_bot_ans;

        printf(" Welcome to our program \n You should make your profile and give some information\n");
        printf(" Please enter correct information because we are making your ID\n\n\n");

        u=fopen("user_information.txt","a+");

        if (u == NULL)
        {
            printf("the file can not be opened");
            start();
        }

        ptr = malloc(sizeof(struct inf));

            // making linked list from the file
            while(fread(ptr , sizeof(struct inf) , 1 , u))
            {

               if(beginning == NULL)
               {
                 beginning = malloc(sizeof (struct inf));
                 strcpy (beginning -> f_name , ptr -> f_name);
                 strcpy (beginning -> l_name , ptr -> l_name);
                 strcpy (beginning -> u_name , ptr -> u_name);
                 strcpy (beginning -> pass , ptr -> pass);
                 strcpy (beginning -> email , ptr -> email);
                 strcpy (beginning -> t_number , ptr -> t_number);
                 strcpy (beginning -> id , ptr -> id);
                 beginning -> next = NULL;
               }
               else
               {
                  temp = beginning;
                  while (temp -> next != NULL)
                  {
                    temp = temp->next;
                  }
                  temp2 = temp;
                  temp = malloc(sizeof(struct inf));
                  strcpy (temp -> f_name , ptr -> f_name);
                  strcpy (temp -> l_name , ptr -> l_name);
                  strcpy (temp -> u_name , ptr -> u_name);
                  strcpy (temp -> pass , ptr -> pass);
                  strcpy (temp -> email , ptr -> email);
                  strcpy (temp -> t_number , ptr -> t_number);
                  strcpy (temp -> id , ptr -> id);
                  temp -> next = NULL;
                  temp2 -> next = temp;
                }
           }


           printf("please enter your first name : \n");
           gets(temp->f_name);
           printf("please enter your last name : \n");
           gets(temp->l_name);
           printf("please enter your id code :\n");
           gets(temp->id);
           printf("please enter your E-mail address :\n");
           gets(temp->email);
           printf("please enter your telephone number :\n add your number without 0 \n for example : 9123456789\n");
           gets(temp->t_number);

           system("cls");

           printf("please choose a user name (contain alphabet & number)\n");
           gets(temp->u_name);
           strcpy(username , temp->u_name);
           printf("choose a password (contain 8 character , alphabet and number)\n !! make sour its not easy to guess !!\n");
           gets(temp->pass);
           printf("enter your password for second time to check and save !!\n");

           for(c=1;c<=2;c++)       //giving chance to give the same password for to step security
           {
              gets(ch_pass);

              if(strcmp(temp->pass , ch_pass)==0)
              {
                break;
              }
              else
                printf("There is difference , enter your password again !! \n");
           }

           srand(time(NULL));
           not_bot=rand();             //random number to make verification user
           printf("please enter the the checking code : %d \n",not_bot);
           scanf("%d",&not_bot_ans);
           if(not_bot_ans == not_bot)
           {
               // adding linked list
               temp -> next = NULL;
               temp2 -> next = temp;

               fwrite(temp , sizeof(struct inf) , 1 , u);
               if (fwrite != 0)               //writing in the file
               printf(" << your information added to system successfully >>\n ");
               Sleep(3000);
               fclose(u);
           }
           else
           {
               fclose(u);
               printf("you are a robot . we cant save your information\n");
               Sleep(2000);
               system("cls");
               start();
           }


        }



void log_in(void)
    {
        FILE *o ;
        struct inf *temp ,*ptr, *temp2;
        char password[10] ;
        int c ;


        o = fopen("user_information.txt","r");

        if(o == NULL)
        {
            printf(" the file con not be opened");
            start();
        }
        else
        {
            ptr = malloc(sizeof(struct inf));

            // making linked list from the file
            while(fread(ptr , sizeof(struct inf) , 1 , o))
            {
               if (beginning == NULL)
               {
                 beginning = malloc(sizeof (struct inf));
                 strcpy (beginning -> f_name , ptr -> f_name);
                 strcpy (beginning -> l_name , ptr -> l_name);
                 strcpy (beginning -> u_name , ptr -> u_name);
                 strcpy (beginning -> pass , ptr -> pass);
                 strcpy (beginning -> email , ptr -> email);
                 strcpy (beginning -> t_number , ptr -> t_number);
                 strcpy (beginning -> id , ptr -> id);
                 beginning -> next = NULL;
               }
               else
               {
                 temp = beginning;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct inf));
                 strcpy (temp -> f_name , ptr -> f_name);
                 strcpy (temp -> l_name , ptr -> l_name);
                 strcpy (temp -> u_name , ptr -> u_name);
                 strcpy (temp -> pass , ptr -> pass);
                 strcpy (temp -> email , ptr -> email);
                 strcpy (temp -> t_number , ptr -> t_number);
                 strcpy (temp -> id , ptr -> id);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);


            printf("~~~~ Welcome back ~~~~\n");
            printf(" please enter your user name : \n");

            gets(username);

            //searching in linked list to find the correct user name
            ptr = beginning;
            while( ptr != NULL)
            {
               if (strcmp(username , ptr->u_name)== 0)         //after finding user name , giving password from user
               {
                  c=1;
                  break;
               }
               ptr = ptr -> next;
            }

            if(c == 1)
            {
               printf("please enter your password:\n");
               gets(password);
               if(strcmp (ptr->pass,password) == 0)
               {
                  printf(" !! welcome user !!\n");
                  Sleep(2000);
               }
               else
               {
                  printf("wrong password!\n");
                  start();
               }
            }
            else
                if(c != 1)
                  {
                    printf("username not found!\n");
                    start();
                  }
        }
    }

int program_parts(void)
   {
        system("cls");
        int c ;
        int part;
        printf(" --> Which part do you want :\n");
        printf(" 1 - New products\n");
        printf(" 2 - Import products to warehouse \n");
        printf(" 3 - Egress products from warehouse \n");
        printf(" 4 - Reports of transactions \n");
        printf(" 5 - Account setting \n");
        printf(" 6 - Log out \n");
        printf(" 7 - Exit\n\n");
        printf(" --->");
        scanf("%d",&part);


        for(c=1 ; c<=3 ; c++)
        {
            if(isdigit(part) == 0) //checking right answer
            {
               for(c=1 ; c<=3 ; c++)
               {
                   switch(part)     //switching part
                   {
                      case 1 :
                        new_product();
                        break;

                      case 2 :
                        add_product();
                        break;

                      case 3 :
                        decrease_product();
                        break;

                      case 4 :
                        reports();
                        break;

                      case 5 :
                        account_setting();
                        break;

                      case 6 :
                        system("cls");
                        start();
                        break;

                      case 7 :
                        exit(0);
                        break;

                      default :
                        printf(" No part by this number !! \n");
                        if(c == 3)
                            printf("last chance !!");   //warning

                        scanf("%c",&part);
                        break;
                   }

               }

            }
            else
             {
               if(c == 3)
               {
                 printf("\n !! wrong answer , the program will close in 2 second !!");
                 Sleep(2000);
                 exit(0);
               }
               else
                printf(" ! wrong ans , there is no part ! \n");
             }

         }

   }

int new_product(void)
   {
       FILE *f ;
       int num ;
       struct product *temp2 , *temp3 , *ptr;

       system("cls");

       f=fopen("product.txt","a+");

       if(f == NULL)
       {
           printf(" !! NO file !!\n");
           program_parts();
       }
       else
       {
           // making linked list from the file
           temp = malloc(sizeof (struct product));
            while(fread(temp , sizeof(struct product) , 1 , f))
            {
               if(first == NULL)
               {
                  first = malloc( sizeof (struct product));
                  strcpy(first->kind , temp->kind);
                  strcpy(first->model , temp->model);
                  strcpy(first->n_taste , temp->n_taste);
                  strcpy(first->brand , temp->brand);
                  strcpy(first->s_date , temp->s_date);
                  strcpy(first->e_date , temp->e_date);
                  strcpy(first->price , temp->price);
                  strcpy(first->barcode , temp->barcode);
                  strcpy(first->number , temp->number);
                  first->next = NULL;
               }
               else
               {
                  temp2 = first;
                  while (temp2 -> next != NULL)
                  {
                    temp2 = temp2->next;
                  }
                  temp3 = temp2;
                  temp2 = malloc(sizeof(struct product));
                  strcpy(temp2->kind , temp->kind);
                  strcpy(temp2->model , temp->model);
                  strcpy(temp2->n_taste , temp->n_taste);
                  strcpy(temp2->brand , temp->brand);
                  strcpy(temp2->s_date , temp->s_date);
                  strcpy(temp2->e_date , temp->e_date);
                  strcpy(temp2->price , temp->price);
                  strcpy(temp2->barcode , temp->barcode);
                  strcpy(temp2->number , temp->number);
                  temp2->next=NULL;
                  temp3 -> next = temp2;
                }
           }
           ptr=temp;
           temp=malloc(sizeof (struct product));

           if(strcmp(username , "admin") == 0)                           //giving access to one user , only admin
           {
               printf(" you want to save new product , first of all in which category is your product ? \n");
               printf("---> 1 - need fridge \n ---> 2 - not need fridge \n");
               scanf("%d",&num);

               //choosing kind of product which specialized
               switch(num)
               {
                 case 1 :
                   need_fridge();
                   break;

                 case 2 :
                   not_need_fridge();
                   break;

                default :
                   printf(" !!!!!   wrong answer !!!!! \n");
                   Sleep(3000);
                   system("cls");
                   new_product();
               }

               continue_new_product();                 //going to common parts

               ptr -> next = temp;
               temp -> next = NULL;

               fwrite( temp , sizeof ( struct product) , 1 , f);
               fclose(f);
               printf(" << your information added to system successfully >>\n ");
               Sleep(2000);
               system("cls");
               program_parts();
           }
           else
           {
            printf("This part is lock for you !!");                //not access to users
            Sleep(3000);
            system("cls");
            program_parts();
            return;
           }
       }
   }

int need_fridge(void)
   {
       int num ;

       printf(" what kind of product is ?? \n");
       printf(" 1 - drinks \n 2 - ice cream \n 3 - dairy products \n");
       scanf("%d",&num);
       switch (num)
       {
          case 1 :
            strcpy(temp->kind , "dri");
            return;

          case 2 :
            strcpy(temp->kind , "icc");
            return;

          case 3 :
            strcpy(temp->kind , "dp");
            return;
       }
   }

int not_need_fridge(void)
   {
       int num ;

       printf(" What kind of product is ?? \n");
       printf(" 1 - cakes \n 2 - snacks \n 3 - dried products\n");
       scanf("%d",&num);

       switch (num)
       {
           case 1 :
            strcpy(temp->kind , "ca");
            return;

          case 2 :
            strcpy(temp->kind , "sn");
            return;

          case 3 :
            strcpy(temp->kind , "dp");
            return;
       }
   }

int continue_new_product(void)
   {
       FILE *f;

       //all the getchar  are because of the problem of jumping to next field

       printf(" what is the model ?\n");
       scanf("%s",temp->model);
       printf(" how many taste does it have ? \n");
       scanf("%s",temp->n_taste);
       printf(" what is the brand ? \n");
       scanf("%s",temp->brand);
       printf(" what is the manufacture date ?\n ... enter like this yy/mm/dd ...\n");
       scanf("%s",temp->s_date);
       printf(" what is the expiration date ?\n ... enter like this yy/mm/dd ...\n");
       scanf("%s",temp->e_date);
       printf(" enter the price :\n");
       scanf("%s",temp->price);
       printf(" enter the barcode :\n");
       scanf("%s",temp->barcode);
       printf(" how many / much is the number of product ?\n");
       scanf("%s",temp->number);

       return;
   }

void add_product(void)
   {
       system("cls");
       FILE *o ;
       int num , n , c;
       char bar[10] , new_num[10] ;
       int n_num ;
       struct product *temp , *ptr , *temp2;

       o = fopen("product.txt","r+");
       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
           ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);


               printf("**** HELP : barcods are usually like this nnana00n\n the first double n is for the first category\n the a for first alphabet of model\n the n for the first char of number of taste \n");
               printf(" the a for first char of brand \n the last n for the first char of the price\n\n\n");

               printf(" please enter the barcode : \n");
               fflush(stdin);
               gets(bar);

               ptr = first;
               while(ptr != NULL)
               {
                    if (strcmp(bar , ptr->barcode)== 0)         //finding barcode
                    {
                      c=1;
                      break;
                    }
                    ptr = ptr -> next;
               }


               if(c == 1)
               {
                   printf(" how many products do you want to increase ?\n");
                   scanf("%d",&num);
                   n = atoi(ptr->number);                //changing string to int
                   n_num = n+num;                         //adding
                   itoa(n_num , new_num , 10);            //changing int to string
                   strcpy(ptr->number , new_num);          //rewrite the string

                   printf(" << successfully done >>");
                   Sleep(3000);

                   o = fopen("product.txt" ,"w");
                   temp = first;
                   while (temp != NULL)
                   {
                     fwrite(temp,sizeof(struct product),1,o);            //rewrite the linked list in file
                     if (fwrite != 0)
                        printf("success!\n");
                     temp = temp -> next;
                   }
                   fclose(o);

                   program_parts();
               }
               else
                if(c != 1)
                {
                   printf(" the barcode is wrong\n");
                   Sleep(2000);
                   program_parts();
                }

       }
   }

void decrease_product(void)
   {
       system("cls");
       FILE *o ;
       int num , n , c;
       char bar[10] , new_num[10] ;
       int n_num ;
       struct product *temp , *ptr , *temp2;

       o = fopen("product.txt","r");
       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
               ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);


               printf("**** HELP : barcods are usually like this nnana00n\n the first double n is for the first category\n the a for first alphabet of model\n the n for the first char of number of taste \n");
               printf(" the a for first char of brand \n the last n for the first char of the price\n\n\n");

               printf(" please enter the barcode : \n");
               scanf("%s",bar);

               ptr = first;
               while(ptr != NULL)
               {
                    if (strcmp(bar , ptr->barcode) == 0)         //finding barcode
                    {
                      c=1;
                      break;
                    }
                    ptr = ptr -> next;
               }

               if(c == 1)
               {
                   printf(" how many products do you want to increase ?\n");
                   scanf("%d",&num);
                   n = atoi(ptr->number);                   //changing string to int

                   // cheking
                   if (num > n)
                   {
                      printf(" there is not enough in the warehouse");
                      return;
                   }
                   else
                     if(num <= n)
                     {
                        n_num = n - num ;                     //reducing
                        itoa(n_num , new_num , 10);           //changing int to string
                        strcpy(ptr->number , new_num);        //rewrite the string

                        printf(" << successfully done >>");
                        Sleep(3000);

                        o = fopen("product.txt" ,"w");
                        temp = first;
                        while (temp != NULL)
                        {
                          fwrite(temp,sizeof(struct product),1,o);            //rewrite the linked list in file
                          if (fwrite != 0)
                            printf("success!\n");

                          temp = temp -> next;
                        }
                        fclose(o);

                        program_parts();
                     }
               }
               else
                if(c != 1)
                {
                   printf(" the barcode is wrong\n");
                   Sleep(2000);
                   program_parts();
                }
            }
       }


int reports(void)
   {
       int rep ;

       printf(" ----> there is several kind of reports for you .\n      please enter the part you want .\n\n");
       printf(" 1 - number of each product \n");
       printf(" 2 - products with more than 50 number \n");
       printf(" 3 - products with less than 10 number \n");
       printf(" 4 - value of all products \n");
       printf(" 5 - value of a product \n");
       printf(" 6 - added product \n");
       printf(" 7 - reduced product \n");
       printf(" 8 - both 6 & 7\n");
       printf(" 9 - user transaction \n");
       printf(" 10 - users list \n");
       printf(" 11 - return to main menu \n");
       printf(" --> ");
       scanf("%d",&rep);
       system("cls");


       switch (rep)
       {
       case 1 :
        n_product();
        break;

       case 2 :
        more_products();
        break;

       case 3 :
        less_products();
        break;

       case 4 :
        v_all();
        break;

       case 5 :
        v_product();
        break;

       case 6 :
        added();
        break;

       case 7 :
        reduced();
        break;

       case 8 :
        add_reduced();
        break;

       case 9 :
        u_transaction();
        break;

       case 10 :
        u_list();
        break;

       case 11 :
        program_parts();
        break;

       default :
        printf(" !! wrong !! \n");
        system("cls");
        Sleep(2000);
        program_parts();
       }
   }

int n_product(void)
   {
       FILE *o;
       struct product *temp , *ptr , *temp2;

       o = fopen("product.txt","r");
       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
           printf("----> This is the number of all products :\n");

            ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);

            //printing linked list
            ptr = first;
            while(ptr != NULL)
            {
                printf(" product barcode : %s \n",ptr->barcode);
                printf(" product number : %s \n",ptr->number);
                printf(" ***************************************\n");
                ptr = ptr->next;
            }
            reports();
       }
   }

int more_products(void)
   {
       FILE *o;
       struct product *temp , *ptr , *temp2;
       int n , c=0 ;

       o = fopen("product.txt","r");
       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
           printf("----> These are products with more than 50 numbers :\n");

           ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);

            //printing linked list
            ptr = first;
            while(ptr != NULL)
            {
                n = atoi(ptr->number);                           //changing string to int

                if(n>50)
                {
                   c=1;
                   printf(" product barcode : %s \n",ptr->barcode);
                   printf(" product number : %s \n",ptr->number);
                   printf(" ***************************************\n");
                }

                ptr = ptr->next;
            }

            if(c != 1)
                printf("\n\n no product \n\n");

            reports();
       }
   }

int less_products(void)
   {
       FILE *o;
       struct product *temp , *ptr , *temp2;
       int n , c=0 ;

       o = fopen("product.txt","r");
       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
           printf("----> These are products with less than 10 numbers :\n");

           ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);

            //printing linked list
            ptr = first;
            while(ptr != NULL)
            {
                n = atoi(ptr->number);                           //changing string to int

                if(n<10)
                {
                   c=1;
                   printf(" product barcode : %s \n",ptr->barcode);
                   printf(" product number : %s \n",ptr->number);
                   printf(" ***************************************\n");
                }

                ptr = ptr->next;
            }

            if(c != 1)
                printf("\n\n no product \n\n");

            reports();
       }
   }

int v_all(void)
   {
       FILE *o;
       struct product *temp , *ptr , *temp2;
       int n , p;
       long long int sum=0 ;

       o = fopen("product.txt","r");
       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
           ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);

            //searching in linked list
            ptr = first;
            while(ptr != NULL)
            {
                n = atoi(ptr->number);                           //changing string to int
                p = atoi(ptr->price);

                sum = sum + (n*p);                               //calculating price of all products

                ptr = ptr->next;
            }

            printf("\n-----> the value of total products is : %d \n\n",sum);
            Sleep(3000);
            reports();

       }
   }

int v_product(void)
   {
       char check[10];
       FILE *o;
       struct product *temp , *ptr , *temp2;
       int n , p;
       long int sum = 0;

       o = fopen("product.txt","r");

       if(o == NULL)
       {
           printf(" the file cannot be opened");
           start();
       }
       else
       {
           ptr = malloc(sizeof(struct product));

            // making linked list from the file
            while(fread(ptr , sizeof(struct product) , 1 , o))
            {
               if (first == NULL)
               {
                 first = malloc(sizeof (struct product));
                 strcpy (first -> kind , ptr -> kind);
                 strcpy (first -> model , ptr -> model);
                 strcpy (first -> n_taste , ptr -> n_taste);
                 strcpy (first -> brand , ptr ->brand);
                 strcpy (first -> s_date , ptr -> s_date);
                 strcpy (first -> e_date , ptr -> e_date);
                 strcpy (first -> price , ptr -> price);
                 strcpy (first -> barcode , ptr -> barcode);
                 strcpy (first -> number , ptr -> number);
                 first -> next = NULL;
               }
               else
               {
                 temp = first;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct product));
                 strcpy (temp -> kind , ptr -> kind);
                 strcpy (temp -> model , ptr -> model);
                 strcpy (temp -> n_taste , ptr -> n_taste);
                 strcpy (temp -> brand , ptr -> brand);
                 strcpy (temp -> s_date , ptr -> s_date);
                 strcpy (temp -> e_date , ptr -> e_date);
                 strcpy (temp -> price , ptr -> price);
                 strcpy (temp -> barcode , ptr -> barcode);
                 strcpy (temp -> number , ptr -> number);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);

            printf("-----> what is the products you want :\n");
            printf(" enter the barcode :\n");
            getchar();
            gets(check);

            //searching in linked list
            ptr = first;
            while(ptr != NULL)
            {
                if(strcmp(ptr->barcode , check)== 0)
                {
                    n = atoi(ptr->number);                           //changing string to int
                    p = atoi(ptr->price);

                    sum = n*p;                                       //calculating the price

                    printf("\n-----> the value of total products is : %d \n\n ",sum);
                    break;
                }
                ptr = ptr->next;
            }
            Sleep(3000);
            reports();
       }
   }

int added(void)
   {
       printf("-----> this is the list of adding products :\n\n\n\n");
       printf(" sorry i cant report , i could not find a way \n\n");
       Sleep(3000);
       reports();
   }

int reduced(void)
   {
       printf("-----> this the list of reducing products :\n\n\n\n");
       printf(" sorry i cant report , i could not find a way \n\n");
       Sleep(3000);
       reports();
   }

int add_reduced(void)
   {
       printf("-----> what is the products you want :\n\n\n\n");
       printf(" sorry i cant report , i could not find a way \n\n");
       Sleep(3000);
       reports();
   }

int u_transaction(void)
   {
       char uname[10];

       if(strcmp(username , "admin")==0)
       {
          printf(" sorry i cant report , i could not find a way \n\n");
          Sleep(3000);
          reports();
       }
       else
       {
           printf(" !! This part is lock for you !!");
           Sleep(2000);
           system("cls");
           reports();
       }
   }

int u_list(void)
   {
       FILE *o ;
       struct inf *temp ,*ptr, *temp2;

       if(strcmp(username , "admin")==0)
       {
           o = fopen("user_information.txt","r");

           if(o == NULL)
           {
              printf(" the file con not be opened");
              start();
           }
           else
           {
              ptr = malloc(sizeof(struct inf));

              // making linked list from the file
              while(fread(ptr , sizeof(struct inf) , 1 , o))
              {
                 if (beginning == NULL)
                 {
                   beginning = malloc(sizeof (struct inf));
                   strcpy (beginning -> f_name , ptr -> f_name);
                   strcpy (beginning -> l_name , ptr -> l_name);
                   strcpy (beginning -> u_name , ptr -> u_name);
                   strcpy (beginning -> pass , ptr -> pass);
                   strcpy (beginning -> email , ptr -> email);
                   strcpy (beginning -> t_number , ptr -> t_number);
                   strcpy (beginning -> id , ptr -> id);
                   beginning -> next = NULL;
                 }
                 else
                 {
                   temp = beginning;
                   while (temp -> next != NULL)
                   {
                     temp = temp -> next;
                   }
                   temp2 = temp;
                   temp = malloc(sizeof(struct inf));
                   strcpy (temp -> f_name , ptr -> f_name);
                   strcpy (temp -> l_name , ptr -> l_name);
                   strcpy (temp -> u_name , ptr -> u_name);
                   strcpy (temp -> pass , ptr -> pass);
                   strcpy (temp -> email , ptr -> email);
                   strcpy (temp -> t_number , ptr -> t_number);
                   strcpy (temp -> id , ptr -> id);
                   temp -> next = NULL;
                   temp2 -> next = temp;
                 }
              }
              fclose(o);

              printf("-----> This is the list of users :\n");

              //searching in linked list to find the correct user name
              ptr = beginning;
              while( ptr != NULL)
              {
                 printf(" first name : %s\n",ptr->f_name);
                 printf(" last name : %s\n",ptr->l_name);
                 printf(" user name : %s\n",ptr->u_name);
                 printf("*******************************\n");
                 ptr = ptr -> next;
              }

              Sleep(5000);
              reports();

           }
       }
       else
       {
           printf(" !! This part is lock for you !!");
           Sleep(2000);
           system("cls");
           reports();
       }
   }

int account_setting(void)
   {
       FILE *o ;
       struct inf *temp ,*ptr, *temp2;
       char new_pass[10];

       o = fopen("user_information.txt","r");

        if(o == NULL)
        {
            printf(" the file con not be opened");
            start();
        }
        else
        {
            ptr = malloc(sizeof(struct inf));

            // making linked list from the file
            while(fread(ptr , sizeof(struct inf) , 1 , o))
            {
               if (beginning == NULL)
               {
                 beginning = malloc(sizeof (struct inf));
                 strcpy (beginning -> f_name , ptr -> f_name);
                 strcpy (beginning -> l_name , ptr -> l_name);
                 strcpy (beginning -> u_name , ptr -> u_name);
                 strcpy (beginning -> pass , ptr -> pass);
                 strcpy (beginning -> email , ptr -> email);
                 strcpy (beginning -> t_number , ptr -> t_number);
                 strcpy (beginning -> id , ptr -> id);
                 beginning -> next = NULL;
               }
               else
               {
                 temp = beginning;
                 while (temp -> next != NULL)
                 {
                     temp = temp -> next;
                 }
                 temp2 = temp;
                 temp = malloc(sizeof(struct inf));
                 strcpy (temp -> f_name , ptr -> f_name);
                 strcpy (temp -> l_name , ptr -> l_name);
                 strcpy (temp -> u_name , ptr -> u_name);
                 strcpy (temp -> pass , ptr -> pass);
                 strcpy (temp -> email , ptr -> email);
                 strcpy (temp -> t_number , ptr -> t_number);
                 strcpy (temp -> id , ptr -> id);
                 temp -> next = NULL;
                 temp2 -> next = temp;
               }
            }
            fclose(o);

            ptr = beginning;
            while( ptr != NULL)
            {
               if(strcmp (username , ptr->u_name)==0)
               {
                  printf("---> you can change the password :\n");
                  printf("enter your new password\n 8 character & number\n");
                  scanf("%s",new_pass);

                  strcpy(ptr->pass , new_pass);

                  break;
               }
               ptr = ptr -> next;
            }

            o = fopen("user_information.txt" ,"w");
            temp = beginning;
            while (temp != NULL)
            {
               printf("we are here!\n");
               fwrite(temp,sizeof(struct inf),1,o);            //rewrite the linked list in file
                if (fwrite != 0)
                    printf("success!\n");

                temp = temp -> next;
            }
            fclose(o);

            printf(" New password for you ");
            Sleep(2000);
            system("cls");
            start();
        }
   }

