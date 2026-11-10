# Complex Number Calculator

A robust Object-Oriented C++ implementation of a Complex Number Calculator supporting arithmetic operations (+, -, *) with custom formatted I/O handling.

---

## 👥 Contributors
- **Garvit** (Enrollment No: `20014803125`)
- **Rishita** (Enrollment No: `20114803125`)
- **Course**: B.Tech Information Technology (Semester 3)

---

## 📌 Features
- **Encapsulation**: Private data members for real and imaginary parts.
- **Constructors**: Default (zero-initialized) and parameterized constructors.
- **Operator Overloading**: Overloaded `+`, `-`, and `*` operators.
- **Clean I/O**: Overloaded `<<` and `>>` stream operators to handle signed outputs (`a + bi`, `a - bi`, zero values, and pure imaginaries).
- **Edge-Case Handled**: Properly handles zero values, negative coefficients, and unit imaginary numbers ($i$).

---

## 🛠️ Compilation & Execution

### Prerequisites
A standard C++ compiler (`g++`, `clang++`, or MSVC).

### Using GCC / Terminal
```bash
# 1. Compile the source file
g++ -std=c++17 main.cpp -o complex_calculator

# 2. Run the executable
./complex_calculator
