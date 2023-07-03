#include <stdio.h>
#include <string.h>

// 03-12-2021 john 3.5M obama 0
typedef struct mess{
    char time[11]; //DD-MM-YYYY
    char sender[256];
    char size_of_mess[256];
    char receiver[256];
    int blocked;
}Mess;

Mess MessList[100]; // tao mang luu cac tin nhan va nhan toi da 100 mess nhap vao

int check_time(Mess mess) {
    int day, month, year;
    sscanf(mess.time, "%d-%d-%d", &day, &month, &year);
    // printf("%d-%d-%d", day, month, year);
    if(year < 0 || year > 2023) {
        return -1;
    }
    else {
        switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            if(day > 31 || day < 0) {
                return -1;
            }
            break;

        /* Group all 30 days cases together */
        case 4:
        case 6:
        case 9:
        case 11: 
            if(day > 30 || day < 0) {
                return -1;
            }
            break;

        /* Remaining case */
        case 2: 
            if(day > 29 || day < 0) {
                return -1;
            }
            break;

        default: 
            return -1;
        }
    }
    return 0;
}

void getMaxMess(int size) {
    int len;
    char donvi;
    float max = 0, f;
    for(int i = 0; i < size; i++) {
        len = strlen(MessList[i].size_of_mess);
        donvi = MessList[i].size_of_mess[len-1];

        MessList[i].size_of_mess[len-1] = '\0';
        sscanf(MessList[i].size_of_mess, "%f", &f);
        switch(donvi) {
            case 'K':
                break;
            case 'M':
                f = f*1024;
                break;
            case 'G':
                f = f*1024*1024;
                break;
            default:
                printf("khong doc duoc don vi cua size\n");
        }
        
        
    }
}

int main() {
    char buff[1024];
    int i = 0, size = 0;
    printf("Nhap theo định dạng: DD-MM-YYYY sender size_of_message receiver blocked: \n");
    char c ='0';
    while(c != '$') {
        if(c == '\n') {
            buff[i] = '\0';
            sscanf(buff, "%s %s %s %s %d", MessList[size].time, MessList[size].sender, MessList[size].size_of_mess, MessList[size].receiver, &MessList[size].blocked);
            i = 0;
            size++;
        }
        buff[i] = c;
        i++;
        c = getchar();
    }
    buff[i] = '\0';
    // kiểm tra ngày tháng
    for(i = 0; i < size; i++) {
        if(check_time(MessList[i]) == -1) {
            printf("Tin nhan nhap vao thu %d co ngay thang nam khong hop le\n", i+1);
        }
    }
    // kiem tra dung luong lon nhat
    getMaxMess(size);
} 