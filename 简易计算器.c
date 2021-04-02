/*This is used for doing a simple calculation;
 *StudentId:202010420227;
 *Date:3.2 */
#include<stdio.h>
#include<windows.h>
int main()
{
    int a,b;
    char op,answer='y';//To define several variables

    do
    {
        printf("Input 2 numbers and the");
        scanf("%d%c%d",&a,&op,&b);

        switch(op)//Let the user choose which calculation method they want
        {
            case'+':
                printf("%d+%d=%d\n",a,b,a+b);//To plus the two numbers
                break;
            case'-':
                printf("%d-%d=%d",a,b,a-b);//To subtract the two numbers
                break;
            case'*':
                printf("%d*%d=%d",a,b,a*b);//To multiply the two numbers
                break;
            case'/':
                printf("%d/%d=%d",a,b,a/b);//To divide the two numbers
                break;
            case'√':
                printf("√%d=%d,√%d=%d",a,sqrt(a),b,sqrt(b));//To extract a root
                break;
            case'~':
                printf("1/%d=%d,1/%d=%d",a,1.0/a,b,1.0/b);//To find the reciprocal
                break;
            case'^':
                long double x,n;
                scanf("%ld%ld",&x,&n);
                for(int i=0;i<n;++i)
                {
                    x=x*x;
                }
                printf("x^n=%ld",x);//To get the square of the number
                break;
            case'&':
                int c,x1,x2;
                printf("Input the equation's a,b and c\n");
                scanf("%d %d %d", &a, &b, &c);//To get the values of there variables
                if (b*b-4*a*c<0)
                {
                    printf("No real roots");
                }//To judge whether there exist the real root
                else 
                {
                    x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
                    x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
                    printf("the output is：x1=%0.2f,x2=%0.2f", x1, x2);
                }//Printf the root if there exist the real one
            default:
                printf("input again\n");
                break;
        }

        printf("calculate again to input y or n");//If the user wants to calcute again
        answer=getch();
    }while(answer=='y');
    system("pause");
    return 0;
}