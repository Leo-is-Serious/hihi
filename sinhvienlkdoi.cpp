#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct HoTen {
    string ho;
    string ten;
};

struct SinhVien {
    string maSV;
    HoTen hoTen;
    double diemTB;
};

struct Node {
    SinhVien data;
    Node* prev;
    Node* next;
};

Node* taoNode(SinhVien sv) {
    Node* newNode = new Node;
    newNode->data = sv;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void themVaoDau(Node*& head, SinhVien sv) {
    Node* newNode = taoNode(sv);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void themVaoCuoi(Node*& head, SinhVien sv) {
    Node* newNode = taoNode(sv);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void sapXepGiamDanTheoDiemTB(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node *i, *j;
    SinhVien tempData;
    for (i = head; i != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.diemTB < j->data.diemTB) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
}

void inThongTinSV(SinhVien sv) {
    cout << "Ma SV: " << sv.maSV << ", Ho Ten: " << sv.hoTen.ho << " " << sv.hoTen.ten << ", Diem TB: " << fixed << setprecision(2) << sv.diemTB << endl;
}

void timVaInThongTinTheoMaSV(Node* head, string maSV) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.maSV == maSV) {
            inThongTinSV(temp->data);
            return;
        }
        temp = temp->next;
    }
    cout << "Khong tim thay sinh vien voi ma SV " << maSV << endl;
}

void loaiSVDiemTBThapHon5(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.diemTB < 5.0) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

void timVaInThongTinSVDiemTBCaoNhat(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    Node* maxNode = head;
    Node* temp = head->next;

    while (temp != nullptr) {
        if (temp->data.diemTB > maxNode->data.diemTB) {
            maxNode = temp;
        }
        temp = temp->next;
    }

    cout << "Sinh vien co diem trung binh cao nhat la: ";
    inThongTinSV(maxNode->data);
}

void menu() {
    Node* head = nullptr;
    while (true) {
        cout << "---------------DSLK DOI---------------" << endl;
        cout << "1. Them sinh vien vao dau danh sach" << endl;
        cout << "2. Them sinh vien vao cuoi danh sach" << endl;
        cout << "3. Sap xep danh sach giam dan theo diem trung binh" << endl;
        cout << "4. Tim va in thong tin sinh vien theo ma sinh vien" << endl;
        cout << "5. Loai bo sinh vien co diem trung binh nho hon 5" << endl;
        cout << "6. Tim va in thong tin sinh vien co diem trung binh cao nhat" << endl;
        cout << "7. Thoat" << endl;
        cout << "Nhap lua chon: ";
        
        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                string maSV, ho, ten;
                double diemTB;
                cout << "Nhap ma SV: ";
                cin >> maSV;
                cout << "Nhap ho SV: ";
                cin >> ho;
                cout << "Nhap ten SV: ";
                cin >> ten;
                cout << "Nhap diem trung binh: ";
                cin >> diemTB;

                SinhVien sv;
                sv.maSV = maSV;
                sv.hoTen.ho = ho;
                sv.hoTen.ten = ten;
                sv.diemTB = diemTB;

                themVaoDau(head, sv);
                break;
            }
            case 2: {
                string maSV, ho, ten;
                double diemTB;
                cout << "Nhap ma SV: ";
                cin >> maSV;
                cout << "Nhap ho SV: ";
                cin >> ho;
                cout << "Nhap ten SV: ";
                cin >> ten;
                cout << "Nhap diem trung binh: ";
                cin >> diemTB;

                SinhVien sv;
                sv.maSV = maSV;
                sv.hoTen.ho = ho;
                sv.hoTen.ten = ten;
                sv.diemTB = diemTB;

                themVaoCuoi(head, sv);
                break;
            }
            case 3:
                sapXepGiamDanTheoDiemTB(head);
                cout << "Da sap xep danh sach sinh vien giam dan theo diem trung binh." << endl;
                break;
            case 4: {
                string maSV;
                cout << "Nhap ma SV can tim: ";
                cin >> maSV;
                timVaInThongTinTheoMaSV(head, maSV);
                break;
            }
            case 5:
                loaiSVDiemTBThapHon5(head);
                cout << "Da loai bo sinh vien co diem trung binh nho hon 5." << endl;
                break;
            case 6:
                timVaInThongTinSVDiemTBCaoNhat(head);
                break;
            case 7:
                cout << "Thoat chuong trinh." << endl;
                return;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
