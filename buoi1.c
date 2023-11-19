#include<stdio.h> 
#include<math.h>
//in 70 so dau cua day fibonacii
 void in(){
 	printf("70 so dau cua day fibonacii: ");
 	int j,value;
 	static i=0;
 	static k=1;
 	for(j=0; j<70;j++){
 		value=k;
 		printf(" %d",value);
 		k=k+i;
 		i=value;
	 }
 }
 
 //tim ucln va bcnn cua 2 so;
 void ucln(){
 	int a,b,c,d;
 	int ucln, bcnn;
 	int max, min=0;
 	printf("nhap so a:");
 	scanf("%d",&a);
 	printf("nhap so b:");
 	scanf("%d",&b);
 	if(1<a&&b<10000&&a<b){
 		for(c=1;c<=a;c++){
 			if(a%c==0&&b%c==0) max=c;
 				
		 }
		 printf("ucln cua %d va %d la : %d\n",a,b,max);
		 for(c=b;c<100000;c++){
		 	if(c%a==0&&c%b==0){
		 		min=c;
		 		break;
			 }
		 }
		 printf("bcnn cua %d va %d la : %d",a,b,min);
	 }	
 }
 int main(){
 	in();
 	ucln();
 }



