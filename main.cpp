#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor (initializes to 0 + 0i)
    Complex() : real(0.0), imag(0.0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Getter methods
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Operator Overloading: Addition (+)
    Complex operator+(const Complex& other) const {
        return Complex(this->real + other.real, this->imag + other.imag);
    }

    // Operator Overloading: Subtraction (-)
    Complex operator-(const Complex& other) const {
        return Complex(this->real - other.real, this->imag - other.imag);
    }

    // Operator Overloading: Multiplication (*)
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& other) const {
        double r = (this->real * other.real) - (this->imag * other.imag);
        double i = (this->real * other.imag) + (this->imag * other.real);
        return Complex(r, i);
    }

    // Friend functions for Stream Insertion (<<) and Extraction (>>)
    // Separates I/O logic cleanly from mathematical operations
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    friend std::istream& operator>>(std::istream& in, Complex& c);
};

// Stream Insertion Operator: formats output into readable "a + bi" or "a - bi"
std::ostream& operator<<(std::ostream& out, const Complex& c) {
    if (c.real == 0.0 && c.imag == 0.0) {
        out << "0";
        return out;
    }

    if (c.real != 0.0) {
        out << c.real;
    }

    if (c.imag != 0.0) {
        if (c.imag > 0.0) {
            if (c.real != 0.0) out << " + ";
            if (c.imag == 1.0) out << "i";
            else out << c.imag << "i";
        } else {
            if (c.real != 0.0) out << " - ";
            else out << "-";
            if (c.imag == -1.0) out << "i";
            else out << std::abs(c.imag) << "i";
        }
    }

    return out;
}

// Stream Extraction Operator: standard user input
std::istream& operator>>(std::istream& in, Complex& c) {
    std::cout << "  Real part: ";
    in >> c.real;
    std::cout << "  Imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    std::cout << "==========================================\n";
    std::cout << "         COMPLEX NUMBER CALCULATOR        \n";
    std::cout << "==========================================\n\n";

    Complex c1, c2;

    std::cout << "Enter details for First Complex Number:\n";
    std::cin >> c1;

    std::cout << "\nEnter details for Second Complex Number:\n";
    std::cin >> c2;

    std::cout << "\n------------------------------------------\n";
    std::cout << "Entered Numbers:\n";
    std::cout << "C1 = " << c1 << "\n";
    std::cout << "C2 = " << c2 << "\n";
    std::cout << "------------------------------------------\n";

    // Arithmetic computations using overloaded operators
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    std::cout << "\nCalculation Results:\n";
    std::cout << "Addition       (C1 + C2) : " << sum << "\n";
    std::cout << "Subtraction    (C1 - C2) : " << diff << "\n";
    std::cout << "Multiplication (C1 * C2) : " << prod << "\n";
    std::cout << "------------------------------------------\n";

    return 0;
}
