#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "traversal.h"
#include <time.h>
#define MAX_CAR 300
#define TRUE 1
#define FALSE 0

void showData(elmType x) {
    printf("%d-%02d-%02d %02d:%02d:%02d %s\n",x.YYYY,x.MM,x.DD,x.hh,x.mm,x.ss,x.name);
}

typedef struct {
    char name[1000];
    int (*func)(elmType arr[]);
} MenuItem;

void printTime()
{
 time_t t = time(NULL);
 struct tm tm = *localtime(&t);
 printf("Hien tai la: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1,
tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}


FILE *file=NULL;
tree_t tree=NULL;
char filein[]="log_input.txt";
char fileout[]="change_log.txt";
int count_car = 0;
elmType change[1000];
int change_count = 0;

int check_name (char *name) {
    for (int i=0; i <strlen(name); i++) {
        if (name[i] == ' ') return FALSE;
    }
    if (strlen(name) > 12) return FALSE;
    return TRUE;
}

int docfile (elmType arr[]) {
    // printf("1\n");
    // Mo file che do doc
    file = fopen(filein,"r");
    if (file==NULL) {
        printf("Khong mo duoc file %s\n",filein);
        exit(1);
    }
    elmType temp;
    while (fscanf(file, "%d-%d-%d %d:%d:%d %s %d",&temp.YYYY,&temp.MM,&temp.DD,&temp.hh,&temp.mm,&temp.ss,temp.name,&temp.type)!=EOF) {
        // if (check_name(temp.name)==FALSE) {
        //     continue;
        // }
        // else {
            arr[count_car]=temp;
            count_car++;
        // }
    }
    fclose(file);
    // printf("%d\n",count_car);
    // for (int i=0; i<count_car; i++) {
    //     printf("%s\n", arr[i].name);
    // }
    return 0;
}

int tracuu (elmType arr[]) {
    // Tim kiem
    elmType find;
    printf("Nhap ngay ban muon tim: ");
    scanf("%d-%d-%d",&find.YYYY,&find.MM,&find.DD);
    int in=0;
    int out=0;
    for (int i=0; i< count_car;i++) {
        if (find.MM == arr[i].MM && find.DD == arr[i].DD) {
            if (arr[i].type == 1) {
                in++;
            }
            else {
                out++;
            }
        }
        else if (find.MM > arr[i].MM && find.DD > arr[i].DD) {
            break;
        }
    }
    printf("So xe gui: %d\n",in);
    printf("So xe lay ra: %d\n",out);
    return 0;
}

int in4xe (elmType arr[]) {
    // int count_in = 0;
    // elmType in[1000];
    // for (int i = 0; i < count_car; i++) {
    //     if (arr[i].type == 1) {
    //         printf("Hey\n");
    //         int check = 0;
    //         for (int j = i+1; j < count_car; j++) {
    //             if (arr[j].type == 1 && strcmp(arr[j].name,arr[i].name) == 0) {
    //                 check++;
    //             }
    //             if (check==0) {
    //                 in[count_in]=arr[i];
    //                 count_in++;
    //             }
    //         }
    //     }
    // }
    // printf("Hi\n");
    // for (int i=0; i<count_in; i++) {
    //     printf("%s\n",in[i].name);
    //     InsertNode(in[i],&tree);
    // }
    for (int i=0; i<count_car; i++) {
        if (arr[i].type == 1) {
            InsertandCount(arr[i],&tree);
        }
        else if (arr[i].type == 0) {
            deleteNode(arr[i],&tree);
        }
    }
    // prettyPrint(tree);
    // printf("\n");
    int count_in = countInternalNodes(tree);
    printf("Tong so xe hien co: %d\n",count_in);
    printf("Bien so\t\tThoi gian gui\n");
    inorderprint(tree);
    return 0;
}

int guixe (elmType arr[]) {
    file = fopen(filein,"a");
    if (file==NULL) {
        printf("Khong mo duoc file %s\n",filein);
        exit(1);
    }
    elmType find;
    printf("Bien so xe ban can gui: ");
    scanf("%s",find.name);
    getchar();
    // while (check_name(find.name)==FALSE) {
    //     printf("Loi. Bien so xe khong duoc co dau cach.\nVui long nhap lai: ");
    //     scanf("%[^\n]s",find.name);
    //     getchar();
    // }
    tree_t result = search(find,tree);
    if (result == NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        find.YYYY = tm.tm_year+1900;
        find.MM = tm.tm_mon+1;
        find.DD = tm.tm_mday;
        find.hh = tm.tm_hour;
        find.mm = tm.tm_min;
        find.ss = tm.tm_sec;
        find.type = 1;
        change[change_count]=find;
        change_count++;
        InsertNode(find,&tree);
        printf("Gui xe thanh cong!\n");
        fprintf(file,"%d-%02d-%02d %02d:%02d:%02d %s %d\n",find.YYYY,find.MM,find.DD,find.hh,find.mm,find.ss,find.name,find.type);
    }
    else {
        printf("Loi bien so da ton tai\n");
    }
    fclose(file);
    return 0;
}

int traxe (elmType arr[]) {
    file = fopen(filein,"a");
    if (file==NULL) {
        printf("Khong mo duoc file %s\n",filein);
        exit(1);
    }
    elmType find;
    printf("Bien so xe ban can tra: ");
    scanf("%s",find.name);
    getchar();
    // while (check_name(find.name)==FALSE) {
    //     printf("Loi. Bien so xe khong duoc co dau cach.\nVui long nhap lai: ");
    //     scanf("%[^\n]s",find.name);
    //     getchar();
    // }
    tree_t result = search(find,tree);
    if (result != NULL) {
        printf("\n");
        showData(result->element);
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        find.YYYY = tm.tm_year+1900;
        find.MM = tm.tm_mon+1;
        find.DD = tm.tm_mday;
        find.hh = tm.tm_hour;
        find.mm = tm.tm_min;
        find.ss = tm.tm_sec;
        find.type = 0;
        change[change_count]=find;
        change_count++;
        deleteNode(find,&tree);
        printf("Lay xe thanh cong!\n");
        fprintf(file,"%d-%02d-%02d %02d:%02d:%02d %s %d\n",find.YYYY,find.MM,find.DD,find.hh,find.mm,find.ss,find.name,find.type);
    }
    else {
        printf("Lay xe KHONG thanh cong do xe khong gui tai bai\n");
    }
    fclose(file);
    return 0;
}

int capnhat (elmType arr[]) {
    file = fopen(fileout,"a");
    if (file==NULL) {
        printf("Khong mo duoc file %s\n",fileout);
        exit(1);
    }
    for (int i = 0; i < change_count; i++) {
        fprintf(file,"%d-%02d-%02d %02d:%02d:%02d %s %d\n",change[i].YYYY,change[i].MM,change[i].DD,change[i].hh,change[i].mm,change[i].ss,change[i].name,change[i].type);
    }
    fclose(file);
    return 0;
}

int thoat (elmType arr[]) {
    // Return 1 de doan sau thoat duoc vong lap
    printf("\nCam on ban da su dung chuong trinh.\nThoat chuong trinh...\n\n");
    return 1;
}

int main () {
    elmType *arr = (elmType *)malloc(MAX_CAR*sizeof(elmType));
    MenuItem item[]={{"Doc du lieu tu file log",docfile},
                    {"Tra cuu so luong xe gui/lay theo ngay trong qua khu",tracuu},
                    {"Thong tin cac xe trong bai hien tai",in4xe},
                    {"Gui them xe moi",guixe},
                    {"Tra xe",traxe},
                    {"Cap nhat log du lieu",capnhat},
                    {"Thoat",thoat}};
    int size = sizeof(item) / sizeof(item[0]);    // Kich co menu
    
    for (;;) { // Vong lap vo han chay den khi gap thoat thi ket thuc
        printf("\nChuong trinh quan ly bai xe\nVui long chon mot trong cac chuc nang sau:\n");
        for (int i = 0; i < size; i++) {
            printf("[%d] %s\n",i+1,item[i].name); //In menu
        }
        int luachon;
        printf("\nLua chon cua ban la: ");
        scanf("%d",&luachon);
        if (luachon < 1 || luachon > size) {
            continue; //Neu lua chon khong nam trong kich co thi bo qua
        }
        else if (item[luachon-1].func(arr)) {
            // Khi goi den ham thoat thi se thoat vong lap do return 1
            break;
        }
    }
    // Giai phong bo nho cap phat dong
    freeTree(tree);
    free(arr);
}