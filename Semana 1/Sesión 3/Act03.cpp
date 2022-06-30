#include <iostream>

int sumaImpares(int arr[]) {
    int suma = 0;
    for (int i = 0; i <= sizeof(arr[0]); i++) {
        if (arr[i] % 2 == 1) {
            suma += arr[i];
        }
    }
    return suma;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9};
    std::cout << "Suma: " << sumaImpares(arr);
    return 0;
}
