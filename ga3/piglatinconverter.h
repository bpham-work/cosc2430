#include "linkedlist.h"
#include <string>
using namespace std;

class PigLatinConverter {
    private:
        bool hasY = false;
        bool hasVowel = false;
        LinkedList<char> charList;
        void loadCharList(string word);
        bool isVowel(char letter);
        bool hasOnlyYAsVowel();
        bool hasNoVowelsAtAll();
    public:
        PigLatinConverter();
        string convert(string word);
        void print();
};

PigLatinConverter::PigLatinConverter() {}

string PigLatinConverter::convert(string word) {
    this->loadCharList(word);

    char firstLetter = charList.peekHead();
    this->charList.append('-');
    if (this->isVowel(firstLetter) || this->hasNoVowelsAtAll()) {
        // Add -way if first letter is vowel or does not have any vowels
        this->charList.append('w');
        this->charList.append('a');
        this->charList.append('y');
    } else if (this->hasOnlyYAsVowel()) {
        // Rotate and add -ay if Y is the only vowel
        while (firstLetter != 'y' && firstLetter != 'Y') {
            this->charList.rotate();
            firstLetter = this->charList.peekHead();
        }
        this->charList.append('a');
        this->charList.append('y');
    } else if (this->hasVowel) {
        // Rotate and add -ay if word has vowel
        while (!this->isVowel(firstLetter)) {
            this->charList.rotate();
            firstLetter = charList.peekHead();
        }
        this->charList.append('a');
        this->charList.append('y');
    }

    return this->charList.toString();
}

void PigLatinConverter::print() {
    this->charList.print();
}

void PigLatinConverter::loadCharList(string word) {
    this->charList.clear();
    this->hasY = false;
    this->hasVowel = false;
    for (string::iterator it = word.begin(); it != word.end(); it++) {
        if (*it == 'y' || *it == 'Y') this->hasY = true;
        if (this->isVowel(*it)) this->hasVowel = true;
        this->charList.append(*it);
    }
}

bool PigLatinConverter::isVowel(char letter) {
    return letter == 'a' || letter == 'A' ||
        letter == 'e' || letter == 'E' ||
        letter == 'i' || letter == 'I' ||
        letter == 'o' || letter == 'O' ||
        letter == 'u' || letter == 'U';
}

bool PigLatinConverter::hasOnlyYAsVowel() {
    return !this->hasVowel && this->hasY;
}

bool PigLatinConverter::hasNoVowelsAtAll() {
    return !this->hasVowel && !this->hasY;
}
