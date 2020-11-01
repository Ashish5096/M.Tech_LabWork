#include<stdio.h>
#include<time.h>
#include<math.h>

void big_O_n();
void big_O_n2();
void big_O_n3();
void exponential();

int main()
{

    big_O_n();
    big_O_n2();
    big_O_n3();
    exponential();

    return 0;
}

void big_O_n()
{
    clock_t start, end;
    unsigned int n=0;
    double sec = 0;

    start = clock();
    
    for(n=1;sec<1;n++)
    {
        end=clock();
        sec = (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Value of n with O(n) complexity in 1 second::  %u\n", n);
}


void big_O_n2()
{
    clock_t start, end;
    unsigned int n;
    double sec = 0;
    int flag=0,j;

    start = clock();
    
        for(n=1;;n++)
        {
            for(j=0;j<n;j++)
            {
                end=clock();
                sec = (double)(end - start) / CLOCKS_PER_SEC;
                if(sec>=1)
                {
                    flag=1;
                    break;
                }
            }

            if(flag==1)
                break;
        }

    printf("Value of n with O(n^2) complexity in 1 second::  %u\n", n);
}

void big_O_n3()
{
    clock_t start, end;
    unsigned int n;
    double sec = 0;
    int flag=0,j,k;

    start = clock();
    
        for (n=1;;n++)
        {
            for (j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    end = clock();
                    sec = (double)(end - start) / CLOCKS_PER_SEC;
                    if (sec >= 1)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 1)
                {
                    break;
                }
            }

            if (flag == 1)
            {
                break;
            }
        }


    printf("Value of n with O(n^3) complexity in 1 second::  %u\n", n);
}

void exponential()
{
    clock_t start, end;
    unsigned int n;
    double sec = 0;
    int flag=0,i,j,k;

    start = clock();
    
        for (n=1;;n++)
        {
            for (j = 0; j < pow(2,n); j++)
            {
                    end = clock();
                    sec = (double)(end - start) / CLOCKS_PER_SEC;
                    if (sec >= 1)
                    {
                        flag = 1;
                        break;
                    }
            }
            if (flag == 1)
            {
                break;
            }
        }

    printf("Value of n with O(2^n) complexity in 1 second::  %u\n", n);
}



