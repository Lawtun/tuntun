#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nhanvien {
    char hoten[50];
    char maso;
    int luong;
    struct nhanvien *Next;
} * nv;

nv initHead() {
    return NULL;
}

nv taonv(char *hoten, char maso, int luong) {
    nv nvmoi;
    nvmoi = (nv)malloc(sizeof(struct nhanvien));

    strncpy(nvmoi->hoten, hoten, sizeof(nvmoi->hoten));
    nvmoi->maso = maso;
    nvmoi->luong = luong;
    nvmoi->Next = NULL;
    
    return nvmoi;
}

nv themnv(nv head, char *hoten, char maso, int luong) {
    nv nvmoi = taonv(hoten, maso, luong);

    if (head == NULL) {
        return nvmoi;
    }

    nv tro1 = head;
    while (tro1->Next != NULL) {
        tro1 = tro1->Next;
    }

    tro1->Next = nvmoi;

    return head;
}

void xuatDanhSach(nv head) {
    nv p = head;
     printf("\n---------------Danhsach-------------");
    while (p != NULL) {
        printf("\nHo ten: %s, Ma so: %c, Luong: %d\n", p->hoten, p->maso, p->luong);
        p = p->Next;
    }
     printf("\n------------------------------------");
}

nv nhapnv(nv ds, int *soluongnv) {
    char hoten[50];
    char maso;
    int n = *soluongnv;
    int m;
    int i, luong;
    
    printf("\nNhap so luong nhan vien: ");
    scanf("%d", &(*soluongnv));
    if (n >= 1) {
        *soluongnv = n + m;
        for (i = n; i < *soluongnv; i++) {
            while (getchar() != '\n');  
            printf("\nNhap ten nhan vien: ");
            fgets(hoten, sizeof(hoten), stdin);
            printf("\nNhap ma so nhan vien: ");
            scanf(" %c", &maso); 
            printf("\nNhap luong nhan vien: ");
            scanf("%d", &luong);
            ds = themnv(ds, hoten, maso, luong);
        }
    } else {
        for (i = 0; i < *soluongnv; i++) {
             while (getchar() != '\n');  
            printf("\nNhap ten nhan vien: ");
            fgets(hoten, sizeof(hoten), stdin);
            printf("\nNhap ma so nhan vien: ");
            scanf(" %c", &maso); 
            printf("\nNhap luong nhan vien: ");
            scanf("%d", &luong);
            ds = themnv(ds, hoten, maso, luong);
            n++;
        }
    }
    return ds;
}

nv tim_ms(nv head, char maso) {
    nv tro1 = head;
    while (tro1 != NULL) {
        if (tro1->maso == maso) {
            return tro1;
        }
        tro1 = tro1->Next;
    }
    return NULL;
}

nv tim_ten(nv head, const char *ten) {
    nv tro1 = head;
    while (tro1 != NULL) {
        if (strstr(tro1->hoten, ten) != NULL) {
            return tro1;
        }
        tro1 = tro1->Next;
    }
    return NULL;
}

nv xoa_ms(nv head, char maso) {
    nv tro1 = head;
    nv tro2 = NULL;

    while (tro1 != NULL && tro1->maso != maso) {
        tro2 = tro1;
        tro1 = tro1->Next;
    }

    if (tro1 == NULL) {
        printf("Khong tim thay nhan vien co ma so %c.\n", maso);
        return head;
    }

    if (tro2 == NULL) {
        head = tro1->Next;
    } else {
        tro2->Next = tro1->Next;
    }
    free(tro1);
    printf("Da xoa nhan vien co ma so %c.\n", maso);

    return head;
}
nv xoa_ten(nv head, const char* ten) {
    nv tro1 = head;
    nv tro2 = NULL;

    while (tro1 != NULL) {
        if (strstr(tro1->hoten, ten) != NULL) {
            int y;
            printf("\nCo muon xoa nhan vien: %s",tro1->hoten);
            printf("Nhan 1 de xoa, Nhan 2 de khong xoa: ");
            scanf("%d", &y);

            if (y == 1) {
                if (tro2 == NULL) {
                    
                    head = tro1->Next;
                    free(tro1);
                    tro1 = head;
                } else {
                    tro2->Next = tro1->Next;
                    free(tro1);
                    tro1 = tro2->Next;
                }
            } else if (y == 2) {
               
                tro2 = tro1;
                tro1 = tro1->Next;
            } else {
                printf("Lua chon khong hop le.\n");
            }
        } else {
            tro2 = tro1;
            tro1 = tro1->Next;
        }
    }

    return head;
}

void menu() {
    nv ds = initHead();
    int soluongnv = 0;
    char maso[10];
    char ten[10];
    int luaChon;

    do {
        printf("\n---------------MENU-------------");
        printf("\n1.Them nhan vien moi");
        printf("\n2.Tim nhan vien theo ma so");
        printf("\n3.Tim nhan vien theo ten");
        printf("\n4.Xoa nhan vien theo ma so");
        printf("\n5.Xoa nhan vien theo ten");
        printf("\n6.Hien thi danh sach nhan vien");
        printf("\n0.Thoat chuong trinh");
        printf("\nChon 1 trong cac chuc nang tren: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 0:
                printf("\n\tBan da chon thoat! ");
                printf("\n\t    TAM BIET!");
                break;
            case 1:
                ds = nhapnv(ds, &soluongnv);
                xuatDanhSach(ds);
                break;
            case 2:
                while (getchar() != '\n');
                printf("Nhap ma can tim: ");
                scanf(" %c", maso);
                nv timNV = tim_ms(ds,*maso);
                if (timNV != NULL) {
                    printf("Nhan vien co ma so %c:\n", maso);
                    printf("Ho ten: %s, Ma so: %c, Luong: %d\n", timNV->hoten, timNV->maso, timNV->luong);
                } else {
                    printf("Khong tim thay nhan vien co ma so %c.\n", maso);
                }
                break;
            case 3:
                printf("Nhap ten can tim: ");
                scanf("%s", ten);
                nv timNV_ten = tim_ten(ds, ten);
                if (timNV_ten != NULL) {
                    printf("Nhan vien co ten %s:\n", ten);
                    printf("Ho ten: %s, Ma so: %c, Luong: %d\n", timNV_ten->hoten, timNV_ten->maso, timNV_ten->luong);
                } else {
                    printf("Khong tim thay nhan vien co ten %s.\n", ten);
                }
                break;
            case 4:
                while (getchar() != '\n');
                printf("Nhap ma nhan vien can xoa: ");
                scanf(" %c", maso);
                ds = xoa_ms(ds, *maso);
                xuatDanhSach(ds);
                break;
            case 5:
                while (getchar() != '\n');
                printf("Nhap ten nhan vien can xoa: ");
                scanf("%s", ten);
                ds = xoa_ten(ds, ten);
                break;
            case 6:
                printf("Hien thi danh sach nhan vien hien tai:\n");
                xuatDanhSach(ds);
                break;
            default:
                printf("Vui long chon chuc nang tuong ung tai MENU!\n");
                break;
        }
    } while (luaChon);
}

int main() {
    menu();
    return 0;
}

