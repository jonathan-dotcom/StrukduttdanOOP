#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>

using namespace std;

// Fungsi untuk menghash sebuah string menggunakan SHA256
string sha256(const string &input) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input.c_str(), input.length());
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    char outputBuffer[65];
    for (int i = 0; i < md_len; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", md_value[i]);
    }
    outputBuffer[64] = 0;

    return outputBuffer;
}

int main() {
    // Simpan username dan password ke dalam struktur data
    struct User {
        string username;
        string password;
    };

    // Daftar pengguna
    User users[100];
    int userCount = 0;

    char choice;
    bool loggedIn = false;
    string username, password;

    do {
        cout << "Menu:" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                cout << "Masukkan username: ";
                cin >> users[userCount].username;
                cout << "Masukkan password: ";
                cin >> users[userCount].password;
                users[userCount].password = sha256(users[userCount].password); // Hash password
                userCount++;
                cout << "Registrasi berhasil!" << endl;
                break;
            case '2':
                cout << "Masukkan username: ";
                cin >> username;
                cout << "Masukkan password: ";
                cin >> password;
                password = sha256(password); // Hash password

                loggedIn = false;
                for (int i = 0; i < userCount; i++) {
                    if (users[i].username == username && users[i].password == password) {
                        loggedIn = true;
                        break;
                    }
                }

                if (loggedIn) {
                    cout << "Login berhasil!" << endl;
                } else {
                    cout << "Login gagal. Username atau password salah." << endl;
                }
                break;
            case '3':
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != '3');

    return 0;
}

