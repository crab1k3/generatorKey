#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

std::string generateKey() {
    std::string key;
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < 25; ++i) {
        if (i != 0 && i % 5 == 0) {
            key += '-';
        }

        char randomChar = characters[rand() % characters.length()];
        key += randomChar;
    }

    return key;
}

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time

    int numKeys;
    std::cout << "Enter the number of keys to generate: ";
    std::cin >> numKeys;

    if (numKeys <= 0) {
        std::cout << "Invalid number of keys." << std::endl;
        return 1;
    }

    std::vector<std::string> keys;

    for (int i = 0; i < numKeys; ++i) {
        std::string key = generateKey();
        keys.push_back(key);
    }

    std::cout << "Generated keys:" << std::endl;
    for (const std::string& key : keys) {
        std::cout << key << std::endl;
    }

    system("pause");
}