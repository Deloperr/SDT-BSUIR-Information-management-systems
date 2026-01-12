#include <iostream>
#include <string>
#include <map>


class English {
private:
    std::map<std::string, std::string> dictionary = {
        {"кот", "cat"}, {"дом", "house"}, {"солнце", "sun"},
        {"вода", "water"}, {"хлеб", "bread"}, {"книга", "book"},
        {"окно", "window"}, {"дверь", "door"}, {"стол", "table"}, {"стул", "chair"}
    };

public:
    std::string translate(const std::string& word) {
        return dictionary.count(word) ? dictionary[word] : "Unknown word";
    }

    std::string reverseTranslate(const std::string& word) {
        for (const auto& pair : dictionary) {
            if (pair.second == word) return pair.first;
        }
        return "Unknown word";
    }
};


class German {
private:
    std::map<std::string, std::string> dictionary = {
        {"кот", "Katze"}, {"дом", "Haus"}, {"солнце", "Sonne"},
        {"вода", "Wasser"}, {"хлеб", "Brot"}, {"книга", "Buch"},
        {"окно", "Fenster"}, {"дверь", "Tür"}, {"стол", "Tisch"}, {"стул", "Stuhl"}
    };

public:
    std::string translate(const std::string& word) {
        return dictionary.count(word) ? dictionary[word] : "Unbekanntes Wort";
    }

    std::string reverseTranslate(const std::string& word) {
        for (const auto& pair : dictionary) {
            if (pair.second == word) return pair.first;
        }
        return "Unbekanntes Wort";
    }
};


class LanguageFacade {
private:
    English english;
    German german;

public:
    void printTranslations(const std::string& language) {
        std::map<std::string, std::string> words = {
            {"кот", ""}, {"дом", ""}, {"солнце", ""}, {"вода", ""}, {"хлеб", ""},
            {"книга", ""}, {"окно", ""}, {"дверь", ""}, {"стол", ""}, {"стул", ""}
        };

        if (language == "English") {
            for (auto& pair : words) pair.second = english.translate(pair.first);
        }
        else if (language == "German") {
            for (auto& pair : words) pair.second = german.translate(pair.first);
        }

        std::cout << "Перевод на " << language << ":\n";
        for (const auto& pair : words) {
            std::cout << pair.first << " -> " << pair.second << std::endl;
        }
    }

    void reverseTranslate(const std::string& language, const std::string& word) {
        std::string result;
        if (language == "English") {
            result = english.reverseTranslate(word);
        }
        else if (language == "German") {
            result = german.reverseTranslate(word);
        }

        std::cout << "Обратный перевод (" << language << "): " << word << " -> " << result << std::endl;
    }
};

int main() {
    system("chcp 1251");
    LanguageFacade facade;

    facade.printTranslations("English");
    facade.reverseTranslate("English", "cat");

    facade.printTranslations("German");
    facade.reverseTranslate("German", "Haus");
    std::cout << "Введите слово на немецком: ";
    std::string a;
    std::cin >> a;
    facade.reverseTranslate("German", a);


    return 0;
}
