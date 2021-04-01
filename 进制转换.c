// A tiny calculator to solve common base conversion.//
#include<stdio.h>
#include<math.h>
#include<windows.h>

void mune()
{
    printf("******************************************************\n");
    printf("**                                                  **\n");
    printf("**                   common base conversion                    **\n");
    printf("**                                                  **\n");
    printf("**              1、Decimal conversion to Binary                 **\n");
    printf("**              2、Decimal conversion to Octal                 **\n");
    printf("**              3、Decimal conversion to Hexadecimal               **\n");
    printf("**              4、Binary conversion to Decimal                 **\n");
    printf("**              5、Octal conversion to Decimal                 **\n");
    printf("**              6、Hexadecimal conversion to Decimal               **\n");
    printf("**              0、Quit                              **\n");
    printf("**                                                  **\n");
    printf("******************************************************\n");
}

void TenToTwo()
{
    int num,m, c, i = 0;
    int n = 2;
    int a[32];
    printf("Input an integer：");
    scanf("%d", &num);
    m = num;
    while (num>0)
    {
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
    printf("The Binary number is：%d", m);
    for (i--; i >= 0; i--)           //To reverse the array's output
        printf("%d", a[i]);
    printf("\n");
}

void TenToEight()
{
    int num, m, c, i = 0;
    int n = 8;
    int a[32];
    printf("Input an integer：");
    scanf("%d", &num);
    m = num;
    while (num>0)
    {
        c = (num % n);
        a[i] = c;
        num = num / n;
        i++;
    }
    printf("The hexadecimal number is：", m);
    for (i--; i >= 0; i--)           //To reverse the array's output
        printf("%d", a[i]);
    printf("\n");
}

void TenToSixteen()
{
        char arr[] = "0123456789ABCDEF";//To make the array has the necessary symbols of the hexadecimal numbers
        char hex[16];//To make the array has 16 elements
        int i = 0;
        int j = 0;
        int num = 0,a = 0;
        printf("Input an integer：");
        scanf("%d", &num);
        a = num;
        while (num)
        {
            hex[i++] = arr[num % 16];   //Calculate the remainder of the decimal number and finally match the characters in the hextable array
            num = num / 16;
        }
        printf("The hexadecimal number is：", a);
        for (j = i - 1; j >= 0; --j)
            printf("%c", hex[j]);
        printf("\n");
}

void TwoToTen()
{   
        long long n,a;
        int sum = 0, i = 0, m;
        printf("Input a binnary number: ");
        scanf("%lld", &n);
        a = n;
        while (n != 0)
        {
            m = n % 10;
            n /= 10;
            sum += m*pow(2, i);//POW function here means 2^i
            ++i;
        }
        printf("The decimal number is %d\n",sum);
}

void EightToTen()
{
    int n, a;
    int sum = 0, i = 0, m;
    printf("Input an octal number: ");
    scanf("%d", &n);
    a = n;
    while (n != 0)
    {
        m = n % 10;
        n /= 10;
        sum += m*pow(8, i);//POW function here means 8^i
        ++i;
    }
    printf("The decimal number is %d\n", a, sum);
}

void SixteenToTen()
{
    int num = 0;
    printf("Input a hexadecimal number: ");
    scanf("%x", &num);
    printf("The decimal number is %d\n", num, num);//C has already provided such a conversion
}

int main()
{
    int n = 0;
    while (1)
    {
        mune();
        printf("Please select：");
        scanf("%d", &n);
        switch (n)//Selection
        {
        case 1:TenToTwo();
            break;
        case 2:TenToEight();
            break;
        case 3:TenToSixteen();
            break;
        case 4:TwoToTen();
            break;
        case 5:EightToTen();
            break;
        case 6:SixteenToTen();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("You've made a wrong operation!\n");
            break;
        }
    }
    system("pause");
    return 0;
}
