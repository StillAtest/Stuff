/**通过一趟排序将要排序的数据分割成独立的两部分;
 *其中一部分的所有数据都比另外一部分的所有数据都要小;
 *然后再按此方法对这两部分数据分别进行快速排序;
 *整个排序过程可以递归进行;
 *以此达到整个数据变成有序序列;
 *StudentId:202010420227;
 *Date:3.31 */

#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
#define BUF_SIZE 10

/* *Function: print array elements
   *Parameters: array-the array to be printed, maxlen-the number of array elements
   *Return value: none */

void display(int array[], int maxlen)
{
    int i;
 
    for(i=0;i<maxlen;i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");
 
    return ;
}

/* Return value: none */
void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int k = arr[low];
        while (i < j)
        {
            while(i < j && arr[j] >= k)     // To find the first number less than k from right to left
            {
                j--;
            }
 
            if(i < j)
            {
                arr[i++] = arr[j];
            }
 
            while(i < j && arr[i] < k)      // To find the first number greater than or equal to k from left to right
            {
                i++;
            }
 
            if(i < j)
            {
                arr[j--] = arr[i];
            }
        }
        arr[i] = k;
 
        //Recursive call
        QuickSort(arr, low, i - 1);     // To sort the left side of k
        QuickSort(arr, i + 1, high);    // To sort the right side of k
    }
}
 
//The main function
int main()
{
    int array[BUF_SIZE] = {12,85,25,16,34,23,49,95,17,61};
    int maxlen = BUF_SIZE;    
    printf("Array before sorting\n");
    display(array, maxlen);    
    QuickSort(array, 0, maxlen-1);  // Quick Sort  
    printf("Sorted array\n");
    display(array, maxlen);
    system("pause");
    return 0;
}
