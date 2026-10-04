#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3f * uts) + (0.4f * uas) + (0.3f * tugas);
}

int main() {
    const int MAX_MHS = 10;
    Mahasiswa daftarMhs[MAX_MHS];
    int n;

    cout << "============================================" << endl;
    cout << "     PROGRAM PENGELOLAAN NILAI MAHASISWA    " << endl;
    cout << "============================================" << endl;
    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> n;

    if (n > MAX_MHS || n <= 0) {
        cout << "Jumlah data tidak valid! Program berhenti." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama        : ";
        cin.ignore();
        getline(cin, daftarMhs[i].nama);
        cout << "NIM         : ";
        cin >> daftarMhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> daftarMhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> daftarMhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> daftarMhs[i].tugas;

        daftarMhs[i].nilaiAkhir = hitungNilaiAkhir(
            daftarMhs[i].uts, 
            daftarMhs[i].uas, 
            daftarMhs[i].tugas
        );
    }

    cout << "\n=======================================================================" << endl;
    cout << left << setw(5)  << "No" 
         << setw(20) << "Nama" 
         << setw(15) << "NIM" 
         << setw(8)  << "UTS" 
         << setw(8)  << "UAS" 
         << setw(8)  << "Tugas" 
         << setw(10) << "Akhir" << endl;
    cout << "=======================================================================" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(5)  << (i + 1)
             << setw(20) << daftarMhs[i].nama
             << setw(15) << daftarMhs[i].nim
             << fixed << setprecision(2)
             << setw(8)  << daftarMhs[i].uts
             << setw(8)  << daftarMhs[i].uas
             << setw(8)  << daftarMhs[i].tugas
             << setw(10) << daftarMhs[i].nilaiAkhir << endl;
    }
    cout << "=======================================================================" << endl;

    return 0;
}