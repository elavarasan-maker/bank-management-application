# Bank Management Application
C++17 console application using a `Bank` class, `Account` structure, vectors and file handling.

Features: create account, deposit, withdraw, balance inquiry, list accounts, and persistent records in `accounts.txt`.

Compile:
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o bank
./bank
```
Windows: `g++ -std=c++17 main.cpp -o bank.exe` then `.ank.exe`.

Security limitation: this is an educational simulation. Account records are plain text and there is no customer authentication, encryption, audit trail or concurrency control. Never use real financial/customer data or present it as production banking software.
