#include<stdio.h>
#include<ctype.h>
#include<strings.h>
#include<stdlib.h>
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
struct product *make;
FILE *fp;
void main()
{
 fp = fopen("product.txt","w");
 make = malloc(sizeof(struct product));
 strcpy(make -> kind, "dri");
 strcpy(make -> model, "juice");
 strcpy(make -> n_taste, "10");
 strcpy(make -> brand, "lima");
 strcpy(make -> s_date, "01/11/01");
 strcpy(make -> e_date, "02/01/01");
 strcpy(make -> price, "10000");
 strcpy(make -> barcode, "11j1l001");
 strcpy(make -> number, "60");

 fwrite(make,sizeof(struct product),1,fp);
 if(fwrite != 0)
    printf("success!");
 fclose(fp);
}

