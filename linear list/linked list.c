//���Խṹ ������
/**
 * InitList(&L):��ʼ��һ��˳���
 * DestoryList(&L):����һ��˳���
 * ListEmpty(L):�ж�˳����Ƿ�Ϊ��
 * ListLength(L):��ȥ˳����Ԫ�ظ���
 * DisplayList(L):����˳���
 * GetElem(L,i,&e):ͨ��������ȡĳ��Ԫ�ز�����
 * LocateElem(L,e):����Ԫ���Ƿ����
 * ListInsert(&L,i,e):����Ԫ��
 * ListDelete(&L,i,&e):ɾ��Ԫ��
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
    printf("������Ҫ�����������ȣ�\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        printf("�������%d��������");
        printf("�������%d�����䣺");
        printf("�������%d���Ա�");

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



