#include<iostream>
#include<fstream>
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
        cout << "\n=============================================================";
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

    cout << "\n\n\t\t\t----------SIGN UP---------" << "\n\n";
    cout << "\n..:: Enter Your User Name\t\t: ";
    getline(cin, userName);
    cout << "..:: Enter Your Email Address\t\t: ";
    getline(cin, Email);
    cout << "..:: Enter Your Password\t\t: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::login() {
    cout << "\n\n\t\t\t----------LOGIN---------" << "\n\n";
    cout << "..:: Enter Your User Name\t: ";
    getline(cin, searchName);
    cout << "..:: Enter Your Password\t: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\n\t==> Account Login Successful...!\n";
                cout << "\n..:: Username\t\t: " << userName << endl;
                cout << "\n..:: Email\t\t: " << Email << endl;
                found = true;
                break;
            }
            else {
                cout << "\n\t\t==> Password is Incorrect...!";
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "\n\t\t==> User not found...!";
    }
    file.close();
}

void temp::forgot() {
    cout << "\n\n..:: Enter Your UserName\t\t: ";
    getline(cin, searchName);
    cout << "\n..:: Enter Your Email Address\t\t: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (userName == searchName && Email == searchEmail) {
            cout << "\nAccount Found...!" << endl;
            cout << "\n\t==> Your Password : " << password << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Account not found...!";
    }
    file.close();
}