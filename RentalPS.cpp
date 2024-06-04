#include "RentalPS.h"
#include <iostream>

using namespace std;

bool RentalPS::sewaKonsol(int idPelanggan, int idKonsol) {
    Pelanggan* pelanggan = cariPelanggan(idPelanggan);
    KonsolPS* konsol = cariKonsol(idKonsol);
    
    if (pelanggan && konsol && konsol->tersedia) {
        konsol->tersedia = false;
        cout << "Konsol PS berhasil disewa oleh " << pelanggan->nama << endl;
        return true;
    } else {
        cout << "Gagal menyewa konsol PS." << endl;
        return false;
    }
}

bool RentalPS::kembalikanKonsol(int idKonsol) {
    KonsolPS* konsol = cariKonsol(idKonsol);
    
    if (konsol && !konsol->tersedia) {
        konsol->tersedia = true;
        cout << "Konsol PS berhasil dikembalikan." << endl;
        return true;
    } else {
        cout << "Gagal mengembalikan konsol PS." << endl;
        return false;
    }
}