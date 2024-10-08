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

void demChanLe(int a[], int n) {
	int chan = 0, le = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			chan++;
		else
			le++;
	}
	printf("\nSo phan tu chan la: %d\n", chan);
	printf("So phan tu le la: %d\n", le);
}


int timKiemTuyenTinh(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i; // Tra ve vi tri dau tien tim thay
		}
	}
	return -1; // Khong tim thay
}
void sapXepMang(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void demSoPhanTuX(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			count++;
		}
	}
	printf("So phan tu co gia tri %d trong mang la: %d\n", x, count);
}
void Cau6(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x)
			count++;
	}
	printf("So phan tu lon hon %d la %d\n", x, count);
}

int kiemTraNguyenTo(int x) {
	if (x < 2) return 0;
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

void Cau8(int a[], int n) {
	printf("\nSo nguyen to trong mang: ");
	for (int i = 0; i < n; i++) {
		if (kiemTraNguyenTo(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}
int tinhTongMang(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

void ghepMang(int b[], int m, int c[], int n, int a[]) {
	int i = 0, j = 0, k = 0;
	while (i < m && j < n) {
		if (b[i] < c[j]) {
			a[k++] = b[i++];
		}
		else {
			a[k++] = c[j++];
		}
	}
	while (i < m) {
		a[k++] = b[i++];
	}
	while (j < n) {
		a[k++] = c[j++];
	}
}

int kiemTraHoanThien(int x) {
	int sum = 0;
	for (int i = 1; i <= x / 2; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}
	return sum == x;
}
void xuatSoHoanThien(int a[], int n) {
	printf("\nCac so hoan thien trong mang: ");
	for (int i = 0; i < n; i++) {
		if (kiemTraHoanThien(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
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
	printf("12. Dem so phan tu x\n");
	printf("13. Tinh tong cac phan tu trong mang\n");
	printf("14. Xuat cac so hoan thien\n");
	printf("20. Thoat\n");
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
		case 5:
			demChanLe(a, n);
			break;
		case 6:
			printf("Nhap gia tri x de tim trong mang: ");
			scanf_s("%d", &x);
			viTriTuyenTinh = timKiemTuyenTinh(a, n, x);
			if (viTriTuyenTinh != -1) {
				printf("Gia tri %d xuat hien tai vi tri %d trong mang.\n", x, viTriTuyenTinh);
			}
			else {
				printf("Gia tri %d khong co trong mang.\n", x);
			}
			break;
		case 7:
			sapXepMang(a, n);
			printf("Mang sau khi sap xep: ");
			xuatMang(a, n);
			break;

		case 9:
			printf("Nhap vao gia tri x: ");
			scanf_s("%d", &x);
			Cau6(a, n, x);
			break;
		case 10:
			Cau8(a, n);
			break;
		case 11: {
					 int m, p;
					 int b[50], c[50];
					 printf("Nhap so luong phan tu cua mang b: ");
					 scanf_s("%d", &m);
					 printf("Nhap cac phan tu cua mang b (tang dan):\n");
					 for (int i = 0; i < m; i++) {
						 scanf_s("%d", &b[i]);
					 }
					 printf("Nhap so luong phan tu cua mang c: ");
					 scanf_s("%d", &p);
					 printf("Nhap cac phan tu cua mang c (tang dan):\n");
					 for (int i = 0; i < p; i++) {
						 scanf_s("%d", &c[i]);
					 }
					 ghepMang(b, m, c, p, a);
					 printf("Mang a sau khi ghep la:\n");
					 xuatMang(a, m + p);
					 break;
		}
		case 12:
			printf("Nhap gia tri x can dem: ");
			scanf_s("%d", &x);
			demSoPhanTuX(a, n, x);
			break;
		case 13:
			printf("Tong cac phan tu trong mang la: %d\n", tinhTongMang(a, n));
			break;
		case 14:
			xuatSoHoanThien(a, n);
			break;
		case 20:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 12);
	getchar();
	getchar();
	return 0;
}
