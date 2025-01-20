
# Secure Login System

A basic C++ application providing a secure login system. Users can sign up, log in, and recover forgotten passwords. User data is securely stored in a file.

## Features
- **Sign-Up**: Allows new users to register by entering their username, email, and password.
- **Login**: Authenticates existing users by checking their username and password.
- **Forgot Password**: Helps users recover their forgotten password by verifying their username and email.
- **Data Storage**: User details are stored in a file named `loginData.txt`.

## How to Use
1. **Clone the repository** or download the source code.
2. **Compile the code** using a C++ compiler (e.g., `g++`).
   ```bash
   g++ -o secure_login_system secure_login_system.cpp
   ```
3. **Run the compiled program**.
   ```bash
   ./secure_login_system
   ```
4. Follow the menu prompts to sign up, log in, or recover a password.

## Menu Options
- **1 - Login**: Enter your username and password to log in.
- **2 - Sign-Up**: Register as a new user by providing your username, email, and password.
- **3 - Forgot Password**: Recover your password by entering your registered username and email.
- **4 - Exit**: Exit the application.

## File Format
User details are stored in `loginData.txt` in the following format:
```
username*email*password
```

## Example
```
john_doe*john@example.com*securepassword123
```

## Code Overview
```cpp
#include <iostream>
#include <fstream>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUP();
    void forgot();
} obj;

int main() {
    char choice;
    while (true) {
        cout << "\n\n\t\t..:: Secure Login System ::..";
        cout << "\n\n\t\t\t1- Login";
        cout << "\n\t\t\t2- Sign-Up";
        cout << "\n\t\t\t3- Forgot Password";
        cout << "\n\t\t\t4- Exit";
        cout << "\n\n\t..:: Enter Your Choice\t: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cin.ignore();
            obj.login();
            break;
        case '2':
            cin.ignore();
            obj.signUP();
            break;
        case '3':
            cin.ignore();
            obj.forgot();
            break;
        case '4':
            return 0;
        default:
            cout << "Invalid Selection...!";
        }
    }
}

void temp::signUP() {
    // Sign-Up Implementation
}

void temp::login() {
    // Login Implementation
}

void temp::forgot() {
    // Forgot Password Implementation
}
```


## Author
[SagarBiswas-MultiHAT](https://github.com/SagarBiswas-MultiHAT)

