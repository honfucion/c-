#include < bits/stdc++.h>
using namespace std;

class Xe {
    string bks;
    static int solanViPham;
public:
    Xe(string x) : bks(x) {
        solanViPham++;
    }
    void setBKS(string x) {bks=x;}
    string getBKS() {return bks;}
    int getSoLanViPham() {return solanViPham;}
};

int Xe :: solanViPham = 0;
class ViPham {
    string maViPham;
    string moTa;
    int soTienPhat;
public:
    ViPham(string x, string y, int z) : maViPham(x), moTa(y), soTienPhat(z) {}
};

class XeViPham : public Xe, public ViPham {
    bool daNop = false ;
    string diaDiem;
public:
    XeViPham(string bks, string maViPham, string diaDiem): Xe(bks), ViPham(maViPham, " "), diaDiem(diaDiem) {}
    void setDaNop(bool x) {daNop=x;}
    bool getDaNop() {return daNop;}
};

int main()