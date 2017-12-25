#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 25
#define M 10
typedef struct{
  char  name[20];
  int   price;
} Record;
int main(int argc,char *argv[])
{
  int i=0,count;
  Record drink[N];
  FILE *fp;
  char choosedrink[M];
  int mustpay,lackmoney,must,extra;
  char rorc;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("read file %s open error!\n",argv[1]);
    exit(1);
  }
  printf("----------DRINK-----------\n");
  while(fscanf(fp,"%s%d",drink[i].name,&drink[i].price)!=EOF){
    printf("%s %d$\n",drink[i].name,drink[i].price);
    i++;
  }
  printf("---------------------------\n");
  printf("\nChoose your wanting drink(ex.Fanta)\n");
  scanf("%s",choosedrink);
  count=i;
  for(i=0;i<count;i++){
    if(strcmp(choosedrink,drink[i].name)==0){              /*(strncmp(str,"Bad",3))==0*/
      printf("\nIt's OK. %s is %d pay\nHow much is your trying to put money??\n",drink[i].name,drink[i].price);
      break;
    }
  }
  while(1){
    scanf("%d",&mustpay);
    if(mustpay<drink[i].price){
      printf("\nyour put money is lack of %d.\ncharge lack of money?? (c) or reset?? (r)\n",drink[i].price-mustpay);
      lackmoney=drink[i].price-mustpay;
      scanf("%c",&rorc);
      if(rorc=='c'){
        printf("\nYou must pay extra %d equal or more.\n",lackmoney);
        scanf("%d",&must);
        extra=must-lackmoney;
        printf("\nYou bought %s\n",choosedrink);
        printf("extra money is %d\n\n",extra);
        break;
      }
      if(rorc=='r'){
        continue;
      }
    }
    if(mustpay==drink[i].price){
      printf("\nYou are kind person.I'm easy mind.You bought %s.\n",choosedrink);
      break;
    }
    if(mustpay>drink[i].price){
      printf("\nYou bought %s\n",choosedrink);
      printf("extra money is %d\n\n",mustpay-drink[i].price);
      break;
    }
  }
  return 0;
}
