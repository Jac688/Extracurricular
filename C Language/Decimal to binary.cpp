//Decimal to binary
#include <stdio.h>
int main(){
     int a,r,i=0,j=1,count[100];     //�������a
     printf("������һ��ʮ��������:\n");
     scanf("%d",&a);
     do               //ѭ����ֱ��a����0���� 
    {
         r=a%2;       //��ÿһ�ε�������ʵ������������Ҳ����� 
         a=a/2;
         i++;
        count[i]=r;
  
     }
    while(a!=0);
     printf("ʮ��������ת��Ϊ����������:\n");
     for(j=i;j>0;j--){              //�����ǵ������ 
        printf("%d",count[j]);
    }
    return 0;

}

