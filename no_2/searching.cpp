#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mengurutkan array menggunakan selection sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Fungsi untuk melakukan binary search dan menemukan semua indeks elemen yang dicari
vector<int> binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    vector<int> foundIndices;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            foundIndices.push_back(mid);

            // Cari di bagian kiri array
            int temp = mid - 1;
            while (temp >= 0 && arr[temp] == target) {
                foundIndices.push_back(temp);
                temp--;
            }

            // Cari di bagian kanan array
            temp = mid + 1;
            while (temp < arr.size() && arr[temp] == target) {
                foundIndices.push_back(temp);
                temp++;
            }
            break;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return foundIndices;
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};

    // Urutkan array dengan selection sort
    selectionSort(arr);

    // Test cases untuk binary search
    vector<int> testCases = {1, 50, 100};

    for (int num : testCases) {
        vector<int> indices = binarySearch(arr, num);
        if (!indices.empty()) {
            cout << "Angka " << num << " ditemukan di indeks: ";
            for (size_t i = 0; i < indices.size(); i++) {
                cout << indices[i];
                if (i < indices.size() - 1) cout << ", ";
            }
            cout << endl;
        } else {
            cout << "Angka " << num << " tidak ditemukan dalam array" << endl;
        }
    }

    return 0;
}
