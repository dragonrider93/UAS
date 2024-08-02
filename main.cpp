#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Barang {
    int id;
    string nama;
    int jumlah;
    double harga;
};

class Gudang {
private:
    vector<Barang> daftarBarang;

public:
    void tambahBarang(int id, const string& nama, int jumlah, double harga) {
        if (id < 0 || jumlah < 0 || harga < 0) {
            cout << "ID, jumlah, dan harga tidak boleh negatif.\n";
            return;
        }

        for (const auto& barang : daftarBarang) {
            if (barang.id == id) {
                cout << "Barang dengan ID " << id << " sudah ada.\n";
                return;
            }
        }

        Barang barang = {id, nama, jumlah, harga};
        daftarBarang.push_back(barang);
        cout << "Barang telah ditambahkan.\n";
    }

    void hapusBarang(int id) {
        for (auto it = daftarBarang.begin(); it != daftarBarang.end(); ++it) {
            if (it->id == id) {
                daftarBarang.erase(it);
                cout << "Barang dengan ID " << id << " telah dihapus.\n";
                return;
            }
        }
        cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
    }

    Barang* cariBarang(int id) {
        for (auto& barang : daftarBarang) {
            if (barang.id == id) {
                return &barang;
            }
        }
        cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
        return nullptr;
    }

    void perbaruiBarang(int id, const string& nama, int jumlah, double harga) {
        if (jumlah < 0 || harga < 0) {
            cout << "Jumlah dan harga tidak boleh negatif.\n";
            return;
        }

        Barang* barang = cariBarang(id);
        if (barang != nullptr) {
            barang->nama = nama;
            barang->jumlah = jumlah;
            barang->harga = harga;
            cout << "Barang dengan ID " << id << " telah diperbarui.\n";
        }
    }

    void tampilkanBarang() const {
        if (daftarBarang.empty()) {
            cout << "Tidak ada barang di gudang.\n";
            return;
        }

        for (const auto& barang : daftarBarang) {
            cout << "ID: " << barang.id << ", Nama: " << barang.nama
                 << ", Jumlah: " << barang.jumlah << ", Harga: " << barang.harga << '\n';
        }
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Gudang gudang;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Hapus Barang\n";
        cout << "3. Cari Barang\n";
        cout << "4. Perbarui Barang\n";
        cout << "5. Tampilkan Semua Barang\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (cin.fail()) {
            clearInput();
            cout << "Pilihan tidak valid. Masukkan angka 1-6.\n";
            continue;
        }

        switch (pilihan) {
            case 1: {
                int id, jumlah;
                string nama;
                double harga;
                cout << "Masukkan ID: ";
                cin >> id;
                if (cin.fail()) {
                    clearInput();
                    cout << "ID harus berupa angka.\n";
                    break;
                }
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jumlah: ";
                cin >> jumlah;
                if (cin.fail()) {
                    clearInput();
                    cout << "Jumlah harus berupa angka.\n";
                    break;
                }
                cout << "Masukkan Harga: ";
                cin >> harga;
                if (cin.fail()) {
                    clearInput();
                    cout << "Harga harus berupa angka.\n";
                    break;
                }
                gudang.tambahBarang(id, nama, jumlah, harga);
                break;
            }
            case 2: {
                int id;
                cout << "Masukkan ID barang yang akan dihapus: ";
                cin >> id;
                if (cin.fail()) {
                    clearInput();
                    cout << "ID harus berupa angka.\n";
                    break;
                }
                gudang.hapusBarang(id);
                break;
            }
            case 3: {
                int id;
                cout << "Masukkan ID barang yang akan dicari: ";
                cin >> id;
                if (cin.fail()) {
                    clearInput();
                    cout << "ID harus berupa angka.\n";
                    break;
                }
                Barang* barang = gudang.cariBarang(id);
                if (barang != nullptr) {
                    cout << "ID: " << barang->id << ", Nama: " << barang->nama
                         << ", Jumlah: " << barang->jumlah << ", Harga: " << barang->harga << '\n';
                }
                break;
            }
            case 4: {
                int id, jumlah;
                string nama;
                double harga;
                cout << "Masukkan ID barang yang akan diperbarui: ";
                cin >> id;
                if (cin.fail()) {
                    clearInput();
                    cout << "ID harus berupa angka.\n";
                    break;
                }
                cout << "Masukkan Nama baru: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jumlah baru: ";
                cin >> jumlah;
                if (cin.fail()) {
                    clearInput();
                    cout << "Jumlah harus berupa angka.\n";
                    break;
                }
                cout << "Masukkan Harga baru: ";
                cin >> harga;
                if (cin.fail()) {
                    clearInput();
                    cout << "Harga harus berupa angka.\n";
                    break;
                }
                gudang.perbaruiBarang(id, nama, jumlah, harga);
                break;
            }
            case 5: {
                cout << "Daftar Barang:\n";
                gudang.tampilkanBarang();
                break;
            }
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Masukkan angka 1-6.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
