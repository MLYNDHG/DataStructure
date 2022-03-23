#define MaxSize 50
#include<stdio.h>
typedef struct{
    int data[MaxSize];
    int length;
} linearList;
void InitList(linearList **linear){
    //��ʼ��
    //main�������   ����Ϊһ������ָ��
    (*linear)=(linearList*)malloc(sizeof(linearList));
    (*linear)->length=0;
    printf("�ڴ˳�ʼ��\n");
    (*linear)->data[0]=123;
    (*linear)->data[1]=456;
    (*linear)->length=2;
};
void DestoryList(linearList **linear){
    printf("����˳������\n");
    (*linear)=NULL;
};
void ListEmpty(linearList **linear){    
    printf("����˳��������գ�\n");
    InitList((*linear));
};
int ListLength(linearList **linear){
    return (*linear)->length;
};
void DisplayList(linearList **linear){
    printf("�������У�\n");
    for (int i = 0; i < ((*linear)->length); i++)
    {
        printf("data[%d]:%d\n",i,(*linear)->data[i]);
    }    
};
int GetElem(linearList **linear,int i){
    if(i<1||i>((*linear)->length)){
        return 0;
    }else{
        return (*linear)->data[i-1];
    }
};
int LocateElem(linearList **linear,int e){
    for (int  i = 0; i < ((*linear)->length); i++)
    {
        if((*linear)->data[i]==e){
            return i++;
        }
    }
};
int ListInsert(linearList **linear,int i,int e){
    if(i<1||i>((*linear)->length)){
        return 0;
    }else{
        i--;
        for(int j=(*linear)->length;j>i;j--){
            (*linear)->data[j]=(*linear)->data[j-1];
        }
        (*linear)->data[i]=e;
        (*linear)->length++;
        return 1;
    }
};
ListDelete();
int main(){
    linearList *linear;
    InitList(&linear);
    ListInsert(&linear,1,1);
    ListInsert(&linear,2,2);
    ListInsert(&linear,3,3);

    DisplayList(&linear);

    printf("��ȡ����4��data:%d",GetElem(&linear,4));

    getchar();
    getchar();
    return 0;
}