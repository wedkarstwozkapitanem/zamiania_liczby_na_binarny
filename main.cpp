
#include <iostream>
#include <vector>

long long potega(int n);
struct {
    long long wynik = 2, potega = 1;
} dane;

int main() {
    long long n = 0; std::cin >> n;

    potega(n);


    std::vector<int> binarny(256);

    int szukany_n = dane.wynik;
    while (n != 0) {
        n -= potega(n);
        int licznik = 0;
        for (int i = binarny.size(); i >= 0; i--) {
            if (licznik == dane.potega) {
                binarny[i] = 1;
            }
                licznik++;
        }
    }
    

    std::cout << "Liczba w systemie binarnym: ";
    bool start = false;
    for (int i : binarny) {
        if (i == 1) start = true;
        if (start)
        std::cout << i << " ";
    }


    return 0;
}


long long potega(int n) {
    long long wynik = 1, potega = 1;
    while (n > wynik) {
        if (n <= wynik) {
            break;
        }
        else {
            if ((wynik * 2) <= n) {
                wynik *= 2;
                potega++;
            }
            else {
                break;
            }
        }
    }
    dane.potega = potega;
    dane.wynik = wynik;
    return wynik;
}
