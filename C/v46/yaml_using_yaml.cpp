#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <unordered_map>

/*
Not implemented yet
*/

class YamlParser {
    private:
        FILE* file;
        std::unordered_map<std::string, std::vector<std::string>> data;

        void parseFile() {
        char buffer[1024];
        std::string key;
        while (std::fgets(buffer, sizeof(buffer), file)) {
            std::string line(buffer);
            size_t delimiter = line.find(':');
            if (delimiter != std::string::npos) {
                key = line.substr(0, delimiter);
                std::string value = line.substr(delimiter + 1);
                key.erase(0, key.find_first_not_of(" \t\n\r"));
                key.erase(key.find_last_not_of(" \t\n\r") + 1);
                value.erase(0, value.find_first_not_of(" \t\n\r"));
                value.erase(value.find_last_not_of(" \t\n\r") + 1);

                if (value.empty()) {
                    while (std::fgets(buffer, sizeof(buffer), file)) {
                        std::string nextLine(buffer);
                        size_t nextDelimiter = nextLine.find(':');
                        if (nextDelimiter != std::string::npos) {
                            fseek(file, -static_cast<long>(nextLine.length()), SEEK_CUR);
                            break;
                        }
                        nextLine.erase(0, nextLine.find_first_not_of(" \t\n\r-"));
                        nextLine.erase(nextLine.find_last_not_of(" \t\n\r") + 1);
                        if (!nextLine.empty()) {
                            data[key].push_back(nextLine);
                        }
                    }
                } else {
                    data[key].push_back(value);
                }
            }
        }
    }

    public:
        YamlParser(const std::string& filename) {
            file = std::fopen(filename.c_str(), "r");
            if (!file) {
                throw std::runtime_error("Failed to open file");
            }
            parseFile();
        }

        std::string getString(const std::string& key) {
            return data[key][0];
        }

        int getInt(const std::string& key) {
            return std::stoi(data[key][0]);
        }

        std::vector<std::string> getStringList(const std::string& key) {
            return data[key];
        }
        
        virtual ~YamlParser() {
            if (file) {
                std::fclose(file);
            }            
        }
};

int main() {
    YamlParser parser("C:\\Users\\cassa\\Documents\\Projects\\IOT\\IoT-embedded\\C\\v46\\example.yaml");

    std::string name = parser.getString("name");
    int age = parser.getInt("age");
    std::vector<std::string> items = parser.getStringList("items");

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age " << age << std::endl;
    std::cout << "Items: " << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item << std::endl;
    }
    
    return 0;
}