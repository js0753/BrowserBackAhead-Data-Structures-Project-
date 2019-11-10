#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{

   char x[100];
   struct stack *prev;

}s;

char c[100];
//char garbage;

void printStack(s *top){
printf("\nStack is :\n");
s *t;
t=top;
while(t!=NULL){
        int j=0;
while(t->x[j]!='\0')
printf("%c\n",t->x[j++]);
if(t->prev!=NULL)
t=t->prev;
else
break;

}

}

char * pop(s **top){

  s *temp;
  temp=*top;
  int j=0;
//puts((*top)->x);
while((*top)->x[j]!='\0'){
  c[j]=(*top)->x[j];
  j++;
}
c[j]='\0';
  *top=(*top)->prev;
  free(temp);
  //printf("\nPopped :");
  //puts(c);
  //printf("\n");

return c;
}

void push(s **top,char a[100]){
//printf("Push \n");

 s* temp;
temp=*top;
*top=(s*)malloc(sizeof(s));
int j=0;
while(a[j]!='\0'){
(*top)->x[j]=a[j];
j++;
}
(*top)->x[j]='\0';
(*top)->prev=temp;
//printStack(*top);
//printf("So far so good\n");
}

void display(char a[100]){
    int i;
system("cls");
printf("\n----------------------------------------------------------\nBrowser by Jainam Shah,B2,1811085\n----------------------------------------------------------\n");
for(i=0;i<10;i++)
printf("|\t\t\t\t\t\t\t\t|\n");
int j=0;
if(a[0]!='\0'&&strcmp(a,"Can't go back further")!=0&&strcmp(a,"Can't go ahead further")!=0)
printf("\t\t\tWELCOME TO\n\t\t\t");
if(97<=a[0]&&a[0]<=122)
    a[0]-=32;
while(a[j]!='\0'&&a[j]!='.'){
    printf("%c",a[j++]);
}
printf("\n");
for(i=0;i<10;i++)
printf("|\t\t\t\t\t\t\t\t|\n");
printf("----------------------------------------------------------\n");
printf("Enter Input(Press 1 to go back,2 for go ahead,3 to quit) : ");
}
int main()
{
    s *top=NULL;
    s *top1=NULL;
    int d=4;
    display("\0");
    while(d!=3){
    char a[100];
    gets(a);
    if(a[0]!='1'&&a[0]!='2'&&a[0]!='3')
    {
    display(a);
    push(&top,a);
    while(top1!=NULL)
        pop(&top1);
    }
    else if(a[0]=='1'){

        //pop(&top);
        if(top!=NULL){

        push(&top1,pop(&top));
        if(top!=NULL)
        display(top->x);
        else
        display("Can't go back further");

    }
        else
            display("Can't go back further");
    }
    else if(a[0]=='2'){
            if(top1!=NULL){
        display(top1->x);
        push(&top,pop(&top1));
            }
            else
                display("Can't go ahead further");
    }
    else if(a[0]=='3'){
        printf("Exiting Browser\n");
        //getch();
        d=3;
    }
    }

    return 0;
}
