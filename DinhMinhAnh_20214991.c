#include <stdio.h>
#include <string.h>

typedef struct
{
    char maKienHang[20];
    float L,W,H,weight;
    int loaiVanChuyen;
} ThongTinKienHang;
ThongTinKienHang DsHang[100];

void printMenu() {
    printf("==============Menu==================\n"
           "1.Nhap thong tin kien hang\n"
           "2.Chi tiet kien hang bi tu choi\n"
           "3.Chi tiet cac kien hang hop le\n"
           "4.Tinh phi van chuyen\n"
           "5.Thoat\n"
           "Lua chon cua ban: ");
}

int IDCheck(char* id){
	int i;
	for(i = 0; i<strlen(id);i++){
		if(id[i]<'0'||(id[i]>'9'&&id[i]<'A')||(id[i]>'Z'&&id[i]<'a')||id[i]>'z') return -1;
	}
	return 0;
}

void NhapThongTin(int n) {
	int i;
	char tmp[20];
	for(i = 0; i < n; i++) {
		printf("Nhap thong tin kien hang %d: \n", i +1);
		printf("\tMa kien hang: ");
		scanf("%s",tmp);
		if(IDCheck(tmp) == -1) {
			printf("\tMa kien hang loi!\n");
			return;
		}
		strcpy(DsHang[i].maKienHang,tmp);
		printf("\tChieu dai: ");
		scanf("%f", &DsHang[i].L);
		printf("\tChieu rong: ");
		scanf("%f", &DsHang[i].W);
		printf("\tChieu cao: ");
		scanf("%f", &DsHang[i].H);
		printf("\tTrong luong tinh: ");
		scanf("%f", &DsHang[i].weight);
		printf("\tLoai van chuyen: ");
		scanf("%d", &DsHang[i].loaiVanChuyen);
	}
}

int ErrorCheck(ThongTinKienHang kienHang){
	if(kienHang.L<10||kienHang.W<10||kienHang.H<10) return 1;
	if(kienHang.L>150||kienHang.W>150||kienHang.H>150) return 2;
	if(kienHang.weight>30) return 3;
	return 0;
}

void printTuChoi(int n) {
	int i;	
	printf("\tChi tiet kien hang bi tu choi\n"
		   "\t=============================\n");
	printf("\t%-20s %-20s\n", "Ma kien hang", "Ly do tu choi");
	for(i = 0; i < n; i++) {
		int err = ErrorCheck(DsHang[i]);
		if(err != 0) {
			switch(err){
				case 1:
					printf("\t%-20s %-20s\n",DsHang[i].maKienHang, "ER1");
					break;
				case 2:
					printf("\t%-20s %-20s\n",DsHang[i].maKienHang, "ER2");
					break;
				case 3:
					printf("\t%-20s %-20s\n",DsHang[i].maKienHang, "ER3");
					break;
			}
			
		}
	}
}

float TrongLuong(ThongTinKienHang kienHang){
	if(kienHang.L+kienHang.W+kienHang.H < 80) return kienHang.weight;
	if(kienHang.loaiVanChuyen == 1){
		return kienHang.L*kienHang.W*kienHang.H/6000;
	}
	else{
		return kienHang.L*kienHang.W*kienHang.H/4000;
	}
}

float LamTronTrongLuong(float weight){
	int w = (int)(weight*2);
	if(weight*2-w>0) return (float)(w+1)/2;
	return weight;
}

float CanNangTinhPhi(ThongTinKienHang kienHang){
	float w = LamTronTrongLuong(TrongLuong(kienHang));
	if(w> kienHang.weight) return w - kienHang.weight;
	else return  kienHang.weight - w;
}
double PhiVanChuyen(ThongTinKienHang kienHang){
	float tl = TrongLuong(kienHang);
	tl = LamTronTrongLuong(tl);
	if(kienHang.loaiVanChuyen == 1){
		return 22000+(tl-3)/0.5*2500;
	}
	else{
		return 16500+(tl-3)/0.5*2500;
	}
}

void printHopLe(int n, int *hople) {
	int i, count = 0;
	printf("\tChi tiet kien hang hop le\n"
		   "\t=============================\n");
	printf("\t%-20s %-20s %-20s %-20s\n", "Ma kien hang", "Can nang tinh phi", "Hinh thuc van chuyen", "Cuoc phi");
	for(i = 0; i < n; i++) {
		int err = ErrorCheck(DsHang[i]);
		if(err == 0) {
			count++;
			if(DsHang[i].loaiVanChuyen == 0)
				printf("\t%-20s %-20.2f %-20s %-20.lf\n",DsHang[i].maKienHang, CanNangTinhPhi(DsHang[i]) ,"Chuyen thuong",PhiVanChuyen(DsHang[i]));
			if(DsHang[i].loaiVanChuyen == 1)
				printf("\t%-20s %-20.2f %-20s %-20.lf\n",DsHang[i].maKienHang, CanNangTinhPhi(DsHang[i]) ,"Chuyen nhanh", PhiVanChuyen(DsHang[i]));
		}
	}
	printf("\tTong so: %d\n", count);
	*hople = count;
}

double  TinhPhiVanChuyen(int n) {
	double res = 0;
	int i;
	for(i = 0; i < n; i++) {
		int err = ErrorCheck(DsHang[i]);
		if(err == 0) {
			res += 	PhiVanChuyen(DsHang[i]);
		}
	}
	return res;
}

void printChiPhiVanChuyen(int n, int hople) {
	printf("\tChi phi van chuyen\n"
		   "\t=============================\n");
	printf("\tSo luong kien hang: %d\n", hople);
	printf("\tTong tien cuoc: %.lf\n", TinhPhiVanChuyen(n));
	printf("\tVAT: %.lf\n", TinhPhiVanChuyen(n)*0.08);
	printf("Tong chi phi: %.lf\n",TinhPhiVanChuyen(n)*1.08);
}


int main() {
	int choice, n, soKienHangHopLe, i;
	while(1) {
		printMenu();
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("Nhap so kien hang: ");
                scanf("%d", &n);
                if(n < 1 || n > 100) {
                    printf("so kien hang khong hop le!\n");
                    break;
                }
                NhapThongTin(n);
				break;
			case 2:
				printTuChoi(n);
				break;
			case 3:
				printHopLe(n, &soKienHangHopLe);
				break;
			case 4:
				printChiPhiVanChuyen(n, soKienHangHopLe);
				break;
			case 5:
				return 0;
				break;
		}
	}
}
