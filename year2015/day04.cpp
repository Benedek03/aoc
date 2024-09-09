#include <openssl/evp.h>

#include <iomanip>
#include <iostream>
#include <sstream>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
    std::string md5(const std::string& content) {
        EVP_MD_CTX* context = EVP_MD_CTX_new();
        const EVP_MD* md = EVP_md5();
        unsigned char md_value[EVP_MAX_MD_SIZE];
        unsigned int md_len;
        std::string output;

        EVP_DigestInit_ex2(context, md, NULL);
        EVP_DigestUpdate(context, content.c_str(), content.length());
        EVP_DigestFinal_ex(context, md_value, &md_len);
        EVP_MD_CTX_free(context);

        output.resize(md_len * 2);
        for (unsigned int i = 0; i < md_len; ++i)
            std::sprintf(&output[i * 2], "%02x", md_value[i]);
        return output;
    }

   public:
    Solution(std::string inputFileName = "inputs/2015/4.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        std::string s;
        inputFile >> s;

        std::string out;
        size_t i = 0;
        do {
            i++;
            out = md5(s + std::to_string(i));
        } while (out.substr(0, 5) != "00000");
        return std::to_string(i);
    }
    std::string part2() {
        std::string s;
        inputFile >> s;

        std::string out;
        size_t i = 0;
        do {
            i++;
            out = md5(s + std::to_string(i));
        } while (out.substr(0, 6) != "000000");
        return std::to_string(i);
    }
};

int main() {
    Solution d = Solution();
    d.solve();
}
