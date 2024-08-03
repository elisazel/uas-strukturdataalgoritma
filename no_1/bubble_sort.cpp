#include <iostream>
#include <vector>
#include <string>

struct Data {
    std::string Nama;
    std::string Alamat;
};

void bubbleSort(std::vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].Nama > data[j + 1].Nama) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<Data> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    bubbleSort(data);

    std::cout << "Hasil pengurutan dengan Bubble Sort:\n";
    for (const auto& item : data) {
        std::cout << "Nama: " << item.Nama << ", Alamat: " << item.Alamat << std::endl;
    }

    return 0;
}
