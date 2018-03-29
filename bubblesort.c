#include <stdio.h>

int main(){

int a,b,c,hold;

scanf("%d %d %d",&a,&b,&c);

if(b>a){
hold=a;
a=b;
b=hold;
}

if(c>a){
hold=a;
a=c;
c=hold;
}

if(c>b){
hold=b;
b=c;
c=hold;
}

printf("a=%d\n",a);
printf("b=%d\n",b);
printf("c=%d\n",c);

return 0;
}
