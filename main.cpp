#include <iostream>
#include "RentalPS.h"

using namespace std;

void tampilkanMenu() {
    cout << "Menu Rental PS:" << endl;
    cout << "1. Tampilkan daftar pelanggan" << endl;
    cout << "2. Tampilkan daftar konsol" << endl;
    cout << "3. Tambah pelanggan" << endl;
    cout << "4. Hapus pelanggan" << endl;
    cout << "5. Sewa konsol" << endl;
    cout << "6. Kembalikan konsol" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main() {
    RentalPS rental;
    int pilihan;
    
    // Tambah konsol baru
    rental.tambahKonsol(3, "PS3", true);
    rental.tambahKonsol(4, "PS2", true);
    rental.tambahKonsol(5, "PS1", true);
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                rental.tampilkanPelanggan();
                break;
            case 2:
                rental.tampilkanKonsol();
                break;
            case 3: {
                int id;
                string nama, alamat;
                cout << "Masukkan ID pelanggan: ";
                cin >> id;
                cout << "Masukkan nama pelanggan: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan alamat pelanggan: ";
                getline(cin, alamat);
                rental.tambahPelanggan(id, nama, alamat);
                break;
            }
            case 4: {
                int id;
                cout << "Masukkan ID pelanggan yang akan dihapus: ";
                cin >> id;
                rental.hapusPelanggan(id);
                break;
            }
            case 5: {
                int idPelanggan, idKonsol;
                cout << "Masukkan ID pelanggan: ";
                cin >> idPelanggan;
                cout << "Masukkan ID konsol: ";
                cin >> idKonsol;
                rental.sewaKonsol(idPelanggan, idKonsol);
                break;
            }
            case 6: {
                int idKonsol;
                cout << "Masukkan ID konsol: ";
                cin >> idKonsol;
                rental.kembalikanKonsol(idKonsol);
                break;
            }
            case 7:
                cout << "Terima kasih telah menggunakan layanan kami!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 7);
    
    return 0;
}
