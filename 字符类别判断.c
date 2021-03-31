#include<stdio.h>
#include<windows.h>
int main()
{
    char c;
    printf("\n input a character");
    c=getchar();
    if(c<32)
        printf("\nit's a character for controlling.\n");
    else if(c>='0'&&c<='9')
        printf("\nit's a number\n");
    else if(c>='A'&&c<='Z')
        printf("\nit's an upper case character\n");
    else if("c>='a'&&c<='z'")
        printf("\n it's a lower case letter\n");
    else
        printf("it's an another character\n");
    system("pause");
    return 0;
}