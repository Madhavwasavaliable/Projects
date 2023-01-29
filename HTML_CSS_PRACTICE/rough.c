#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,flag=0,num=0,count=0;
    scanf("%d",&a);
    for(int i=2;i<=100000;i++)
    {
        for(int j=1;j<=i;j++)
        {   
            num=0;
            if(i%j==0)
            flag++;
        }
        if(flag==2)
        {
            num=i+a;
            for(int k=1;k<=num;k++)
            {
                if(num%k==0)
                count++;
            }
            if(count!=2)
            {
            printf("%d",i);
            exit(0);
            }
        }
  }
}