#include <stdio.h>

int main(){

int i,lim,aux;

printf("Digite o limite: \n");
scanf("%d",&lim);

int nums[lim];
int lixo[lim];

for(i=0;i<lim;i++){
nums[i]=i;
}

for(i=0;i<lim;i++){

if(nums[i]!=2){
if(nums[i]%2==0){
aux=nums[i];
lixo[i]=aux;
nums[i]=0;
}
}

if(nums[i]!=3){
if(nums[i]%3==0){
aux=nums[i];
lixo[i]=aux;
nums[i]=0;
}
}

if(nums[i]!=5){
if(nums[i]%5==0){
aux=nums[i];
lixo[i]=aux;
nums[i]=0;
}
}

if(nums[i]!=7){
if(nums[i]%7==0){
aux=nums[i];
lixo[i]=aux;
nums[i]=0;
}
}

if(nums[i]!=11){
if(nums[i]%11==0){
aux=nums[i];
lixo[i]=aux;
nums[i]=0;
}
}

}

for(i=0;i<lim;i++){
if(nums[i]!=0){
printf("Elemento[%d] = %d\n",i,i);}
}

return 0;
}
