#include <iostream>
#include <sstream>
#include <cctype>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Polygon.h"
#include "Reader.h"
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "ERROR: Filename not provided" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "ERROR: Failed to open file" << std::endl;
        return 1;
    }

    std::vector<Polygon> polygons;
    polygonReader(inFile, polygons);
    inFile.close();
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream cmdStream(line);
        std::string cmd;
        cmdStream >> cmd;

        try {
            if (cmd == "RMECHO") {
                Polygon target;
                if (!(cmdStream >> target)) {
                    std::cout << "<INVALID COMMAND>" << std::endl;
                }
                size_t removed = rmecho(polygons, target);
                std::cout << removed << std::endl;
            }
            else if (cmd == "SAME") {
                Polygon target;
                if (!(cmdStream >> target)) {
                    std::cout << "<INVALID COMMAND>" << std::endl;
                }
                size_t count = same(polygons, target);
                std::cout << count << std::endl;
            }
            else {
                std::cout << "<INVALID COMMAND>" << std::endl;
            }
        }
        catch (const std::exception&) {
            std::cout << "<INVALID COMMAND>" << std::endl;
        }
    }
    return 0;
}
