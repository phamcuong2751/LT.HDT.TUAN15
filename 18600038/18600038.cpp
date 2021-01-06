#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 1000

#pragma region Câu 1

/*=========================================CLASS RAP PHIM=========================================*/
class RapPhim
{
protected:
    int M;
    int N;
    int GiaHangGheTrungTam;
    bool ViTriGhe[MAX][MAX];
    float DoanhThu;
public:
    int TinhSoGheTrong();
    float GiaVeTai(int);
    float TinhDoanhThu();
    bool ViTriGheTrong(int, int);
};

bool RapPhim::ViTriGheTrong(int M, int N)
{
    return ViTriGhe[M][N];
}

float RapPhim::TinhDoanhThu()
{
    return DoanhThu;
}

float RapPhim::GiaVeTai(int M)
{
    int temp;
    temp = this->M / 2;
    if (this->M % 2 == 0)
    {
        if (M < temp)
        {
            return GiaHangGheTrungTam - (temp - M - 1) * 2000;
        }
        if (M > temp - 1)
        {
            return GiaHangGheTrungTam - (M - temp) * 2000;
        }
        if (M == temp || M == temp - 1)
        {
            return GiaHangGheTrungTam;
        }
    }
    else
    {
        if (M < temp + 1)
        {
            return GiaHangGheTrungTam - (temp + 1 - M) * 2000;
        }
        if (M > temp + 1)
        {
            return GiaHangGheTrungTam - (M - temp) * 2000;
        }
        if (M == temp + 1)
        {
            return GiaHangGheTrungTam;
        }
    }
}

int RapPhim::TinhSoGheTrong()
{
    int DemSoGheTrong = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (ViTriGhe[i][j] == false)
                DemSoGheTrong++;
    return DemSoGheTrong;
}
/*=========================================CLASS RAP THUONG=========================================*/
class CRapThuong :public RapPhim
{
public:
    CRapThuong(int, int);
    void DatVe(int, int);
};

/// <summary>
/// Hàm đặt vé
/// </summary>
/// <param name="M">Số hàng ghế trong rạp</param>
/// <param name="N">Số ghế trong một hàng</param>
void CRapThuong::DatVe(int M, int N)
{
    if (ViTriGhe[M][N] == false)
    {
        ViTriGhe[M][N] = true;
        DoanhThu += this->GiaVeTai(M);
    }
    else
    {
        cout << "Ghe nay da co khach dat truoc do!" << endl;
    }
}


CRapThuong::CRapThuong(int M, int N)
{
    DoanhThu = 0;
    this->M = M;
    this->N = N;
    this->GiaHangGheTrungTam = 60000;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            this->ViTriGhe[i][j] = false;
}
/*=========================================CLASS RAP CAO CAP=========================================*/
class CRapCaoCap :public RapPhim
{
public:
    CRapCaoCap(int, int);
    void DatVe(int, int, int);
};

CRapCaoCap::CRapCaoCap(int N, int M)
{
    DoanhThu = 0;
    this->M = M;
    this->N = N;
    this->GiaHangGheTrungTam = 100000;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            this->ViTriGhe[i][j] = false;
}
/// <summary>
/// Hàm đặt vé
/// </summary>
/// <param name="M">Số hàng ghế trong rạp</param>
/// <param name="N">Số ghế trong một hàng</param>
/// <param name="Ngay">Đại diện cho các thứ 2 3 4 5 6 7, CN = 1</param>
void CRapCaoCap::DatVe(int M, int N, int Ngay)
{
    if (ViTriGhe[M][N] == false)
    {
        ViTriGhe[M][N] = true;
        if (Ngay == 5)
            DoanhThu += 0.5 * this->GiaVeTai(M);
        else
            DoanhThu += this->GiaVeTai(M);
    }
    else
    {
        cout << "Ghe nay da co khach dat truoc do!" << endl;
    }
}
#pragma endregion


#pragma region Câu 2
class CNgay
{
private:
    int Ngay;
    int Thang;
    int Nam;
public:
    CNgay(void);
    void Nhap();
    void Xuat();
};

void CNgay::Nhap()
{
    cout << "Nhap Ngay: ";
    cin >> Ngay;
    cout << "Nhap Thang: ";
    cin >> Thang;
    cout << "Nhap Nam: ";
    cin >> Nam;
}

void CNgay::Xuat()
{
    cout << Ngay << "/" << Thang << "/" << Nam;
    cout << endl;
}

CNgay::CNgay()
{
    Ngay = 0;
    Thang = 0;
    Nam = 0;
}

class CNhanVien
{
protected:
    string CMND;
    string Ten;
    CNgay NgaySinh;
    string DiaChi;
    float LuongCoBan;
public:
    CNhanVien(void);
    virtual float TinhLuong();
    virtual void Nhap();
    virtual void Xuat();
};

CNhanVien::CNhanVien()
{
    CMND = "";
    Ten = "";
    DiaChi = "";
    LuongCoBan = 0;
}

