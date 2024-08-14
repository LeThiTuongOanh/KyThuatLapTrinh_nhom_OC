#include <stdio.h>

// Xuat day Fibonacci

int fibonacci(int n);
void printFibonacci(int n);

int main() {
	int n;
	do {

		printf("Nhap so luong so Fibonacci can xuat: ");
		scanf_s("%d", &n);

		if (n <= 0) {
			printf("So luong phan tu phai la so nguyen duong!\n");
		}
	} while (n <= 0);

	printFibonacci(n);
	getchar();
	getchar();
	return 0;
}

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) {
	if (n <= 2) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm xuất dãy Fibonacci 
void printFibonacci(int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n");
}
