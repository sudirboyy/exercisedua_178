#include<iostream>				
#include <vector>
using namespace std;

class pengarang;
class penerbit {
public:
	string nama_penerbit;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) : nama_penerbit(pNama) {
		cout << "penerbit \"" << nama_penerbit << "\" \n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama_penerbit << "\" tidak ada\n";
	}
	void TambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
public:
	string nama_pengarang;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) : nama_pengarang(pNama) {
		cout << "pengarang \"" << nama_pengarang << "\" \n";
	}
	~pengarang() {
		cout << "pengarang \"" << nama_pengarang << "\" tidak ada\n";
	}
	void TambahPenerbit(penerbit*);
	void cetakPenerbit();
};


void penerbit::TambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "\nDaftar pengarang pada penerbit \"" << this-> nama_penerbit << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama_pengarang << "\n";
	}
	cout << endl;
}

void pengarang::TambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->TambahPengarang(this);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this-> nama_pengarang << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama_penerbit << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* VarPenerbit1 = new penerbit("Gama Press");
	penerbit* VarPenerbit2 = new penerbit("Intan Pariwara");
	pengarang* VarPengarang1 = new pengarang("Giga");
	pengarang* VarPengarang2 = new pengarang("Joko");
	pengarang* VarPengarang3 = new pengarang("Asroni");
	pengarang* Varpengarang4 = new pengarang("Lia");

	VarPenerbit1->TambahPengarang(VarPengarang2);
	VarPenerbit1->TambahPengarang(Varpengarang4);
	VarPenerbit1->TambahPengarang(VarPengarang1);
	VarPenerbit2->TambahPengarang(VarPengarang3);
	VarPengarang1->TambahPenerbit(VarPenerbit1);
	VarPengarang1->TambahPenerbit(VarPenerbit2);

	VarPenerbit1->cetakPengarang();
	VarPenerbit2->cetakPengarang();
	VarPengarang1->cetakPenerbit();

	delete VarPenerbit1;
	delete VarPenerbit2;
	delete VarPengarang1;
	delete VarPengarang2;
	delete VarPengarang3;
	delete Varpengarang4;

	return 0;
}