/*To judge the level of the students;
 *StudentId:202010420227;
 *Date:3.5 */
#include<stdio.h>
#include<windows.h>
int main()
{
    float grade;
    printf("\ninput your grades\n");
    scanf("%f",&grade);//To get the input
    if(grade>=90)//The first level of judgement
        printf("\n优\n");
    else if((grade>=80)&&(grade<90))//The second level of judgement
        printf("\n良\n");
    else if((grade>=60)&&(grade<80))//The third level of judgement
        printf("\n中\n");
    else //The last level of judgement
        printf("\n差\n");
    system("pause");
    return 0;
}