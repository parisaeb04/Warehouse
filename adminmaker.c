#include<stdio.h>
#include<ctype.h>
#include<strings.h>
#include<stdlib.h>
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
struct inf *make;
FILE *fp;
void main()
{
 fp = fopen("user_information.txt","w");
 make = malloc(sizeof(struct inf));
 strcpy(make -> f_name, "admin");
 strcpy(make -> l_name, "admin");
 strcpy(make -> u_name, "admin");
 strcpy(make -> t_number, "admin");
 strcpy(make -> pass, "admin");
 strcpy(make -> email, "admin");
 strcpy(make -> id, "admin");
 fwrite(make,sizeof(struct inf),1,fp);
 if(fwrite != 0)
    printf("success!");
 fclose(fp);
}
