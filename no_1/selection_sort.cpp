#include <iostream>
#include <vector>
#include <string>

struct Data {
    std::string Nama;
    std::string Alamat;
};

void selectionSort(std::vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j].Nama < data[min_idx].Nama) {
                min_idx = j;
            }
        }
        std::swap(data[i], data[min_idx]);
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

    selectionSort(data);

    std::cout << "Hasil pengurutan dengan Selection Sort:\n";
    for (const auto& item : data) {
        std::cout << "Nama: " << item.Nama << ", Alamat: " << item.Alamat << std::endl;
    }

    return 0;
}
