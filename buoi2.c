#include<stdio.h>
#include<math.h>

void so_ng_to1(){
	int x,i,k=0;
	int j,n;
	printf("nhap x:");
	scanf("%d",&x);
	if(1<x&&x<100000){
		for(i=1;i<=x;i++){
			if(x%i==0) k++;
			
		}
		if(k==2) {
		printf("%d la so nguyen to\n",x);
		}
		else	{ 
		printf("%d khong la so nguyen to\n",x);
		printf("cac so ng to < x : ");
		}
		for(i=2;i<x;i++){
			for(j=1;j<=i;j++){
				if(i%j==0) n++;	
			}
			if(n<=2){
				printf("%d ",i);
				n=0;			
			}
			else{
				n=0;
			}
		}			
	}
	
}
int main(){
	so_ng_to1();
}
