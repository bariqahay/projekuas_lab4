#ifndef RENTAL_PS_H
#define RENTAL_PS_H

#include <string>
#include <vector>

using namespace std;

// Struktur untuk data pelanggan
struct Pelanggan {
    int id;
    string nama;
    string alamat;
};

// Struktur untuk data konsol PS
struct KonsolPS {
    int id;
    string nama;
    bool tersedia;
};

// Kelas untuk rental PS
class RentalPS {
private:
    vector<Pelanggan> daftarPelanggan;
    vector<KonsolPS> daftarKonsol;
    
public:
    RentalPS();
    void tambahPelanggan(int id, string nama, string alamat);
    void tambahKonsol(int id, string nama, bool tersedia);
    void tampilkanPelanggan();
    void tampilkanKonsol();
    Pelanggan* cariPelanggan(int id);
    KonsolPS* cariKonsol(int id);
    bool sewaKonsol(int idPelanggan, int idKonsol);
    bool kembalikanKonsol(int idKonsol);
};

#endif
