/**基本思想是，将元素逐个添加到已经排序好的数组中去，
 *同时要求，插入的元素必须在正确的位置，这样原来排序好的数组是仍然有序的。*/

#include<stdio.h>
#include<stdlib.h>
#define N 8
void insert_sort(int a[],int n);
//Insertion sorting is implemented, here is sorted from small to large
void insert_sort(int a[],int n)//n is the number of elements in array a
{
    //To perform N-1 round insertion process
    for(int i=1; i<n; i++)
    {
        //First find the position where the element a[i] needs to be inserted
        int j=0;
        while( (a[j]<a[i]) && (j<i))
        {
            j++;
        }
        //Insert the element in the correct position
        if(i != j)  //If i==j, it means that a[i] happens to be in the correct position
        {
            int temp = a[i];
            for(int k = i; k > j; k--)
            {
                a[k] = a[k-1];
            }
            a[j] = temp;
        }
    }
}
int  main()
{
    int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};
    insert_sort(num, N);
    for(int i=0; i<N; i++)
        printf("%d  ", num[i]);
    printf("\n");
    system("pause");
    return 0;
}