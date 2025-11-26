#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//  convert usernames to lowercase
string toLowerCase(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

void registerUser() {
    string username, password;

    cin.ignore(); // clear leftover newline

    cout << "Enter username: ";
    getline(cin, username);

    username = toLowerCase(username);

    cout << "Enter password: ";
    getline(cin, password);

    ofstream file((username + ".txt").c_str());
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "Registration successful.\n";
    } else {
        cout << "Error creating user file.\n";
    }
}

bool loginUser() {
    string username, password, storedUser, storedPass;

    cin.ignore(); // clear leftover newline

    cout << "Enter username: ";
    getline(cin, username);

    username = toLowerCase(username);

    cout << "Enter password: ";
    getline(cin, password);

    ifstream file((username + ".txt").c_str());
    if (file.is_open()) {
        getline(file, storedUser);
        getline(file, storedPass);
        file.close();

        storedUser = toLowerCase(storedUser);

        if (username == storedUser && password == storedPass) {
            cout << "Login successful.\n";
            return true;
        } else {
            cout << "Invalid credentials.\n";
            return false;
        }
    } else {
        cout << "User not found.\n";
        return false;
    }
}

int main() {
    int choice;

    while (true) {   //  runs indefinitely
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) { //  handle non-numeric input
            cin.clear();
            cin.ignore(1000, '\n'); // ignore up to 1000 chars until newline
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            cout << "Exiting... Goodbye!\n";
            break;  // ✅ exits loop
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
