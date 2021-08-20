/* Declaration Of Header Files */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>//for string operations
char *a[100],*b[100];
int l,k,No2=0,j,i;
char *t,*m;
int Scan(char *a[100]);
int QuickS(char *a[100],int,int);
void Disp1();
void Split(int,int);
void MergeS(int,int,int);
void Disp2();
/* Start Of Main Program */
int main()
{
 int No1 = 0;
 printf("\nWelcome to 'Quick' And 'Merge' types of sorting program :");
 do
12
 {
 printf("\nPlease select one of the following options :");
 printf("\n1. Quick Sorting");
 printf("\n2. Merge Sorting");
 printf("\n3. Exit from menu");
 printf("\nPlease enter your choice here : ");
 scanf("%d",&No1);
 switch(No1)
 {
 case 1: No2 = (Scan(a));
 l = 0;
 QuickS(a , l , No2); // Call To The Function.
 Disp1();
 break;
 case 2: No2 = (Scan(a));
 Split(0,No2-1);
 Disp2();
 break;
 case 3: exit (0);
 break;
 default:printf("\nSorry! Invalid choice. ");
 }
 }
13
 while(No1 <= 3);
 getch();
}
int Scan(char *a[100])
{
 int i;
 printf("\nPlease enter the limit of array A : ");
 scanf("%d",&No2);
 printf("\nPlease enter the strings for array A : ");
 for(i=0;i<No2;i++)
 {
 scanf("%s",&a[i]);
 }
 for(i=0;i<No2;i++)
 {
 printf("%s",a[i]);
}
 return (No2);
}
int QuickS(char *a[],int l,int No2)
{
 if(l >= No2)
 return(0);
14
 k=l;
 i=l;
 j=No2;
 m=a[i];
 do

{
 do

{
 i++;

}
 while(a[i]<=m && i<No2);
 do

{

j--
;

}
 while(a[j]>=m && j>l);
 if(i<j)

{
 t=a[i];
 a[i]=a[j];
 a[j]=t;

}

}
15
 while(i<j);
 t=a[j];
 a[j]=m;
 a[k]=t;
 QuickS(a,l,j);
 QuickS(a,j+1,No2);
 return(0);
}
void Disp1()
{
 printf("\nQuick Sorted array 'A' is as follows : ");
 for(i=0;i<No2;i++)
 {
 printf("%s\n",a[i]);
 }
}
void MergeS(int low,int mid,int high)
{
 int i,h,j,k;
 i=low;
 h=low;
 j=mid+1;
16
 while(h <= mid && j <= high)

{
 if(a[h] < a[j])

{
 b[i] = a[h];
 h++;

}
 else

{
 b[i] = a[j];
 j++;

}
 i++;

}
 if( h > mid )

{
 for(k=j ; k <= high ; k++)

{
 b[i] = a[k];
 i++;

}

}
 else
17
 {
 for(k=h ; k<= high ; k++)
 {
 b[i] =a[k];
 i++;
 }
 }
 for(k=low ; k <= high ; k++)
 a[k] = b[k];
}
void Split(int low,int high)
{
 int mid;
 if(low<high)
 {
 mid = (low+high)/2;
 Split(low,mid);
 Split(mid+1,high);
 MergeS(low,mid,high); // Call to the function.
 }
}
void Disp2()
18
{
 printf("\nMerge Sorted array 'A' is as follows : ");
 for(i=0;i<No2;i++)
 {
 printf("%s\n",a[i]);
 }
}