#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 100
#define MAX_COL 100


// Hàm kiểm tra chữ số đầu là chữ số lẻ
bool chuSoDauLe(int num) {
	while (num >= 10) {
		num /= 10;
	}
	return num % 2 != 0;
}
// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLe(int matrix[][MAX_COL], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (chuSoDauLe(matrix[i][j])) {
				tong += matrix[i][j];
			}
		}
	}
	return tong;
}



void menu() {
	printf("\n----------Menu----------\n");
	printf("1. Tinh tong cac phan tu co chu so dau la chu so le\n");
	printf("2. Liet ke cac so hoan thien trong ma tran\n");
	printf("3. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no\n");
	printf("4. Tinh tong gia tri tren dong k cua ma tran\n");
	printf("5. Tinh tong cac gia tri nam tren bien cua ma tran\n");
	printf("6. Dem tan suat xuat hien cua 1 gia tri x trong ma tran\n");
	printf("7. Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to\n");
	printf("8. Thoat\n");
}
// Hàm kiểm tra số hoàn thiện
bool laSoHoanThien(int num) {
	if (num <= 0) return false;
	int tong = 0;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			tong += i;
		}
	}
	return tong == num;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int matrix[][MAX_COL], int m, int n) {
	bool timThay = false;
	printf("Cac so hoan thien trong ma tran:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laSoHoanThien(matrix[i][j])) {
				printf("%d ", matrix[i][j]);
				timThay = true;
			}
		}
	}
	if (!timThay) {
		printf("Khong co so hoan thien nao.\n");
	}
	printf("\n");
}
// Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTriTuyetDoiSau(int matrix[][MAX_COL], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (matrix[i][j] > abs(matrix[i][j + 1])) {
				tong += matrix[i][j];
			}
		}
	}
	return tong;
}
// Hàm tính tổng giá trị trên dòng k của ma trận
int tongDauDong(int matrix[][MAX_COL], int m, int n, int k) {
	int tong = 0;
	if (k >= 0 && k < m) {
		for (int j = 0; j < n; j++) {
			tong += matrix[k][j];
		}
	}
	else {
		printf("Dong %d khong ton tai.\n", k);
	}
	return tong;
}

int main() {
	int matrix[MAX_ROW][MAX_COL];
	
	int luaChon;
	menu();
	
	// Nhập các phần tử của ma trận
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j]= (rand()-199)%100;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	do {
		// Hiển thị menu
		
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(matrix, 3, 3));
			break;

		case 2:
			lietKeSoHoanThien(matrix, 3, 3);
			break;
		case 3:
			printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tongLonHonTriTuyetDoiSau(matrix, 3, 3));
			break;
		case 4:
		{
			int k;
			printf("Nhap dong k de tinh tong: ");
			scanf_s("%d", &k);
			printf("Tong gia tri tren dong %d: %d\n", k, tongDauDong(matrix, 3, 3, k));
		}
		break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (luaChon != 8);

	return 0;
}