float CNhanVien::TinhLuong()
{
    return 0.0f;
}

void CNhanVien::Nhap()
{
    cout << "CMND: ";
    cin >> CMND;
    cout << "Ten: ";
    cin >> Ten;
    cout << "Ngay Sinh: ";
    cout << endl;
    NgaySinh.Nhap();
    cout << "Dia chi: ";
    cin >> DiaChi;
    cout << "luong co ban: ";
    cin >> LuongCoBan;
}

void CNhanVien::Xuat()
{
    cout << "CMND: " << CMND << endl;
    cout << "Ten: " << Ten << endl;
    cout << "Ngay Sinh: ";
    NgaySinh.Xuat();
    cout << endl;
    cout << "Dia chi: " << DiaChi << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
}

class CPro : public CNhanVien
{
private:
    float Overtime;
public:
    CPro();
    float TinhLuong();
    void Nhap();
    void Xuat();
};

CPro::CPro()
{
    Overtime = 0;
}

float CPro::TinhLuong()
{
    return LuongCoBan + Overtime;
}

void CPro::Nhap()
{
    CNhanVien::Nhap();
    cout << "Overtime: ";
    cin >> Overtime;
}

void CPro::Xuat()
{
    CNhanVien::Xuat();
    cout << "Overtime:" << Overtime;
    cout << endl;
}

class CDes : public CNhanVien
{
private:
    float Bonus;
public:
    CDes();
    float TinhLuong();
    void Nhap();
    void Xuat();
};

CDes::CDes()
{
    Bonus = 0;
}

float CDes::TinhLuong()
{
    return LuongCoBan + Bonus;
}

void CDes::Nhap()
{
    CNhanVien::Nhap();
    cout << "Bonus: ";
    cin >> Bonus;
}

void CDes::Xuat()
{
    CNhanVien::Xuat();
    cout << "Bonus:" << Bonus;
    cout << endl;
}

class CTes : public CNhanVien
{
private:
    int Error;
public:
    CTes();
    float TinhLuong();
    void Nhap();
    void Xuat();
};

CTes::CTes()
{
    Error = 0;
}

float CTes::TinhLuong()
{
    return LuongCoBan + Error * 100000;
}

void CTes::Nhap()
{
    CNhanVien::Nhap();
    cout << "Error: ";
    cin >> Error;
}

void CTes::Xuat()
{
    CNhanVien::Xuat();
    cout << "Error:" << Error;
    cout << endl;
}

class CCongTy
{
private:
    vector <CNhanVien*> DNhanVien;
public:
    void Nhap();
    void Xuat();
    float TongLuong();

};
void CCongTy::Nhap()
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    CNhanVien* temp = new CNhanVien;
    for (int i = 0; i < n; i++)
    {
        int loai = 0;
        cout << "Loai nhan vien (1. Progammer, 2. Designer, 3. Tester): ";
        cin >> loai;

        if (loai == 1)
            temp = new CPro;
        else if (loai == 2)
            temp = new CDes;
        else if (loai == 3)
            temp = new CTes;

        temp->Nhap();
        DNhanVien.push_back(temp);
    }
}

void CCongTy::Xuat()
{
    for (int i = 0; i < DNhanVien.size(); i++)
    {
        cout << "Nhan vien " << i << endl;
        DNhanVien[i]->Xuat();
    }
}

float CCongTy::TongLuong()
{
    float sum = 0;
    for (int i = 0; i < DNhanVien.size(); i++)
    {
        sum += DNhanVien[i]->TinhLuong();
    }
    return sum;
}

#pragma endregion




