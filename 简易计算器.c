#include<stdio.h>
#include<windows.h>
int main()
{
    int a,b;
    char op,answer='y';

    do
    {
        printf("simple calculator v1.0\n");
        printf("input 2 numbers and the");
        scanf("%d%c%d",&a,&op,&b);

        switch(op)
        {
            case'+':
                printf("%d+%d=%d\n",a,b,a+b);
                break;
            case'-':
                printf("%d-%d=%d",a,b,a-b);
                break;
            case'*':
                printf("%d*%d=%d",a,b,a*b);
                break;
            case'/':
                printf("%d/%d=%d",a,b,a/b);
                break;
            case'√':
                printf("√%d=%d,√%d=%d",a,sqrt(a),b,sqrt(b));
                break;
            case'~':
                printf("1/%d=%d,1/%d=%d",a,1.0/a,b,1.0/b);
                break;
            case'^':
                long double x,n;
                scanf("%ld%ld",&x,&n);
                for(int i=0;i<n;++i)
                {
                    x=x*x;
                }
                printf("x^n=%ld",x);
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

        printf("calculate again to input y or n");
        answer=getch();
    }while(answer=='y');
    system("pause");
    return 0;
}