#include <stdio.h>
#include <iostream>
#include <math.h>
#include <gmp.h>
#include <gmpxx.h>
#include <fstream>

mpz_class factorial(int n) {
    mpz_class f = 1;
    for(int k = 2; k <= n; k++){
        f *= k;
    }
    return f;
}

mpz_class falling_factorial(int n, int k) {
    mpz_class f = 1;
    for(int m = 0; m < k; m++){
        f *= n - m;
    }
    return f;
}

mpz_class binomial(int n, int k) {
    return falling_factorial(n, k)/factorial(k);
}

mpz_class sum_array(mpz_class a[], int n) {
    mpz_class sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

mpz_class Euler_number(int n, int k) {
    mpz_class e[k+1], p, b;
    uint32_t N = n;
    for(int i = 0; i < k + 1; i++) {
        b = k + 1 - i;
        mpz_pow_ui(p.get_mpz_t(), b.get_mpz_t(), N);
        e[i] = pow(-1, i % 2)*p*binomial(n + 1, i);
    }
    return sum_array(e, k + 1);
}

void print_Euler_poly(int n) {
    for(int k = 0; k < n - 1; k++) {
        std::cout << Euler_number(n, k) << ", ";
    }
    std::cout << Euler_number(n, n - 1) << "\n";
}

bool cfHP_Y1_test(int n, int m, mpz_class E[], int N, bool p) {
    mpz_class a1[n];
    mpz_class a2[n];
    mpz_class pi;
    mpz_class two = 2;
    mpz_class two_pow, B1, B2, B3;
    int a;
    for(int k = 0; k < n; k++) {
        pi += binomial(m - 1, k);
    }
    pi *= 2;
    for(int r = 0; r < n; r++) {
        a1[r] += pi*binomial(n - 1, r)*pow(-1, r % 2);
    }
    for(int l = 1; l < n; l++) {
        mpz_pow_ui(two_pow.get_mpz_t(), two.get_mpz_t(), uint32_t(l + 1));
        B1 = two_pow*binomial(m, l);
        for(int k = 0; k < n - l; k++){
            B2 += binomial(m - l - 1, k);
        }
        B2 *= B1;
        for(int r = 0; r < n - l; r++) {
            B3 = B2*pow(-1, r % 2)*binomial(n - l - 1, r);
            for(int s = 0; s < l; s++) {
                a2[r + s + 1] += B3*E[l*N + s];
            }
        }
    }
    if (p) {
        if(n == 1) {
            std::cout << "1\n";
        }
        if(n == 2) {
            std::cout << a1[0] + a2[0] << " + " << a1[1] + a2[1] << "T\n";
        }
        if(n > 2) {
            std::cout << a1[0] + a2[0] << " + ";
            std::cout << a1[1] + a2[1] << "*T + ";
            for(int k = 2; k < n - 1; k++) {
                std::cout << a1[k] + a2[k] << "*T^" << k << " + ";
            }
            std::cout << a1[n - 1] + a2[n - 1] << "*T^" << n - 1 << "\n";
        }
    }
    a = 1; // Know a = 0 and a = n - 1 are already pi-multiples.
    while(a < n - 1) {
        if((a1[a] + a2[a]) % pi != 0) {
            return false;
        }
        a += 1;
    }
    return true;
}

int main() {
    int A, B, n, m, dec;
    bool U;
    std::ofstream out_file;
    char name[] = "./UniformTestOutput.txt";
    std::cout << "Which do you want do to?\n  0: Integrality test.\n  1: Compute numerator.\n";
    std::cin >> dec;
    if(dec == 0){ 
        std::cout << "Test all U_{n, m} for n in [A, B] and m up to C.\nA = ";
        std::cin >> A;
        std::cout << "B = ";
        std::cin >> B;
        std::cout << "C = ";
        std::cin >> m;
        // Build Euler table.
        std::cout << "\n==== Integrality Test ===================================\n";
        std::cout << "Saving to file: " << name << "\n";
        std::cout << "Building table with Eulerian numbers.\n";
        mpz_class Euler[B*(B + 1)];
        Euler[0] = 1;
        for(int i = 0; i < B + 1; i++) {
            for(int j = 0; j < i; j++) {
                Euler[i*B + j] = Euler_number(i, j);
            }
        }
        // Run test
        for(int i = A; i < B + 1; i++) {
            std::cout << "Testing n = " << i << " and m in [" << i+1 << ", " << m << "]\n";
            for(int j = i + 1; j < m + 1; j++) {
                U = cfHP_Y1_test(i, j, Euler, B, false);
                if(U) {
                    std::cout << "---- (" << i << ", " << j << ") ----\n";
                    out_file.open(name, std::ios_base::app);
                    out_file << "(" << i << ", " << j << ")\n";
                    out_file.close();
                }
            }
        }
        std::cout << "=========================================================\n";
    }
    else {
        std::cout << "n = ";
        std::cin >> n;
        std::cout << "m = ";
        std::cin >> m;
        // Build Euler table.
        std::cout << "Building table with Eulerian numbers.\n";
        mpz_class Euler[n*(n + 1)];
        Euler[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                Euler[i*n + j] = Euler_number(i, j);
            }
        }
        std::cout << "\n";
        cfHP_Y1_test(n, m, Euler, n, true);
    }
    return 0;
}
