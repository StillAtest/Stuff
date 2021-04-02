/*A program to solve a common question;
 *StudentId:202010420227;
 *Date:3.7 */
#include<stdio.h>
#include<windows.h>

//The main algorithm to calcute the original number of peaches//
int peachcount(int n)
{
    int count=1;
    int i;
    for(i=1;i<n;++i)
    {
        count=(count+1)*2;//This is what we've got from the question
    }
    return count;
}
int main()
{
    int n,count;
    printf("q for monkey's peaches\n");
    printf("which day was there exist only 1 peach?");//To get the limit
    scanf("%d",&n);
    count=peachcount(n);//To assign the result to count
    printf("%dday\n",n);
    printf("the number of peaches gotten in the 1st day is %d\n",count);//To print the result
    system("pause");
    return 0;
}