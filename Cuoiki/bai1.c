
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "traversal.h"

typedef struct
{
    char name[1000];
    int (*func)();
} MenuItem;

FILE *file = NULL;
tree_t tree = NULL;
char filename[] = "booking_orders.txt";
int e = 0;
elmType arr[1000];
int count = 0;  


int docfile()
{
    // Mo file che do doc
    file = fopen(booking_orders, "r");
    if (file == NULL)
    {
        printf("Khong mo duoc file %s\n", booking_orders);
        exit(1);
    }
    fscanf(file, "%d", &e);
    elmType temp;
    while (fscanf(file, "%s %d %d %s %d-%d-%d %d", temp.name, &temp.a, &temp.b, temp.c, &temp.DD, &temp.MM, &temp.YYYY, &temp.d) != EOF)
    {
        arr[count] = temp;
        count++;
        InsertNode(temp, &tree);
    }
    // code
    fclose(file);
    return 0;
}

int tinhnang2()
{
    // Tim kiem
    elmType find;
    printf("Nhap ban muon tim: ");
    scanf("%s", find.name);
    tree_t result = search(find, tree);
    if (result == NULL)
    {
        printf("Khong tim thay %s\n", find.name);
    }
    else

    {
        // code
        find = result->element;
        printf("%s %d %d %s %d-%d-%d %d\n", find.name, find.a, find.b, find.c, find.DD, find.MM, find.YYYY, find.d);
    }
    return 0;
}

int tinhnang3()
{
    // code
    return 0;
}

int tinhnang4()
{
    // code
    return 0;
}
int tinhnang5()
{
    // code
    return 0;
}
int tinhnang6()
{
    // code
    return 0;
}
int thoat (elmType arr[]) {
    // Return 1 de doan sau thoat duoc vong lap
    printf("\nCam on ban da su dung chuong trinh.\nThoat chuong trinh...\n\n");
    return 1;
}


int main()
{
    int *arr = (int *)malloc(300 * sizeof(int));
    MenuItem item[] = {{"Doc du lieu tu file log", docfile},
                       {"Kiem tra so luong yeu cau khong hop le", tinhnang2},
                       {"Tra cuu ma theo yeu cau", tinhnang3},
                       {"Thay doi yeu cau", tinhnang4},
                       {"Huy yeu cau", tinhnang5},
                       {"Luu danh sach yeu cau ra file", tinhnang6};
                      {"Thoat", thoat}};
    int size = sizeof(item) / sizeof(item[0]); // Kich co menu

    for (;;)
    { // Vong lap vo han chay den khi gap thoat thi ket thuc
        printf("\nMenu:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d. %s\n", i + 1, item[i].name); // In menu
        }
        int luachon;
        printf("\nNhap lua chon: ");
        scanf("%d", &luachon);
        if (luachon < 1 || luachon > size)
        {
            continue; // Neu lua chon khong nam trong kich co thi bo qua
        }
        else if (item[luachon - 1].func())
        {
            // Khi goi den ham thoat thi se thoat vong lap do return 1
            break;
        }
    }
    // Giai phong bo nho cap phat dong
    freeTree(tree);
    free(arr);
}