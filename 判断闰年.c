/*The program is used for judging whether the year is the leap year or not;
 *StudentId:202010420227;
 *Date:3.2 */
#include<stdio.h>
#include<windows.h>
int main()
{
    int year;
    printf("\n input the year number:\n");
    scanf("%d",&year);//To get an input of the number of the year
    if((year%4==0&&year%100!=0)||(year%400==0))//The analyzing condition of the leap year
        printf("\n%d is the leap year",year);
    else
        printf("\n%d is not the leap year",year);//The output of getting the non-compliant number
    system("pause");
    return 0;
}
