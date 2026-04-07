# 🏦 ATM Machine Simulation (C)

## 📌 Overview

This project is a modular ATM Machine Simulation developed using the C programming language.
It allows users to perform basic banking operations such as authentication, balance inquiry, deposit, and withdrawal using a file-based system.

The project follows a structured modular approach, improving code readability, maintainability, and scalability.

---

## 🚀 Features

* 🔐 User Authentication (Account Number & PIN)
* 💰 Balance Inquiry
* 💵 Deposit Money
* 💸 Withdraw Money (with validation)
* 💾 File Handling for persistent data storage
* 🧩 Modular Programming (separate `.c` and `.h` files)

---

## 🏗️ Project Structure

```
ATM_Project/
│
├── main.c              # Main driver program
├── auth.c / auth.h     # Authentication module
├── account.c / account.h   # Account operations
├── file_ops.c / file_ops.h # File handling
├── string_utils.c / string_utils.h # String functions
├── accounts.txt        # Data storage file
└── README.md
```

---

## ⚙️ Technologies Used

* C Programming Language
* File Handling
* Structures & Pointers
* Modular Programming

---

## ▶️ How to Run

### Step 1: Compile

```
gcc main.c auth.c account.c file_ops.c string_utils.c -o atm
```

### Step 2: Run

```
./atm
```

---

## 📂 Sample Data (accounts.txt)

```
1001 Rahul 1234 5000
1002 Aman 4321 8000
```

---

## 🧠 Concepts Used

* Structures (`struct`)
* File handling (`fopen`, `fscanf`, `fprintf`)
* Modular design
* Pointer usage
* Input validation

---

## 🎯 Learning Outcomes

* Understanding modular programming in C
* Working with file-based data storage
* Implementing real-world logic (ATM system)
* Improving debugging and problem-solving skills

---

## 🔮 Future Improvements

* Limit login attempts (security enhancement)
* Hide PIN input (masking)
* Add transaction history
* Support multiple users dynamically

---

## 👨‍💻 Author

Developed as part of Project-Based Learning (PBL).

---

## ⭐ If you like this project

Give it a star on GitHub ⭐
