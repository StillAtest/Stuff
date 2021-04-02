/*N people form a circle, start counting from the first one;
 *the M-th will be killed, and the last one will be left;
 *and the rest will be killed. For example;
 *N=6, M=5, the order of being killed is: 5, 4, 6, 2, 3;
 *StudentId:202010420227;
 *Date:3.27 */

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

//The structure of the circular linkedlist
typedef struct double_link{
    //struct double_link *pro;
    int data;
    struct double_link *next;
}link;

link *initLink(int n){
    //To create a single linkedlist
    link *p=(link*)malloc(sizeof(link));
    p->data=1;
    p->next=NULL;
    link *temp=p;//The structure that used for transforming the data
    for(int i=2;i<=n;i++){
        link* a=(link*)malloc(sizeof(link));
        a->data=i;
        //printf("------%d\n",a->data);
        a->next=NULL;
        temp->next=a;//The former pointer point at the latter one
        temp=temp->next;
    }
    //To start the circular linkedlist,the last pointer will point at the first position
    temp->next=p;
    printf("Initializing finished.\n");
    return p;
}


void display(link* p){
    link* temp=p;
    do{
        printf("Printf the primary value：%d\n",temp->data);
        temp=temp->next;
    }while (temp->next!=p->next);
    
}

//Where to make this game; start with which number; how many people were aparted
int findAndKillK(link *p,int k, int m){

    //To fine k
    link *find=p;
    while (find->data!=k) {
        
        find=find->next;
    }
    printf("Has found number k：%d\n",find->data);
    //Now the find->data is k
    //Starting from number k, it ends when only one is left. Others have been eliminated
    link * temp2=NULL;
    while (find!=find->next) {
        //Find the number 1 and the next number 2. Find the position of the number m, and eliminate it; do it again
        //Find the one before m first, which is why i<m
        for(int i=1;i<m;i++){
            temp2 = find;
            find=find->next;
        }
        printf("Delete：%d\n",find->data);
        temp2->next=find->next; //Pick the find node from the linked list
        free(find);
        find = temp2->next;
        
    }
    return find->data;
}

int main()
{
    link *p=initLink(5);
    display(p);
    int num=findAndKillK(p, 3, 2);
    printf("Print the final number：%d\n",num);
    system("pause");
    return 0;
}