#include<stdio.h>
#include<windows.h>
int main()
{
    int year;
    printf("\n input the year number:\n");
    scanf("%d",&year);
    if((year%4==0&&year%100!=0)||(year%400==0))
        printf("\n%d年是闰年",year);
    else
        printf("\n%d年不是闰年",year);
    system("pause");
    return 0;
}