void main()
{
    int BaiTap;
    do
    {
        cout << "1. Bai tap 1 | 2. Bai tap 2 | 0. Thoat" << endl;
        cin >> BaiTap;
        switch (BaiTap)
        {
        case 1:
        {
            cout << "\nBai Tap 1: " << endl;
#pragma region Câu 1
            cout << "=================KHOI TAO=================\n";
            int M, N;
            cout << "Khoi tao tong so luong ghe cho rap: " << endl;
            cout << "Nhap tong so hang: ";
            cin >> M;
            cout << "Nhap so ghe moi hang: ";
            cin >> N;
            CRapThuong* RapThuong = new CRapThuong(M, N);
            CRapCaoCap* RapCaoCap = new CRapCaoCap(M, N);
            int Chon;
            do
            {
                cout << "Chon loai rap:" << endl;
                cout << "1. Rap thuong | 2. Rap cao cap | 0. Thoat" << endl;
                cin >> Chon;
                //Đặt vé rạp thường
                if (Chon == 1)
                {
                    int ThaoTac;
                    do
                    {
                        int VT_Hang;
                        int VT_SoGhe;
                        cout << "\nNhap cac thao tac sau: " << endl;
                        cout << "1. Dat ve tai mot vi tri ghe nao do." << endl;
                        cout << "2. Cho biet gia ve tai mot vi tri ghe nao do." << endl;
                        cout << "3. Cho biet mot vi tri ghe nao do con trong khong." << endl;
                        cout << "4. Cho biet so ghe con trong trong rap." << endl;
                        cout << "5. Tinh tong so tien ve ban duoc." << endl;
                        cout << "0.Thoat" << endl;

                        cin >> ThaoTac;
                        switch (ThaoTac)
                        {
                        case 1:
                        {
                            cout << "Lua chon 1:" << endl;
                            cout << "Nhap hang ghe: ";
                            cin >> VT_Hang;
                            cout << "Ghe so may trong hang: ";
                            cin >> VT_SoGhe;
                            RapThuong->DatVe(VT_Hang, VT_SoGhe);
                            cout << "\nThem 1 ve thanh cong" << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "Lua chon 2:" << endl;
                            cout << "Nhap hang ghe: ";
                            cin >> VT_Hang;
                            cout << "Gia ve tai vi tri  hang so " << "[" << VT_Hang << "] la: " << RapThuong->GiaVeTai(VT_Hang);
                            break;
                        }
                        case 3:
                        {
                            cout << "Lua chon 3:" << endl;
                            cout << "Nhap hang ghe: ";
                            cin >> VT_Hang;
                            cout << "Ghe so may trong hang: ";
                            cin >> VT_SoGhe;
                            bool KiemTra = RapThuong->ViTriGheTrong(VT_Hang, VT_SoGhe);
                            if (KiemTra == true)
                            {
                                cout << "Vi tri da co khach dat!" << endl;
                            }
                            else
                            {
                                cout << "Vi tri dang trong!" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            cout << "Lua chon 4:" << endl;
                            cout << "So vi tri trong trong rap: " << RapThuong->TinhSoGheTrong() << endl;
                            break;
                        }
                        case 5:
                        {
                            cout << "Lua chon 5:" << endl;
                            cout << "Tong doanh thu rap thuong: " << RapThuong->TinhDoanhThu() << endl;
                            break;
                        }
                        default:
                            break;
                        }
                    } while (ThaoTac <= 5 && ThaoTac > 0);
                }

                //Đặt vé rạp cao cấp
                if (Chon == 2)
                {
                    int ThaoTac;
                    do
                    {
                        int VT_Hang;
                        int VT_SoGhe;
                        cout << "\nNhap cac thao tac sau: " << endl;
                        cout << "1. Dat ve tai mot vi tri ghe nao do." << endl;
                        cout << "2. Cho biet gia ve tai mot vi tri ghe nao do." << endl;
                        cout << "3. Cho biet mot vi tri ghe nao do con trong khong." << endl;
                        cout << "4. Cho biet so ghe con trong trong rap." << endl;
                        cout << "5. Tinh tong so tien ve ban duoc." << endl;
                        cout << "0.Thoat" << endl;

                        cin >> ThaoTac;
                        switch (ThaoTac)
                        {
                        case 1:
                        {
                            cout << "Lua chon 1:" << endl;
                            cout << "Nhap hang ghe: ";
                            cin >> VT_Hang;
                            cout << "Ghe so may trong hang: ";
                            cin >> VT_SoGhe;
                            RapThuong->DatVe(VT_Hang, VT_SoGhe);
                            cout << "\nThem 1 ve thanh cong" << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "Lua chon 2:" << endl;
                            cout << "Nhap hang ghe: ";
                            cin >> VT_Hang;
                            cout << "Gia ve tai vi tri  hang so " << "[" << VT_Hang << "] la: " << RapCaoCap->GiaVeTai(VT_Hang);
                            break;
                        }
                        case 3:
                        {
                            cout << "Lua chon 3:" << endl;
                            cout << "Nhap hang ghe: ";
                            cin >> VT_Hang;
                            cout << "Ghe so may trong hang: ";
                            cin >> VT_SoGhe;
                            bool KiemTra = RapCaoCap->ViTriGheTrong(VT_Hang, VT_SoGhe);
                            if (KiemTra == true)
                            {
                                cout << "Vi tri da co khach dat!" << endl;
                            }
                            else
                            {
                                cout << "Vi tri dang trong!" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            cout << "Lua chon 4:" << endl;
                            cout << "So vi tri trong trong rap: " << RapCaoCap->TinhSoGheTrong() << endl;
                            break;
                        }
                        case 5:
                        {
                            cout << "Lua chon 5:" << endl;
                            cout << "Tong doanh thu rap cao cap: " << RapCaoCap->TinhDoanhThu() << endl;
                            break;
                        }
                        default:
                            break;
                        }
                    } while (ThaoTac <= 5 && ThaoTac > 0);
                }
            } while (Chon != 0);
#pragma endregion
            break;
        }
       case 2:
       {
           cout << "\nBai Tap 2: " << endl;

#pragma region Câu 2
           CCongTy _congty;
           _congty.Nhap();
           _congty.Xuat();
           cout << "Tong luong: " << _congty.TongLuong();
#pragma endregion
           break;
       }
        default:
            break;
        }

    } while (BaiTap <= 2 && BaiTap > 0);






}
