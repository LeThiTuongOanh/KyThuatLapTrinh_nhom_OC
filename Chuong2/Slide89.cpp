#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int tongDuongCheoChinh(int matrix[][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += matrix[i][i];
	}
	return tong;
}

// Hàm tính tổng các phần tử nằm trên đường chéo phụ
int tongDuongCheoPhu(int matrix[][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += matrix[i][n - 1 - i];
	}
	return tong;
}
void menu() {
	printf("================== Menu ====================\n");
	printf("1.Tong cac phan tu nam tren duong cheo chinh\n");
	printf("2.Tong cac phan tu nam tren duong cheo phu \n");
	printf("3.Tong cac phan tu nam phia tren duong cheo chinh\n");
	printf("4.Tong cac phan tu nam phia tren duong cheo phu \n");
	printf("================== end ====================\n\n\n");
}
void nhapMangNgauNhien(int matrix[MAX_SIZE][MAX_SIZE]) {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}
void xuatMaTran(int matrix[][MAX_SIZE]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int luaChon;
	menu();
	nhapMangNgauNhien(matrix);
	xuatMaTran(matrix);
		do {
			printf("Nhap lua chon cua ban: ");
			scanf_s("%d", &luaChon);

			switch (luaChon) {
			case 1:
				printf("Tong cac phan tu nam tren duong cheo chinh: %d\n", tongDuongCheoChinh(matrix, 5));
				break;
			case 2:
				printf("Tong cac phan tu nam tren duong cheo phu: %d\n", tongDuongCheoPhu(matrix, 5));
				break;
			case 0:
				break;
			default:
				printf("Lua chon khong hop le!\n");
				break;
			}
		} while (luaChon != 8);
		getchar();
		return 0;
}

