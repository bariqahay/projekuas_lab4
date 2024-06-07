#include "RentalPS.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Konstruktor untuk inisialisasi data awal
RentalPS::RentalPS() {
    muatDatabase();
}

void RentalPS::muatDatabase() {
    ifstream inFile("database.txt");
    if (!inFile) {
        cerr << "Tidak dapat membuka file database.txt" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string type;
        iss >> type;
        if (type == "P") {
            Pelanggan p;
            iss >> p.id >> p.nama >> p.alamat;
            daftarPelanggan.push_back(p);
        } else if (type == "K") {
            KonsolPS k;
            iss >> k.id >> k.nama >> k.tersedia;
            daftarKonsol.push_back(k);
        }
    }
    inFile.close();
}

void RentalPS::simpanDatabase() {
    ofstream outFile("database.txt");
    if (!outFile) {
        cerr << "Tidak dapat membuka file database.txt" << endl;
        return;
    }
    for (const auto& p : daftarPelanggan) {
        outFile << "P " << p.id << " " << p.nama << " " << p.alamat << endl;
    }
    for (const auto& k : daftarKonsol) {
        outFile << "K " << k.id << " " << k.nama << " " << k.tersedia << endl;
    }
    outFile.close();
}

void RentalPS::tambahPelanggan(int id, string nama, string alamat) {
    Pelanggan pelanggan = { id, nama, alamat };
    daftarPelanggan.push_back(pelanggan);
    simpanDatabase();
}

void RentalPS::hapusPelanggan(int id) {
    auto it = remove_if(daftarPelanggan.begin(), daftarPelanggan.end(), [id](Pelanggan& p) {
        return p.id == id;
    });
    if (it != daftarPelanggan.end()) {
        daftarPelanggan.erase(it, daftarPelanggan.end());
        simpanDatabase();
    }
}

void RentalPS::tambahKonsol(int id, string nama, bool tersedia) {
    KonsolPS konsol = { id, nama, tersedia };
    daftarKonsol.push_back(konsol);
    simpanDatabase();
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

bool RentalPS::sewaKonsol(int idPelanggan, int idKonsol) {
    Pelanggan* pelanggan = cariPelanggan(idPelanggan);
    KonsolPS* konsol = cariKonsol(idKonsol);
    
    if (pelanggan && konsol && konsol->tersedia) {
        konsol->tersedia = false;
        cout << "Konsol PS berhasil disewa oleh " << pelanggan->nama << endl;
        simpanDatabase();
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
        simpanDatabase();
        return true;
    } else {
        cout << "Gagal mengembalikan konsol PS." << endl;
        return false;
    }
}
