#include <stdio.h>
#include <string.h>


struct NV {
	char hoten[30];
	int ms;
	float luong;	
};

struct danhsachNV{
	struct NV	nv[100];
	int soluong;
};

int main(){
	 struct danhsachNV	ds;
	 ds.soluong =0;
	 int maso;
	 char ten[50];
	 int tim = 0;
 	 int i,j;
	 int x;
	 do {
	 	printf("\nlua chon");
	 	printf("\n1. them nhan vien moi");
	 	printf("\n2. xoa nhan vien");
	 	printf("\n3. tim kiem nhan vien");
	 	printf("\n4. hien thi danh sach nhan vien");
	 	printf("\n5. thoat");
	 	printf("\nNhap lua chon cua ban: ");
        scanf("%d", &x);
        
        switch (x){
        	case 1: {
        		if(ds.soluong < 100){
        			struct NV nhanvien;
        			printf("\nnhap ho va ten : ");
        			 fflush(stdin);
        			fgets(nhanvien.hoten ,sizeof(nhanvien.hoten),stdin);
					        			
					printf(" nhap ma so : ");
					 scanf("%d",&nhanvien.ms);
					 
					printf(" nhap luong hang thang: ");
					scanf("%f",&nhanvien.luong );
					ds.nv [ds.soluong] = nhanvien;
					ds.soluong++;
					 	
				}
				else {
					  printf("\nDanh sach nhan vien da day. Khong the them moi.\n");
				}
				break;
			}
			case 2: {
				int c; 
				printf("\nnhap 1 de xoa the ten nhap 2 de xoa theo ma so:");
				scanf("%d",&c);
				if(c==1){
					printf("\nnhap ten nhan vien can xoa: ");
					fflush(stdin);
					fgets(ten,sizeof(ten),stdin);
					}
				if(c==2){
					printf("\n nhap ma so nhan vien can xoa: ");
					scanf("%d",&maso);
				}
				for(i=0;i<ds.soluong ;i++){
					if((ds.nv[i].ms == maso)|| strcmp(ds.nv[i].hoten, ten) == 0){
						tim=1;
						for(j=i;j<ds.soluong - 1; j++ ){
							ds.nv[j]=ds.nv[j+1];
						}
						ds.soluong--;
						printf("da xoa .");
						break;
					}
				}
				if(!tim){
					printf("\nkhong tim thay nhan vien");
				}
				break;
			}
			case 3: {
				int c; 
				printf("\nnhap 1 de tim the ten nhap 2 de tim theo ma so:");
				scanf("%d",&c);
				if(c==1){
					printf("\nnhap ten nhan vien can tim: ");
					fflush(stdin);
					fgets(ten,sizeof(ten),stdin);
					}
				if(c==2){
					printf("\n nhap ma so nhan vien can tim: ");
					scanf("%d",&maso);
				}
				for(i=0;i<ds.soluong ;i++){
						if((ds.nv[i].ms == maso)|| strcmp(ds.nv[i].hoten, ten) == 0){
							printf("Nhan vien %d:\n", i + 1);
                    		printf("Ho ten: %s", ds.nv[i].hoten);
                   			 printf("Ma so: %d\n", ds.nv[i].ms);
                    		printf("Luong hang thang: %.2f\n", ds.nv[i].luong);
						}
					}
				break;
			}
			case 4: {
				 printf("\nDanh sach nhan vien:\n");
                for (i = 0; i < ds.soluong ; i++) {
                    printf("Nhan vien %d:\n", i + 1);
                    printf("Ho ten: %s", ds.nv[i].hoten);
                    printf("Ma so: %d\n", ds.nv[i].ms);
                    printf("Luong hang thang: %.2f\n", ds.nv[i].luong);
                    printf("--------------------\n");
                }
				break;
			}
			case 5: {
				 printf("Ket thuc chuong trinh. \n");
                break;
            }
             default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	 }
	 while(x!=5);
	 return 0;
}
