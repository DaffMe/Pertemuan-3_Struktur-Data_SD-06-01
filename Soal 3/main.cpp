#include <iostream>
#include <iomanip>

using namespace std;

const int BARIS = 3;
const int KOLOM = 3;

void tampilkanMatriks(int mat[BARIS][KOLOM], string namaMatriks) {
    cout << "Matriks " << namaMatriks << ":" << endl;
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
}

void tukarElemenMatriks(int matA[BARIS][KOLOM], int matB[BARIS][KOLOM], int b, int k) {
    if (b >= 0 && b < BARIS && k >= 0 && k < KOLOM) {
        int temp = matA[b][k];
        matA[b][k] = matB[b][k];
        matB[b][k] = temp;
        cout << ">> Pertukaran elemen posisi [" << b << "][" << k << "] berhasil dilakukan.\n";
    } else {
        cout << ">> Indeks posisi di luar batas matriks!\n";
    }
}

void tukarNilaiPointer(int *p1, int *p2) {
    if (p1 != nullptr && p2 != nullptr) {
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        cout << ">> Pertukaran nilai via pointer berhasil dilakukan.\n";
    }
}

int main() {
    int matriks1[BARIS][KOLOM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriks2[BARIS][KOLOM] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    cout << "=== KONDISI AWAL MATRIKS 2D ===" << endl;
    tampilkanMatriks(matriks1, "A");
    cout << endl;
    tampilkanMatriks(matriks2, "B");
    cout << endl;

    // 2. Menukarkan elemen array 2D pada posisi baris ke-1, kolom ke-1 (tengah: 5 dan 50)
    int targetBaris = 1;
    int targetKolom = 1;
    cout << "--- Menukarkan elemen koordinat [" << targetBaris << "][" << targetKolom << "] ---" << endl;
    tukarElemenMatriks(matriks1, matriks2, targetBaris, targetKolom);
    cout << endl;

    cout << "=== KONDISI MATRIKS SETELAH PERTUKARAN ELEMEN ===" << endl;
    tampilkanMatriks(matriks1, "A");
    cout << endl;
    tampilkanMatriks(matriks2, "B");
    cout << endl;

    int valX = 100;
    int valY = 999;
    int *ptr1 = &valX;
    int *ptr2 = &valY;

    cout << "=== PERTUKARAN NILAI DENGAN 2 POINTER ===" << endl;
    cout << "Kondisi Sebelum Tukar:" << endl;
    cout << "Nilai valX       : " << valX << " (ditunjuk oleh *ptr1: " << *ptr1 << ")" << endl;
    cout << "Nilai valY       : " << valY << " (ditunjuk oleh *ptr2: " << *ptr2 << ")" << endl;
    cout << endl;

    tukarNilaiPointer(ptr1, ptr2);
    cout << endl;

    cout << "Kondisi Setelah Tukar:" << endl;
    cout << "Nilai valX       : " << valX << " (ditunjuk oleh *ptr1: " << *ptr1 << ")" << endl;
    cout << "Nilai valY       : " << valY << " (ditunjuk oleh *ptr2: " << *ptr2 << ")" << endl;

    return 0;
}