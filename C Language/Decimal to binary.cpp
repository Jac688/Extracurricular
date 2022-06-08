//Decimal to binary
#include <stdio.h>
int main(){
     int a,r,i=0,j=1,count[100];     //输入的是a
     printf("请输入一个十进制整数:\n");
     scanf("%d",&a);
     do               //循环，直到a等于0跳出 
    {
         r=a%2;       //求每一次的余数，实际上最后输出的也是这个 
         a=a/2;
         i++;
        count[i]=r;
  
     }
    while(a!=0);
     printf("十进制整数转换为二进制数是:\n");
     for(j=i;j>0;j--){              //这里是倒序输出 
        printf("%d",count[j]);
    }
    return 0;

}

