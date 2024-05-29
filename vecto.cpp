#include <bits/stdc++.h>
using namespace std;

class BenhNhan{
    string cccd;
    string ten;
    public:
        BenhNhan(string cccd, string ten){
            this->cccd = cccd;
            this->ten = ten;
        }
        BenhNhan(string cccd) { this->cccd = cccd; }
        void setCCCD(string a) { this->cccd = a; }
        void setTen(string b) { this->ten = b; }
        string getCCCD() { return this->cccd; }
        string getTen() { return this->ten; }
};

class STT {
    string stt;
    string chuyenKhoa;
    public:
        STT(string stt, string chuyenKhoa){
            this->stt = stt;
            this->chuyenKhoa = chuyenKhoa;
        }
        STT(string stt) { this->stt = stt; }
        void setSTT(string a) { this->stt = a; }
        void setChuyenKhoa(string b) { this->chuyenKhoa = b; }
        string getSTT() { return this->stt; }
        string getChuyenKhoa() { return this->chuyenKhoa; }
};

class LaySo : public STT, public BenhNhan { 
    int gioKham;
    static int tongSo;
    public:
        LaySo(string cccd, string stt, int gioKham) {
            this->cccd = cccd;
            this->stt = stt;
            this->gioKham = gioKham;
            tongSo++;
        }
        void setGioKham(int x) {this->gioKham=x;}
        int getGioKham() {return this->gioKham;}
};

int main() {
    vector<BenhNhan> benhNhan;
    bool b = true;
    while (b) {
        string str1, str2;
        cout << "CCCD: ";
        cout << "Ten: ";
        cin >> str1 >> str2;
        BenhNhan temp(str1, str2);
        benhNhan.push_back(temp);
        cout << "Tiep tuc? (Y/N): ";
        char c;
        cin >> c;
        if (c == 'N' || c == 'n') {
            b = false;
        }
        for (int i = 0; i <benhNhan.size(); i++) {
            cout << "CCCD: " << benhNhan[i].getCCCD() << " " << "Ten: " << benhNhan[i].getTen() << endl;
        }
    }
    vector<STT> stt;
    bool s = true;
    while (s) {
        string str1, str2;
        cout << "STT: ";
        cout << "ChuyenKhoa: ";
        cin >> str1 >> str2;
        STT temp(str1, str2);
        stt.push_back(temp);
        cout << "Tiep tuc? (Y/N): ";
        char c;
        cin >> c;
        if (c == 'N' || c == 'n') {
            s = false;
        }
        for (int i = 0; i <stt.size(); i++) {
            cout << "STT: " << stt[i].getSTT() << " " << "Ten: " << stt[i].getChuyenKhoa() << endl;
        }
    }
    vector<LaySo> laySo;
    while {
        int so =0;
        cout << "1 > In danh sach Benh Nhan" << endl ;
        cout << "2 > In danh sach STT" << endl ;
        cout << "3 > Lay so kham benh" << endl ;
        cout << "4 > Thoat" << endl ;
        cout << "Nhap lua chon: ";
        cin >> so;
        switch (so){
            case 1:
                if (so == 1) {
                    for (int i = 0; i <benhNhan.size(); i++) {
                        cout << "CCCD: " << benhNhan[i].getCCCD() << " " << "Ten: " << benhNhan[i].getTen() << endl;
                    }
                }
                break;
            case 2:
                if (so == 2) {
                    for (int i = 0; i <stt.size(); i++) {
                        cout << "STT: " << stt[i].getSTT() << " " << "Ten: " << stt[i].getChuyenKhoa() << endl;
                    }
                }
                break;
            case 3:
                if (so == 3) {
                    string str1, str2;
                    int gk;
                    cout << "CCCD: "
        }
    }
    return 0;
}