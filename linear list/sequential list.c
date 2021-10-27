//线性结构 顺序表
/**
 * InitList(&L):初始化一个顺序表
 * DestoryList(&L):销毁一个顺序表
 * ListEmpty(L):判断顺序表是否为空
 * ListLength(L):回去顺序表的元素个数
 * DisplayList(L):遍历顺序表
 * GetElem(L,i,&e):通过索引获取某个元素并返回
 * LocateElem(L,e):查找元素是否存在
 * ListInsert(&L,i,e):插入元素
 * ListDelete(&L,i,&e):删除元素
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;


int InitList(SqList *L)
{
    printf("请输入顺序表中多个值(数字,回车键入,-1结束输入):\n");
    int Elem=0;
    L->length=0;
    scanf("%d",&Elem);
    while (Elem!=-1)
    {
        L->data[L->length]=Elem;
        L->length++;
        scanf("%d",&Elem);
    }
    printf("初始化完毕！\n");
    return 0;
}
int DestoryList(SqList *L)
{
    L=NULL;
    printf("销毁完毕！\n");
    return 0;
}
int ListEmpty(SqList L)
{
    if(L.length==0)
        return 0;
    else
        return 1;
}
int ListLength(SqList L)
{
    return L.length;
}
void DisplayList(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d   ",L.data[i]);
    printf("\n");
}
void GetElem(SqList L,int i,int *e)
{
    if(L.length+1<i)
        printf("Error over index!\n");
    else
        *e=L.data[i-1];
}
int LocateElem(SqList L,int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i]==e)        
            return 1;
        else
            return 0;
    }
    
}
int ListInsert(SqList *L,int i,int e)
{
    for (int j = 0; j < L->length-i+1; j++)
    {
        L->data[L->length-j+1]=L->data[L->length-j];
    }
    printf("插入完成！\n");
    L->length++;
    return 1;
}
void ListDelete(SqList *L,int i,int *e)
{
    for (int j = 0; j < L->length-i; j++)
    {
        L->data[i+j]=L->data[i+j+1];
    }
    L->length--;
    printf("删除完成！\n");
    return 1;
}
int main()
{
    SqList mySqList;
    InitList(&mySqList);
    //
    if(ListEmpty(mySqList))
        printf("不为空！\n");
    else
        printf("为空！\n");
    DisplayList(mySqList);
    printf("长度为：%d\n",ListLength(mySqList));
    //
    int Elem,index;
    printf("请输入查询的索引值：");
    scanf("%d",&index);
    GetElem(mySqList,index,&Elem);
    printf("查询的值为：%d\n",Elem);
    //
    if(LocateElem(mySqList,Elem))
        printf("元素%d存在\n",Elem);
    else
        printf("元素%d不存在\n",Elem);
    //
    ListInsert(&mySqList,index,Elem);
    DisplayList(mySqList);
    //
    ListDelete(&mySqList,index,&Elem);
    DisplayList(mySqList);
    //
    DestoryList(&mySqList);
    getchar();
    getchar();
    getchar();
}