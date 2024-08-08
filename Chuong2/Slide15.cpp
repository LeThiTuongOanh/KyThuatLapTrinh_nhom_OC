#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nhapVaoMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap gia tri cua phan tu %d: ", i);
		scanf_s("%d", &a[i]);
	}
}

void xuatMang(int a[], int n) {
	printf("\nGia tri cac phan tu trong mang\n");
	for (int i = 0; i < n; i++) {
		printf("Phan tu thu %d cua mang la: %d\n", i, a[i]);
	}
}

void taoMangNgauNhien(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100; // sinh so ngau nhien tu 0 den 99
	}
}

int timMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		max = (max > a[i]) ? max : a[i];
	}
	return max;
}

int timMin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		min = (min < a[i]) ? min : a[i];
	}
	return min;
}



int binarySearch(int arr[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

void menu() {
	printf("\n--- Menu ---\n");
	printf("0. Bai 1 Tim cac so x trong day so\n\t 7	9	13	17	27	30	31	35	38	40.\n");
	printf("1. Nhap mang\n");
	printf("2. Xuat mang\n");
	printf("3. Tim gia tri max\n");
	printf("4. Tim gia tri min\n");
	printf("5. Dem so luong chan/le\n");
	printf("6. Tim kiem tuyen tinh\n");
	printf("7. Sap xep mang\n");
	printf("8. Tim kiem nhi phan\n");
	printf("9. Dem so phan tu lon hon x\n");
	printf("10. Xuat cac so nguyen to\n");
	printf("11. Ghep hai mang\n");
	printf("12. Thoat\n");
}
int main() {
	menu();
	int n, choice, x;
	int a[50];
	srand(time(0)); // Khoi tao bo sinh so ngau nhien voi thoi gian hien hanh

	do {

		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &choice);
		int viTriTuyenTinh;
		int viTriNhiPhan;
		int arr[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
		int ns = sizeof(arr) / sizeof(arr[0]);
		int searchElements[] = { 17, 35, 40, 23, 10, 36 };
		int searchSize = sizeof(searchElements) / sizeof(searchElements[0]);
		switch (choice) {
		case 0:

			for (int i = 0; i < searchSize; i++) {
				int x = searchElements[i];
				int index = binarySearch(arr, ns, x);
				if (index != -1) {
					printf("Gia tri %d xuat hien tai vi tri %d trong mang.\n", x, index);
				}
				else {
					printf("Gia tri %d khong co trong mang.\n", x);
				}
			}
			break;
		case 1:
			printf("Nhap n so nguyen: ");
			scanf_s("%d", &n);
			if (n > 50 || n <= 0) {
				printf("So luong phan tu khong hop le!\n");
				return 1;
			}
			nhapVaoMang(a, n);
			break;
		case 2:
			xuatMang(a, n);
			break;
		case 3:
			printf("Gia tri max: %d\n", timMax(a, n));
			break;
		case 4:
			printf("Gia tri min: %d\n", timMin(a, n));
			break;
		
		case 12:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 12);

	return 0;
}
