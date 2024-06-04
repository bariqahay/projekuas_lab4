#include <iostream>
#include "RentalPS.h"

void tampilkanMenu() {
    std::cout << "Menu Rental PS:" << std::endl;
    std::cout << "1. Tampilkan daftar pelanggan" << std::endl;
    std::cout << "2. Tampilkan daftar konsol" << std::endl;
    std::cout << "3. Sewa konsol" << std::endl;
    std::cout << "4. Kembalikan konsol" << std::endl;
    std::cout << "5. Keluar" << std::endl;
    std::cout << "Pilih opsi: ";
}

int main() {
    RentalPS rental;
    int pilihan;
    
    do {
        tampilkanMenu();
        std::cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                rental.tampilkanPelanggan();
                break;
            case 2:
                rental.tampilkanKonsol();
                break;
            case 3: {
                int idPelanggan, idKonsol;
                std::cout << "Masukkan ID pelanggan: ";
                std::cin >> idPelanggan;
                std::cout << "Masukkan ID konsol: ";
                std::cin >> idKonsol;
                rental.sewaKonsol(idPelanggan, idKonsol);
                break;
            }
            case 4: {
                int idKonsol;
                std::cout << "Masukkan ID konsol: ";
                std::cin >> idKonsol;
                rental.kembalikanKonsol(idKonsol);
                break;
            }
            case 5:
                std::cout << "Terima kasih telah menggunakan layanan kami!" << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid." << std::endl;
                break;
        }
    } while (pilihan != 5);
    
    return 0;
}
