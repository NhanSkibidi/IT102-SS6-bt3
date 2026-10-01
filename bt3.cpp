#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];
    int soLuong = 0;
    int luaChon;
    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LOGISTICS) ================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("===========================================================================\n");
        printf("Lua chon cua ban (1-5): ");
        scanf("%d", &luaChon);
        while (getchar() != '\n');
        switch (luaChon) {
            case 1: {
                char maPhieuMoi[20];
                int trungMa = 0;
                int ngay;
                printf("\n--- THEM MOI PHIEU MUON ---\n");
                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }
                printf("Nhap ma phieu: ");
                scanf("%19s", maPhieuMoi);
                while (getchar() != '\n');
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maPhieuMoi) == 0) {
                        trungMa = 1;
                        break;
                    }
                }
                if (trungMa == 1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }
                strcpy(maPhieu[soLuong], maPhieuMoi);

                printf("Nhap ma sach: ");
                scanf("%19s", maSach[soLuong]);

                while (getchar() != '\n');

                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &ngay);

                    while (getchar() != '\n');

                    if (ngay <= 0) {
                        printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                    }
                } while (ngay <= 0);

                soNgayMuon[soLuong] = ngay;

                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");

                break;
            }

            case 2: {
                printf("\n============================ DANH SACH PHIEU MUON ============================\n");

                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("%-5s %-12s %-15s %-12s %-18s %-15s\n",
                       "STT",
                       "MA PHIEU",
                       "MA SACH",
                       "SO NGAY",
                       "TRANG THAI",
                       "TIEN PHAT");

                printf("-------------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int ngayQuaHan = 0;
                    int tienPhat = 0;

                    if (soNgayMuon[i] > 14) {
                        ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;

                        printf("%-5d %-12s %-15s %-12d %-18s %d VND\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "QUA HAN",
                               tienPhat);
                    } else {
                        printf("%-5d %-12s %-15s %-12d %-18s %d VND\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "DUNG HAN",
                               0);
                    }
                }
                printf("===============================================================================\n");

                break;
            }
            case 3: {
                char maNhap[20];
                int pos = -1;
                int ngayMoi;
                printf("\n--- CAP NHAT SO NGAY MUON ---\n");
                printf("Nhap ma phieu can cap nhat: ");
                scanf("%19s", maNhap);
                while (getchar() != '\n');
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                } else {
                    printf("So ngay muon hien tai cua phieu %s la: %d\n",
                           maPhieu[pos],
                           soNgayMuon[pos]);
                    do {
                        printf("Nhap so ngay muon moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');
                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai lon hon 0! Vui long nhap lai.\n");
                        }
                    } while (ngayMoi <= 0);
                    soNgayMuon[pos] = ngayMoi;
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }
            case 4: {
                char maNhap[20];
                int pos = -1;
                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU MUON ---\n");
                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%19s", maNhap);
                while (getchar() != '\n');
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                } else {
                    for (int i = pos; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(maSach[i], maSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }
                    soLuong--;
                    printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                }
                break;
            }
            case 5:
                printf("\nCam on ban da su dung he thong LIBRARY_WMS Logistics!\n");
                printf("Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (luaChon != 5);
    return 0;
}

