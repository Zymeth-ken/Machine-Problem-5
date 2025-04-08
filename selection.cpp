#include <iostream>
#include <string>

using namespace std;

void selectionSort(string names[], int shelflife[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (shelflife[j] < shelflife[minIndex]) {
                minIndex = j;
            }
        }

       
        swap(names[i], names[minIndex]);
        swap(shelflife[i], shelflife[minIndex]);
    }
}

int main() {
    const int n = 8;
    string names[n] = {"Mangoes", "Apple", "C2 red", "bukopie", "Magic_sarap", "C2 green", "boy-bawang", "banana"};
    int shelflife[n] = {60, 38, 360, 120, 520, 360, 400, 24};

    selectionSort(names, shelflife, n);

    cout << "Sorted Products by Shelf life:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << " - Shelf life: " << shelflife[i] << " days" << endl;
    }

    return 0;
}
