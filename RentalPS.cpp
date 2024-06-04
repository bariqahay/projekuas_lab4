#include "RentalPS.h"
#include <iostream>

using namespace std;

// Konstruktor untuk inisialisasi data awal
RentalPS::RentalPS() {
    // Inisialisasi pelanggan awal
    tambahPelanggan(1, "Budi", "Jl. Merpati No. 1");
    tambahPelanggan(2, "Susi", "Jl. Kenari No. 2");
    
    // Inisialisasi konsol PS awal
    tambahKonsol(1, "PS4", true);
    tambahKonsol(2, "PS5", true);
}

void RentalPS::tambahPelanggan(int id, string nama, string alamat) {
    Pelanggan pelanggan = { id, nama, alamat };
    daftarPelanggan.push_back(pelanggan);
}

void RentalPS::tambahKonsol(int id, string nama, bool tersedia) {
    KonsolPS konsol = { id, nama, tersedia };
    daftarKonsol.push_back(konsol);
}

void RentalPS::tampilkanPelanggan() {
    for (const auto& p : daftarPelanggan) {
        cout << "ID: " << p.id << ", Nama: " << p.nama << ", Alamat: " << p.alamat << endl;
    }
}

void RentalPS::tampilkanKonsol() {
    for (const auto& k : daftarKonsol) {
        cout << "ID: " << k.id << ", Nama: " << k.nama << ", Tersedia: " << (k.tersedia ? "Ya" : "Tidak") << endl;
    }
}

Pelanggan* RentalPS::cariPelanggan(int id) {
    for (auto& p : daftarPelanggan) {
        if (p.id == id) {
            return &p;
        }
    }
    return nullptr;
}

KonsolPS* RentalPS::cariKonsol(int id) {
    for (auto& k : daftarKonsol) {
        if (k.id == id) {
            return &k;
        }
    }
    return nullptr;
}
