#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], n = 0, choice;

    do {
        printf("\n==== MENU ====\n");
        printf("1. Nh?p s? ph?n t? v� gi� tr? cho m?ng\n");
        printf("2. In gi� tr? c�c ph?n t? trong m?ng\n");
        printf("3. �?m s? lu?ng c�c s? ho�n h?o trong m?ng\n");
        printf("4. T�m gi� tr? nh? th? 2 trong m?ng\n");
        printf("5. Th�m ph?n t? v�o d?u m?ng\n");
        printf("6. X�a ph?n t? t?i v? tr� c? th?\n");
        printf("7. S?p x?p m?ng gi?m d?n\n");
        printf("8. T�m ki?m ph?n t? trong m?ng\n");
        printf("9. S?p x?p m?ng s? l? tru?c, s? ch?n sau\n");
        printf("10. �?o ngu?c m?ng\n");
        printf("0. Tho�t\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Nh?p s? ph?n t? c?a m?ng: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nh?p arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }
        } else if (choice == 2) {
            for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
        } else if (choice == 3) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                int sum = 1;
                for (int j = 2; j <= arr[i] / 2; j++) {
                    if (arr[i] % j == 0) sum += j;
                }
                if (sum == arr[i] && arr[i] > 1) count++;
            }
            printf("S? lu?ng s? ho�n h?o trong m?ng: %d\n", count);
        } else if (choice == 4) {
            int min = __INT_MAX__, secondMin = __INT_MAX__;
            for (int i = 0; i < n; i++) {
                if (arr[i] < min) {
                    secondMin = min;
                    min = arr[i];
                } else if (arr[i] > min && arr[i] < secondMin) {
                    secondMin = arr[i];
                }
            }
            if (secondMin == __INT_MAX__) {
                printf("Kh�ng c� gi� tr? nh? th? 2.\n");
            } else {
                printf("Gi� tr? nh? th? 2: %d\n", secondMin);
            }
        } else if (choice == 5) {
            int newElem;
            printf("Nh?p gi� tr? c?n th�m: ");
            scanf("%d", &newElem);
            for (int i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = newElem;
            n++;
        } else if (choice == 6) {
            int pos;
            printf("Nh?p v? tr� c?n x�a (0-%d): ", n - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) {
                printf("V? tr� kh�ng h?p l?.\n");
            } else {
                for (int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
            }
        } else if (choice == 7) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] < arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("M?ng sau khi s?p x?p gi?m d?n:\n");
            for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
        } else if (choice == 8) {
            int x, found = -1;
            printf("Nh?p gi� tr? c?n t�m: ");
            scanf("%d", &x);
            for (int i = 0; i < n; i++) {
                if (arr[i] == x) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                printf("Gi� tr? %d t�m th?y t?i v? tr� %d.\n", x, found);
            } else {
                printf("Kh�ng t�m th?y gi� tr? %d trong m?ng.\n", x);
            }
        } else if (choice == 9) {
            int temp[MAX], index = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 != 0) temp[index++] = arr[i];
            }
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) temp[index++] = arr[i];
            }
            for (int i = 0; i < n; i++) {
                arr[i] = temp[i];
            }
            printf("M?ng sau khi s?p x?p s? l? tru?c, s? ch?n sau:\n");
            for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
        } else if (choice == 10) {
            for (int i = 0; i < n / 2; i++) {
                int temp = arr[i];
                arr[i] = arr[n - i - 1];
                arr[n - i - 1] = temp;
            }
            printf("M?ng sau khi d?o ngu?c:\n");
            for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
        } else if (choice == 0) {
            printf("Tho�t chuong tr�nh.\n");
        } else {
            printf("L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n");
        }
    } while (choice != 0);

    return 0;
}
