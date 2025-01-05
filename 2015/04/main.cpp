#include <openssl/evp.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

ifstream inputFile;

string md5(const string& content) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    const EVP_MD* md = EVP_md5();
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    string output;

    EVP_DigestInit_ex2(context, md, NULL);
    EVP_DigestUpdate(context, content.c_str(), content.length());
    EVP_DigestFinal_ex(context, md_value, &md_len);
    EVP_MD_CTX_free(context);

    output.resize(md_len * 2);
    for (unsigned int i = 0; i < md_len; ++i)
        sprintf(&output[i * 2], "%02x", md_value[i]);
    return output;
}

string part1() {
    string s;
    inputFile >> s;

    string out;
    size_t i = 0;
    do {
        i++;
        out = md5(s + to_string(i));
    } while (out.substr(0, 5) != "00000");
    return to_string(i);
}
string part2() {
    string s;
    inputFile >> s;

    string out;
    size_t i = 0;
    do {
        i++;
        out = md5(s + to_string(i));
    } while (out.substr(0, 6) != "000000");
    return to_string(i);
}


int main() {
    cout << "2015/04:" << endl;

    inputFile.open("2015/04/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2015/04/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}