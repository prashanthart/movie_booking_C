#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct mbooking
{
char name[30];
int data;
int nota;
int price;
int seat[30];
struct mbooking *next;
};
struct mbooking *root=NULL,*nn,*temp;
void payment(long long int);
void screen(int x)
{
int k,i,j;
switch(x)
{
case 1 : printf("1.****ALA VAIKUNTHAPURRAMLOO****\n");
printf(" _____________screen__________________\n");break;
case 2 : printf("2.****SARILERU NEEKEVVARU****\n");
printf(" ______________screen__________________\n");break;
case 3 : printf("3.****DARBAR****\n");
printf(" ______________screen__________________\n");break;
default : printf("movie not available");break;
}
if(x<4)
{
k=1;
for(i=1;i<=10;i++)
{
for(j=1;j<=10;j++)
{
printf("%4d",k++);
}
printf("\n");
}
}
}
int create()
{
int x,n,i,cou=0;
char c;
long long int ph,otp=1237;
do
{
nn=(struct mbooking*)malloc(sizeof(struct mbooking));
printf("\n*****WELCOME TO M-BOOKING*****\n");
printf(" 1.ALA VAIKUNTHAPURRAMLOO," );
printf("2.SARILERUNEEKEVVARU,3.DARBAR,4.exitbooking\n");
printf(" select one option :- ");
scanf("%d",&x);
screen(x);
if(x>=4)
break;
nn->data=x;
printf(" HOW MANY SEATS YOU WANT? :- ");
scanf("%d",&n);
nn->nota=n;
printf(" enter seat numbers\n");
for(i=0;i<n;i++)
{
scanf("%d",&nn->seat[i]);
nn->seat[i+1]=0;
}
nn->price=n*150;
printf("\n the price is %d/-",nn->price);
printf("\n enter your name : ");
scanf("%s",nn->name);
otp=otp+(++cou);
payment(otp);
nn->next=NULL;
if(root==NULL)
root=temp=nn;
else
{
temp->next=nn;
temp=temp->next;
}
printf("\n you booked a ticket");
printf("\n enter any key to book another ticket (or) to Exit and view ticket enter 'e' or 'E' :- ");
fflush(stdin);
cou++;
scanf("%c",&c);
if(c=='e' || c=='E')
break;
system("cls");
}while(1);
return cou;
}
void display(void)
{
int i;
if(root==NULL)
printf("\n please book the tickets");
else
{
printf(" your tickets are ready\n");
temp=root;
while(temp!=NULL)
{
printf(" __________________________________________________________\n");
switch(temp->data)
{
case 1 : printf(" Movie Name :- ALA VAIKUNTHAPURRAMLOO telugu 2d");break;
case 2 : printf(" Movie Name :- SARILERU NEEKEVVARU telugu 2d ");break;
case 3 : printf(" Movie Name :- DARBAR telugu 2d");break;
}
printf("\n Customer Name :- %s",temp->name);
printf("\n The Number Of Seats %d\n Seat No. :- ",temp->nota);
for(i=0;i<temp->nota;i++)
{
if(temp->seat[i]==0)
break;
printf(" %d",temp->seat[i]);
}
printf("\n The Total Price :- %d/-",temp->price);
printf("\n __________________________________________________________\n");
temp=temp->next;
}
}
}
void payment(long long int otp)
{
int a;
long long int otp1,ph;
printf("pay %d/- through 1.paytm, 2.G-pay, 3.credit card, 4.debit card",nn->price);
scanf("%d",&a);
switch(a)
{
case 1 : printf("paytm\n");break;
case 2 : printf("G-pay\n");break;
case 3 : printf("credit card\n");break;
case 4 : printf("debit card\n");break;
}
printf("enter your phone number :- ");
scanf("%lld",&ph);
otp :
printf("enter OTP %lld :- ",otp);
scanf("%d",&otp1);
if(otp==otp1)
printf("your payment is done\n");
else
{
printf("invalid otp\n");
goto otp;
}
}
void main()
{
system("cls");
create();
system("cls"); // instead use clrscr() in turbo c
display();
getch();
}
