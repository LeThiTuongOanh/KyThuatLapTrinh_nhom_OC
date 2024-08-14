#include <stdio.h>

// Hàm tính Fibonacci đệ quy
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm tìm số Fibonacci lớn nhất nhỏ hơn hoặc bằng n
int largestFibonacciRecursive(int n) {
    int i = 0;
    while (fibonacci(i) <= n) {
        i++;
    }
    return fibonacci(i - 1);
}
int largestFibonacciIterative(int n) {
    int a = 0, b = 1, c = 1;
    while (c <= n) {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}
int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);
    int result1 = largestFibonacciRecursive(n);
    int result = largestFibonacciIterative(n);
    printf("So Fibonacci lon nhat nho hon hoac bang %d la: %d ( de qui) \n", n, result1);
    printf("So Fibonacci lon nhat nho hon hoac bang %d la: %d (Khu de qui) \n", n, result);

    return 0;
}
