#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void nhapVaoMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap gia tri cua phan tu %d: ", i);
		scanf_s("%d", &a[i]);
	}
}

void xuatMang(int a[], int n)
{
	printf("\nGia tri cac phan tu trong mang\n");
	for (int i = 0; i < n; i++)
	{
		printf("Phan tu thu %d cua mang la: %d\n", i, a[i]);
	}
}


void taoMangNgauNhien(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100; // sinh so ngau nhien tu 0 den 99
	}
}
int timMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		max = (max>a[i]) ? max : a[i];

	}
	return max;

}

int main()
{
	int n;
	int a[50];

	srand(time(0));//khoi tao bo sinh so ngau nhien voi tg hien hanh

	printf("Nhap n so nguyen: ");
	scanf_s("%d", &n);
	if (n > 50 || n <= 0)
	{
		printf("So luong phan tu khong hop le!\n");
		return 1;
	}


	nhapVaoMang(a, n);
	xuatMang(a, n);

	int z = timMax(a, n);
	printf("\nGia tri max: %d\n", z);

	
	getchar();  //Xoa ki tu newline tu bo dem nhap
	getchar();  // cho nguoi dung nhan phim truoc khi ket thuc

	return 0;
}
