#include<stdio.h>
float square(float n)
 {
int i;
float s;
s=n/2;
for(i=0;i<n;i++)
 {
s=(s+(n/s))/2;
 }
return s;
 }
int main(void)
 {
float num,res;
printf("\n enter a number : ");
scanf("%f",&num);
if(num>=0)
 {
if(num == 0)
res=0;
else if(num==1)
res=1;
else
res=square(num);
printf("square root of %f is %f\n",num,res);
printf("square root of %f using library function %f\n",num,sqrt(num));
 }
else
printf("\n imaginary number");
return 0;
 }
