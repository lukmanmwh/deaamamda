/*
NAMA  : DEA AMANDA PUTRI
NIM   : 22040040
KELAS : 2B
TEMA  : KASIR TOKO BUKU
*/



#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <iomanip> // Required for setw() function

using namespace std;

void cls() {
	system("cls");
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Produk {
    string nama;
    int harga;
    string kode;
};

void tambahProduk(Produk dataProduk[], int& jumlahProduk) {
    Produk barang;

    gotoXY(2, 1);
    
    cout << "Masukkan nama buku: ";
    cin.ignore();
    getline(cin, barang.nama);

    gotoXY(2, 2);
    
    cout << "Masukkan harga buku: ";
    cin >> barang.harga;

    cin.ignore(); // Membersihkan karakter newline sebelum mengambil input kode buku

    gotoXY(2, 3);
    
    cout << "Masukkan kode buku: ";
    getline(cin, barang.kode);

    dataProduk[jumlahProduk] = barang;
    jumlahProduk++;

    gotoXY(2, 5);
    
    cout << "Produk buku berhasil ditambahkan!" << endl;
    gotoXY(2, 9);system("pause");
    cls();
//    break;
    
}

void tampilkanDaftarBuku(Produk dataProduk[], int jumlahProduk) {
    
    gotoXY(2, 1);cout << "========================================================" << endl;
    gotoXY(2, 2);cout << "| No |       Nama       |     Harga    |   Kode Buku   |" << endl;
    gotoXY(2, 3);cout << "========================================================" << endl;
    for (int i = 0; i < jumlahProduk; i++) {
        gotoXY(2, 4 + i);
        cout << "| " << i + 1 << "  | ";
        cout << setw(16) << left << dataProduk[i].nama << " | ";
        cout << setw(12) << right << dataProduk[i].harga << " | ";
        cout << setw(13) << right << dataProduk[i].kode << " |" << endl;
    }
    gotoXY(2, 10);cout << "========================================================" << endl;
}

bool compareProduk(const Produk& a, const Produk& b) {
    return a.harga < b.harga;
}

void bubbleSortProduk(Produk dataProduk[], int jumlahProduk) {
    for (int i = 0; i < jumlahProduk - 1; i++) {
        for (int j = 0; j < jumlahProduk - i - 1; j++) {
            if (dataProduk[j].harga > dataProduk[j + 1].harga) {
                swap(dataProduk[j], dataProduk[j + 1]);
            }
        }
    }

    gotoXY(2, 12);
    cout << "Produk berhasil diurutkan berdasarkan harga!" << endl;
}

void cariProduk(Produk dataProduk[], int jumlahProduk, const string& keyword) {
    bool found = false;

    gotoXY(2, 10);
    cout << "Hasil Pencarian untuk keyword '" << keyword << "':" << endl;

    for (int i = 0; i < jumlahProduk; i++) {
        if (dataProduk[i].nama.find(keyword) != string::npos) {
            gotoXY(2, 11 + i);
            cout << "Nama: " << dataProduk[i].nama << ", Harga: " << dataProduk[i].harga << ", Kode: " << dataProduk[i].kode << endl;
            found = true;
            gotoXY(2, 20);system("pause");
        }
        
    }

    if (!found) {
        gotoXY(2, 18);cout << "Produk tidak ditemukan." << endl;
    }
    gotoXY(2, 20);system("pause");
}

void prosesTransaksi(Produk dataProduk[], int jumlahProduk) {
    int nomorProduk;
    int jumlahBeli;
    char lagi;

    do {
        
		system("cls");

        gotoXY(2, 1);
        cout << "=== Proses Transaksi ===" << endl;
        gotoXY(2, 2);
        tampilkanDaftarBuku(dataProduk, jumlahProduk);

        gotoXY(2, 12);
        cout << "Pilih nomor produk yang akan dibeli: ";
        cin >> nomorProduk;

        if (nomorProduk >= 1 && nomorProduk <= jumlahProduk) {
            gotoXY(2, 13);
            cout << "Masukkan jumlah yang akan dibeli: ";
            cin >> jumlahBeli;

            if (jumlahBeli > 0) {
                int totalHarga = dataProduk[nomorProduk - 1].harga * jumlahBeli;
                gotoXY(2, 15);
                cout << "Total Harga: " << totalHarga << endl;

                // Tambahkan ke resume transaksi
                Produk barang = dataProduk[nomorProduk - 1];
                for (int i = 0; i < jumlahBeli; i++) {
                    dataProduk[jumlahProduk] = barang;
                    jumlahProduk++;
                }
            } else {
                gotoXY(2, 15);
                cout << "Jumlah beli harus lebih dari 0!" << endl;
            }
        } else {
            gotoXY(2, 13);
            cout << "Nomor produk tidak valid!" << endl;
        }

        gotoXY(2, 17);
        cout << "Apakah ingin membeli lagi? (Y/N): ";
        cin >> lagi;

    } while (toupper(lagi) == 'Y');

    cls();
    gotoXY(2, 1);
    cout << "Transaksi selesai!" << endl;
    gotoXY(2, 3);
    system("pause");
}


void tampilkanResumeTransaksi(Produk dataProduk[], int jumlahProduk) {
    int subtotal = 0;
    int total = 0;

    gotoXY(2, 2);cout << "======================================" << endl;
    gotoXY(2, 3);cout << "| No |       Nama       |    Harga   |" << endl;
    gotoXY(2, 4);cout << "======================================" << endl;
    for (int i = 0; i < jumlahProduk; i++) {
        gotoXY(2, 5 + i);
        cout << "| " << i + 1 << "  | ";
        cout << setw(16) << left << dataProduk[i].nama << " | ";
        cout << setw(10) << right << dataProduk[i].harga << " |" << endl;

        subtotal += dataProduk[i].harga;
    }
    gotoXY(2, 11);cout << "======================================" << endl;

    total = subtotal;

    gotoXY(2, 15 + jumlahProduk);
    gotoXY(3, 16);cout << "Subtotal: " << subtotal << endl;
    gotoXY(2, 17 + jumlahProduk);
    gotoXY(3, 18);cout << "Total   : " << total << endl;
     gotoXY(3, 22);system("pause");
}


//void continue() {
//	system("");
//}

int main() {
    const int MAX_PRODUK = 100;
    Produk dataProduk[MAX_PRODUK];
    int jumlahProduk = 0;
    int pilihan;
    string nama, kelas;
    int nim;

	gotoXY(0, 0);
	cout<<"isi data diri terlebih dahulu";
    gotoXY(0, 1);
    cout << "Masukkan NIM: ";
    cin >> nim;
    cin.ignore();
    gotoXY(0, 2);
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    gotoXY(0, 3);
    cout << "Masukkan Kelas: ";
    getline(cin, kelas);
    
    cls();

    gotoXY(2, 1);cout << "=========================[ PROGRAM KASIR TOKO BUKU ]===================\n";
    gotoXY(2, 2);cout << "|         NIM        |            NAMA            |        KELAS      |\n";
    gotoXY(2, 3);cout << "=======================================================================\n";
    gotoXY(2, 4);cout << "|      " << nim << "      |     " << nama << "       |    	" << kelas << "	|\n";
    gotoXY(2, 5);cout << "=======================================================================\n\n";
	gotoXY(2, 10);system("pause");
    do {
    	system("cls");
    	gotoXY(3, 1);
        cout << "=== Program kasir Toko Buku ===" << endl;
        gotoXY(3, 2);
        cout << "1. Tambah buku" << endl;
        gotoXY(3, 3);
        cout << "2. Tampilkan buku" << endl;
        gotoXY(3, 4);
        cout << "3. Urutkan buku berdasarkan harga (Bubble Sort)" << endl;
        gotoXY(3, 5);
        cout << "4. Cari buku" << endl;
        gotoXY(3, 6);
        cout << "5. Proses Transaksi" << endl;
        gotoXY(3, 7);
        cout << "6. Tampilkan resume transaksi" << endl;
        gotoXY(3, 8);
        cout << "7. Keluar" << endl;
        gotoXY(3, 10);
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cls();

        switch (pilihan) {
            case 1:
                tambahProduk(dataProduk, jumlahProduk);
                break;
            case 2:
                tampilkanDaftarBuku(dataProduk, jumlahProduk);
                gotoXY(2, 12);
                system("pause");
                break;
            case 3:
                bubbleSortProduk(dataProduk, jumlahProduk);
                tampilkanDaftarBuku(dataProduk, jumlahProduk);
                gotoXY(2, 17);
                system("pause");
                break;
            case 4: {
                cin.ignore(); // Clear the input buffer
                gotoXY(2, 1);
                cout << "Masukkan keyword pencarian: ";
                string keyword;
                getline(cin, keyword);
                cariProduk(dataProduk, jumlahProduk, keyword);
                break;
            }
            case 5:
                prosesTransaksi(dataProduk, jumlahProduk);
                break;
            case 6:
                tampilkanResumeTransaksi(dataProduk, jumlahProduk);
                break;
            case 7:
                gotoXY(2, 1);
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                gotoXY(2, 3);
                system("pause");
                break;
            default:
                gotoXY(2, 1);
                cout << "Pilihan tidak valid!" << endl;
                gotoXY(2, 3);
                system("pause");
                break;
        }
    } while (pilihan != 7);
    
    gotoXY(2, 1);cout << "===========================[ PROGRAM KASIR BUKU ]======================\n";
    gotoXY(2, 2);cout << "|         NIM        |            NAMA            |        KELAS      |\n";
    gotoXY(2, 3);cout << "=======================================================================\n";
    gotoXY(2, 4);cout << "|      " << nim << "      |     " << nama << "       |    	" << kelas << "	|\n";
    gotoXY(2, 5);cout << "=======================================================================\n\n";
    
	return 0;
}

