//线性结构 单链表
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
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    char name[100];
    int age;
    char sex[10];
    LinkNode *next;
} LinkNode;

int InitList(LinkNode *L)
{
    int n=0;
    LinkNode *s;
    printf("请输入要创建的链表长度：\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        printf("请输入第%d名姓名：");
        printf("请输入第%d名年龄：");
        printf("请输入第%d名性别：");

    }
    
}
int DestoryList(SqList *L)
{
}
int ListEmpty(SqList L)
{
}
int ListLength(SqList L)
{
}
void DisplayList(SqList L)
{
}
void GetElem(SqList L,int i,int *e)
{
}
int LocateElem(SqList L,int e)
{
}
int ListInsert(SqList *L,int i,int e)
{
}
void ListDelete(SqList *L,int i,int *e)
{
}
int main(){

}



