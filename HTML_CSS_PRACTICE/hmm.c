#include<stdio.h>

int main(){
    int t, n, m=2, count=0, num=0, k=1;
    //scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 2; i <= 100000; i++)
    {
        for (int j = 2; j <= 100000; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
            if (j > i)
            {
                break;
            }
        }
        if (count == 0)
        {
            num = n + i;
            while (num > k)
            {
                if (num % k != 0)
                {
                    printf("%d", i);
                    break;
                }
                k++;   
            }   
        }
        count = 0;   
    }  
}