#include <stdio.h>

#define MAX 100
#define PHI_GOC 150000
#define PHI_BHYT 30000

int main() {
    int stt[MAX], tuoi[MAX], bhyt[MAX];
    long phi_kham[MAX];
    int n = 0;
    long tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    do {
        printf("Nhap so luong benh nhan ban dau (0 - %d): ", MAX);
        scanf("%d", &n);
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        printf("\n--- Benh nhan thu %d ---\n", i + 1);
        stt[i] = i + 1; 
        
        do {
            printf("Tuoi (1 - 120): ");
            scanf("%d", &tuoi[i]);
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Trang thai BHYT (1: Co, 0: Khong): ");
            scanf("%d", &bhyt[i]);
        } while (bhyt[i] != 0 && bhyt[i] != 1);

        phi_kham[i] = (bhyt[i] == 1) ? PHI_BHYT : PHI_GOC;
        tong_doanh_thu += phi_kham[i];
        if (tuoi[i] >= 70) so_ca_uu_tien++;
    }

    printf("\n==== DANH SACH HANG CHO BAN DAU ====\n");
    for (int i = 0; i < n; i++) {
        printf("Index %d | STT: %03d | Tuoi: %3d | BHYT: %d | Phi: %ld VND %s\n", 
            i, stt[i], tuoi[i], bhyt[i], phi_kham[i], (tuoi[i] >= 70) ? "[UU TIEN]" : "");
    }
    printf("Tong doanh thu du kien: %ld VND\n", tong_doanh_thu);
    printf("So ca uu tien: %d\n", so_ca_uu_tien);

    int k;
    printf("\nNhap vi tri chi so (Index) can huy: ");
    scanf("%d", &k);

    if (n == 0) {
        printf("Loi: Hang cho dang rong. Khong the huy.\n");
    } else if (k < 0 || k >= n) {
        printf("Loi: Vi tri K = %d khong ton tai trong hang cho.\n", k);
    } else {
        tong_doanh_thu -= phi_kham[k];
        if (tuoi[k] >= 70) so_ca_uu_tien--;

        for (int i = k; i < n - 1; i++) {
            stt[i] = stt[i + 1];
            tuoi[i] = tuoi[i + 1];
            bhyt[i] = bhyt[i + 1];
            phi_kham[i] = phi_kham[i + 1];
        }
        n--; 
        
        printf("=> Da huy thanh cong benh nhan tai vi tri %d.\n", k);
    }

    printf("\n==== DANH SACH HANG CHO SAU CAP NHAT ====\n");
    if (n == 0) {
        printf("Hang cho hien dang rong.\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("Index %d | STT: %03d | Tuoi: %3d | BHYT: %d | Phi: %ld VND %s\n", 
                i, stt[i], tuoi[i], bhyt[i], phi_kham[i], (tuoi[i] >= 70) ? "[UU TIEN]" : "");
        }
    }
    printf("Tong doanh thu thuc te: %ld VND\n", tong_doanh_thu);
    printf("So ca uu tien hien tai: %d\n", so_ca_uu_tien);

    return 0;
}