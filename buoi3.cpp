#include <stdio.h>
#include <string.h>
#include <ctype.h>

void xuly(char *chuoimoi) {
   
    int len;
    int i = 0;
    len = strlen(chuoimoi);

    char t[100];
    int j = 0;
    for (i = 0; i < len; i++) {
        if ((chuoimoi[i] >= 'a' && chuoimoi[i] <= 'z') || (chuoimoi[i] >= 'A' && chuoimoi[i] <= 'Z') || (chuoimoi[i] == ' ' && chuoimoi[i + 1] != ' ')) {
            t[j++] = chuoimoi[i];
        }
    }
    t[j] = '\0';
    printf("Chuoi sau khi xu ly : %s\n", t);
}

void daochuoi(char *chuoimoi) {
   
    char t[100];
    int len = strlen(chuoimoi);
    int i;
    for (i = 0; i < len; ++i) {
        t[i] = chuoimoi[len - i - 1];
    }
    t[len] = '\0';
    printf("Chuoi dao nguoc: %s\n", t);
}

void inthuong(char *chuoimoi) {
    for (int i = 0; chuoimoi[i]; i++) {
        chuoimoi[i] = tolower(chuoimoi[i]);
    }
}

void thaythe(char *chuoimoi){
	char t[100];
	int len = strlen(chuoimoi);
    int i,j=0;
	for(int i = 0; i < len; i++){
		if(chuoimoi[i]=='e'){
			t[j++]='e';
			t[j++]='f' ;
		}
		else{
			t[j++]=chuoimoi[i]; 
		} 
	}
	t[len] = '\0';
    printf("%s\n", t);
}

int main() {
    char chuoi[100];
    char a[100]="frefshefr efmbefddefd";
    printf("Nhap chuoi : ");

    fgets(chuoi, sizeof(chuoi), stdin);
    printf("\nChuoi vua nhap la : %s", chuoi);

    xuly(chuoi);
    daochuoi(chuoi);

   inthuong(chuoi);
    printf("\nChuoi chuyen doi: %s\n", chuoi);

	thaythe(a);
    return 0;
}
