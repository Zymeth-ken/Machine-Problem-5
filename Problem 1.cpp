#include <iostream>
#include <vector>
using namespace std;

void displayArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

void bubbleSort(vector<int>& arr, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    for (size_t i = 0; i < arr.size() - 1; ++i)
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            ++comparisons;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]), ++swaps;
        }
}

void insertionSort(vector<int>& arr, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            ++comparisons; 
            arr[j + 1] = arr[j];
            --j;
            ++swaps; 
        }
        arr[j + 1] = key;
        if (j >= 0) ++comparisons; // Increment for the final comparison when the while loop exits
    }
}

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j)
            if (++comparisons && arr[j] < arr[minIndex]) minIndex = j;
        if (minIndex != i) swap(arr[i], arr[minIndex]), ++swaps;
    }
}

void merge(vector<int>& arr, int left, int mid, int right, int& comparisons, int& swaps) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        ++comparisons; // Increment for each comparison
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            ++swaps; // Increment for each element taken from the right subarray
        }
    }

    // Copy remaining elements from L
    while (i < L.size()) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements from R
    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}

void mergeSortHelper(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid, comparisons, swaps);
        mergeSortHelper(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

void mergeSort(vector<int>& arr, int& comparisons, int& swaps) {
    comparisons = swaps = 0;
    mergeSortHelper(arr, 0, arr.size() - 1, comparisons, swaps);
}

int main() {
    vector<vector<int>> predefinedArrays = {
        {2, 1, 5, 4, 3}, {6, 1, 7, 5, 2},
        {9, 8, 7, 5, 6}, {7, 6, 4, 3, 5}
    };

    char continueChoice;
    do {
        cout << "Choose The Elements Below:\n"
             << "[A] 2 1 5 4 3\n"
             << "[B] 6 1 7 5 2 \n"
             << "[C] 9 8 7 5 6\n"
             << "[D] 7 6 4 3 5\n"
             << "-----------------------------------------\n"
             << "Enter The Element: ";
        char arrayChoice;
        cin >> arrayChoice;

        vector<int> arr;
        if (arrayChoice == 'A' || arrayChoice == 'a') arr = predefinedArrays[0];
        else if (arrayChoice == 'B' || arrayChoice == 'b') arr = predefinedArrays[1];
        else if (arrayChoice == 'C' || arrayChoice == 'c') arr = predefinedArrays[2];
        else if (arrayChoice == 'D' || arrayChoice == 'd') arr = predefinedArrays[3];
        else {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "-----------------------------------------\n"
             << "Choose The Sorting Algorithm Below:\n"
             << "[A] Bubble Sort\n"
             << "[B] Insertion Sort\n"
             << "[C] Selection Sort\n"
             << "[D] Merge Sort\n"
             << "[E] Exit\n"
             << "-----------------------------------------\n"
             << "Enter The Sorting Algorithm: ";
        char sortChoice;
        cin >> sortChoice;

        if (sortChoice == 'E' || sortChoice == 'e') {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        vector<int> sortedArr = arr;
        int comparisons = 0, swaps = 0;

        switch (tolower(sortChoice)) {
            case 'a': bubbleSort(sortedArr, comparisons, swaps); cout << "Bubble Sort Result: "; break;
            case 'b': insertionSort(sortedArr, comparisons, swaps); cout << "Insertion Sort Result: "; break;
            case 'c': selectionSort(sortedArr, comparisons, swaps); cout << "Selection Sort Result: "; break;
            case 'd': mergeSort(sortedArr, comparisons, swaps); cout << "Merge Sort Result: "; break;
            default: cout << "Invalid choice!" << endl; continue;
        }

        displayArray(sortedArr);
        cout << "-----------------------------------------\n"
             << "Number of comparisons: " << comparisons << "\nNumber of swaps: " << swaps << endl
             << "-----------------------------------------\nDo you want to continue? [Y/N]: ";
        cin >> continueChoice;

    } while (tolower(continueChoice) == 'y');

    cout << "The Program has been Terminated. Thank you!" << endl;
    return 0;
}