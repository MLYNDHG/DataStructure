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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LNode{
    char name[100];
    int age;
    char sex[10];
    struct LNode *next;
} LinkNode;

int InitList(LinkNode *L)
{
    int n=0;
    LinkNode * temp,*rear;
    rear=L;
    printf("请输入要创建的链表长度：\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        temp=(LinkNode *)malloc(sizeof(LinkNode));
        printf("请输入第%d名姓名：",i);
        scanf("%S",temp->name);
        printf("请输入第%d名年龄：",i);
        scanf("%d",&(temp->age));
        printf("请输入第%d名性别：",i);
        scanf("%s",temp->sex);
        rear->next=temp;//尾插法
        rear=temp;
        /**
         * 头插法：
         * temp->next=L->next;
         * L->next=temp;
         * 
        */
    }
    rear->next=NULL;
    printf("初始化完成！\n");
    return 0;
}
int DestoryList(LinkNode *L)
{
    LinkNode *pre=L,*p=L->next;
    while (p->next!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
    return 0;
}
int ListEmpty(LinkNode *L)
{
    if(L->next==NULL)
        return 1;
    else
        return 0;
}
int ListLength(LinkNode *L)
{
    LinkNode *temp=L;
    int length;
    while (temp->next!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
void DisplayList(LinkNode *L)
{
    LinkNode *temp=L->next;
    int length=0;
    while (temp!=NULL)
    {
        length++;
        printf("%d.姓名：%s  性别：%s   年龄：%d\n",length,temp->name,temp->sex,temp->age);
        temp=temp->next;  
    }
    return 0;
}
LinkNode * GetElem(LinkNode *L,int i)
{
    LinkNode *temp=L;
    for (int j = 0; temp->next!=NULL; j++)
    {
        if(i==j)
        {
            return temp;
        }
        temp=temp->next;
    }
}
int LocateElem(LinkNode * L,char * name)
{
    LinkNode *temp=L;
    while (temp->next!=NULL)
    {
        if(strcmp(name,temp->name)==0)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int ListInsert(LinkNode *L,int i,LinkNode * node)
{
    LinkNode *temp=L;
    for (int j = 0;temp->next!=NULL; j++)
    {
        if(i==j)
        {
            node=temp->next->next;
            temp->next=node;            
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void ListDelete(LinkNode *L,int i,LinkNode * node)
{
    LinkNode *temp=L;
    for (int j = 0;temp->next!=NULL; j++)
    {
        if(i==j)
        {
            node=temp;
            temp->next=temp->next->next; 
        }
        temp=temp->next;
    }
}
int main(){
    LinkNode *L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    //
    InitList(L);
    DisplayList(L);
    //
    ListEmpty(L)?printf("为空！\n"):printf("不为空！\n");
    //
    printf("链表长度为：%d\n",ListLength(L));
    DisplayList(L);
    //
    printf("输入要查找的索引：");
    int index;
    scanf("%d",&index);
    LinkNode * node=GetElem(L,index);
    printf("索引为%d：%s  %s  %d",index,node->name,node->sex,node->age);
    printf("输入要查找的姓名：");
    char name[100];
    scanf("%s",name);
    LocateElem(L,name)?printf("存在！\n"):printf("不存在！\n");
    LinkNode Insertnode;
    printf("插入：\n");
    printf("姓名：");
    scanf("%s",Insertnode.name);
    printf("性别：");
    scanf("%s",Insertnode.sex);
    printf("年龄：");
    scanf("%s",&(Insertnode.age));
    int num;
    printf("插入位置：");
    scanf("%d",&num);
    ListInsert(L,num,&Insertnode);
    DisplayList(L);

    printf("删除！\n");
    printf("删除位置：");
    scanf("%d",&num);
    LinkNode deletenode;
    ListDelete(L,num,&deletenode);
    DisplayList(L);
    DestoryList(L);
}



