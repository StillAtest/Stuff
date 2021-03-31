#include<stdio.h>
#include<windows.h>
int main()
{
    float grade;
    printf("\ninput your grades\n");
    scanf("%f",&grade);
    if(grade>=90)
        printf("\n优\n");
    else if((grade>=80)&&(grade<90))
        printf("\n良\n");
    else if((grade>=60)&&(grade<80))
        printf("\n中\n");
    else
        printf("\n差\n");
    system("pause");
    return 0;
}