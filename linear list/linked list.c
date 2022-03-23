//���Խṹ ������
/**
 * InitList(&L):��ʼ��һ��˳���
 * DestoryList(&L):����һ��˳���
 * ListEmpty(L):�ж�˳����Ƿ�Ϊ��
 * ListLength(L):��ȥ˳�����Ԫ�ظ���
 * DisplayList(L):����˳���
 * GetElem(L,i,&e):ͨ��������ȡĳ��Ԫ�ز�����
 * LocateElem(L,e):����Ԫ���Ƿ����
 * ListInsert(&L,i,e):����Ԫ��
 * ListDelete(&L,i,&e):ɾ��Ԫ��
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
    printf("������Ҫ�������������ȣ�\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        temp=(LinkNode *)malloc(sizeof(LinkNode));
        printf("�������%d��������",i);
        scanf("%S",temp->name);
        printf("�������%d�����䣺",i);
        scanf("%d",&(temp->age));
        printf("�������%d���Ա�",i);
        scanf("%s",temp->sex);
        rear->next=temp;//β�巨
        rear=temp;
        /**
         * ͷ�巨��
         * temp->next=L->next;
         * L->next=temp;
         * 
        */
    }
    rear->next=NULL;
    printf("��ʼ����ɣ�\n");
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
        printf("%d.������%s  �Ա�%s   ���䣺%d\n",length,temp->name,temp->sex,temp->age);
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
    ListEmpty(L)?printf("Ϊ�գ�\n"):printf("��Ϊ�գ�\n");
    //
    printf("��������Ϊ��%d\n",ListLength(L));
    DisplayList(L);
    //
    printf("����Ҫ���ҵ�������");
    int index;
    scanf("%d",&index);
    LinkNode * node=GetElem(L,index);
    printf("����Ϊ%d��%s  %s  %d",index,node->name,node->sex,node->age);
    printf("����Ҫ���ҵ�������");
    char name[100];
    scanf("%s",name);
    LocateElem(L,name)?printf("���ڣ�\n"):printf("�����ڣ�\n");
    LinkNode Insertnode;
    printf("���룺\n");
    printf("������");
    scanf("%s",Insertnode.name);
    printf("�Ա�");
    scanf("%s",Insertnode.sex);
    printf("���䣺");
    scanf("%s",&(Insertnode.age));
    int num;
    printf("����λ�ã�");
    scanf("%d",&num);
    ListInsert(L,num,&Insertnode);
    DisplayList(L);

    printf("ɾ����\n");
    printf("ɾ��λ�ã�");
    scanf("%d",&num);
    LinkNode deletenode;
    ListDelete(L,num,&deletenode);
    DisplayList(L);
    DestoryList(L);
}



