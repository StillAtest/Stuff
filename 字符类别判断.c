/*The program is to judge the type of the character
 *StudentId:202010420227;
 *Date:3.15 */
#include<stdio.h>
#include<windows.h>
int main()
{
    char c;
    printf("\n input a character");
    c=getchar();//To get an input of the character
    if(c<32)//If the ASCII number less than 32,it means a control character
        printf("\nit's a control character.\n");
    else if(c>='0'&&c<='9')//A number
        printf("\nit's a number\n");
    else if(c>='A'&&c<='Z')//an upper case character
        printf("\nit's an upper case character\n");
    else if("c>='a'&&c<='z'")//a lower case letter
        printf("\n it's a lower case letter\n");
    else//it's an another character
        printf("it's an another character\n");
    system("pause");
    return 0;
}