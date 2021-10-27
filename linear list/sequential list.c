//���Խṹ ˳���
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
    printf("������˳����ж��ֵ(����,�س�����,-1��������):\n");
    int Elem=0;
    L->length=0;
    scanf("%d",&Elem);
    while (Elem!=-1)
    {
        L->data[L->length]=Elem;
        L->length++;
        scanf("%d",&Elem);
    }
    printf("��ʼ����ϣ�\n");
    return 0;
}
int DestoryList(SqList *L)
{
    L=NULL;
    printf("������ϣ�\n");
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
    printf("������ɣ�\n");
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
    printf("ɾ����ɣ�\n");
    return 1;
}
int main()
{
    SqList mySqList;
    InitList(&mySqList);
    //
    if(ListEmpty(mySqList))
        printf("��Ϊ�գ�\n");
    else
        printf("Ϊ�գ�\n");
    DisplayList(mySqList);
    printf("����Ϊ��%d\n",ListLength(mySqList));
    //
    int Elem,index;
    printf("�������ѯ������ֵ��");
    scanf("%d",&index);
    GetElem(mySqList,index,&Elem);
    printf("��ѯ��ֵΪ��%d\n",Elem);
    //
    if(LocateElem(mySqList,Elem))
        printf("Ԫ��%d����\n",Elem);
    else
        printf("Ԫ��%d������\n",Elem);
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