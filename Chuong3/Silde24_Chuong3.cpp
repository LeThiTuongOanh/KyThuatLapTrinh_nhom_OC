﻿#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
// Hàm kiểm tra chuỗi chỉ chứa ký số
int kiem_tra_chuoi_ky_so(const char *s) {
	while (*s) {
		if (!isdigit(*s)) return 0;  // Nếu không phải ký số, trả về 0
		s++;
	}
	return 1;  // Trả về 1 nếu toàn ký số
}

int demKhoangTrang(const char *s)
{
	int count = 0;
	while (*s)
	{
		if (*s == ' ')
		{
			count++;
		}
		s++;
	}
	return count;
}




void xoa_khoang_trang_thua(char* s) {
	char* dst = s;
	int space_found = 0;

	while (*s) {
		if (*s == ' ') {
			if (!space_found) {
				*dst++ = *s;
				space_found = 1;
			}
		}
		else {
			*dst++ = *s;
			space_found = 0;
		}
		s++;
	}
	*dst = '\0';
}

int main() {
	int lua_chon;
	printf("----------MeNu------------ :\n");
	printf("1. Kiem tra chuoi co chua toan ky so\n");
	printf("2. Viet ham đem co bao nhieu khoang trang trong chuoi\n");
	printf("3. Xoa khoang trang thua trong chuoi\n");
	printf("4. Chuyen doi ky tu dau tien cua moi tu thanh chu in hoa\n");
	printf("5. Tim kiem ten trong chuoi ho ten\n");
	printf("6. Cat chuoi ho ten thanh ho lot va ten\n");
	printf("7. Viet chuong trinh chen mot chu vao vi tri nguoi dung yeu cau\n");
	printf("8. Xoa chuoi con\n");
	printf("9. Liet ke moi ky tu trong chuoi xuat hien may lan\n");
	printf("10. Tim ky tu xuat hien nhieu nhat trong chuoi\n");
	do{
		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &lua_chon);

		switch (lua_chon) {
		case 1: {
					char s[100];
					printf("Nhap chuoi can kiem tra: ");
					scanf_s(" %[^\n]", s, sizeof(s));  // Đọc chuỗi có khoảng trắng
					if (kiem_tra_chuoi_ky_so(s)) {
						printf("Chuoi chua toan ky so.\n");
					}
					else {
						printf("Chuoi khong chua toan ky so.\n");
					}
					break;
		}



		case 2: {
					char s[100];
					printf("Nhap chuoi can kiem tra: ");
					scanf_s(" %[^\n]", s, sizeof(s));  // Đọc chuỗi có khoảng trắng
					printf("So khoang trang trong chuoi la: %d", demKhoangTrang(s));
					break;
		}
		case 3: {
					char s[100];
					printf("Nhap chuoi can xoa khoang trang thua: ");
					while (getchar() != '\n');
					fgets(s, sizeof(s), stdin);
					s[strcspn(s, "\n")] = '\0';
					xoa_khoang_trang_thua(s);
					printf("Chuoi sau khi xoa khoang trang thua: %s\n", s);
					break;
		}
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (lua_chon != 0);
	getchar();
	return 0;
}
