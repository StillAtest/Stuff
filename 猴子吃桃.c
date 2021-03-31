#include<stdio.h>
#include<windows.h>

int peachcount(int n)
{
    int count=1;
    int i;
    for(i=1;i<n;++i)
    {
        count=(count+1)*2;
    }
    return count;
}
int main()
{
    int n,count;
    printf("q for monkey's peaches\n");
    printf("whhich day was there exist only 1 peach");
    scanf("%d",&n);
    count=peachcount(n);
    printf("%dday\n",n);
    printf("the number of peaches gotten in the 1st day is %d\n",count);
    system("pause");
    return 0;
}