#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

void horner(std::vector<int>& coefficients, std::vector<int>& deflated_coefficients, std::vector<int>& remainders, int r) {
    int n = coefficients.size();
    deflated_coefficients.clear();
    deflated_coefficients.push_back(coefficients[0]);
    for (int i = 1; i < n; i++) {
        coefficients[i] += coefficients[i-1] * r;
        if (i < n - 1) {
            deflated_coefficients.push_back(coefficients[i]);
        }
    }
    remainders.push_back(coefficients[n-1]);
}

int main() {
    char cont;
    do {
        int n;
        std::cout << "Enter the degree of function: ";
        std::cin >> n;
        if (n > 10) {
            std::cout << "Too large degree. Try again!.";
            return 0;
        }

        std::vector<int> coefficients(n + 1);
        for (int i = 0; i < coefficients.size() ; i++) {
            std::cout << "Coefficient for x^" << n - i << ": ";
            std::cin >> coefficients[i];
        }

        int r;
        std::cout << "Enter the value of x: ";
        std::cin >> r;

        std::vector<int> deflated_coefficients;
        std::vector<int> remainders;
        horner(coefficients, deflated_coefficients, remainders, r);

        std::cout << "Deflated coefficients = [";
        for (int i = 0; i < deflated_coefficients.size(); i++) {
            std::cout << deflated_coefficients[i];
            if (i < deflated_coefficients.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;

        std::cout << "Remainders = [";
        for (int i = 0; i < remainders.size(); i++) {
            std::cout << remainders[i];
            if (i < remainders.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;

        std::cout << "Continue to divide polynomial function? Enter Y/N" << std::endl;
        std::cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    std::cout << "Exited!" << std::endl;
    return 0;
}