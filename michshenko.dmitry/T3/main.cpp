#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cctype>

#include "algoritms.hpp"
#include "service.hpp"
#include "Polygon.hpp"
#include "Streamguard.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR: incorrect input" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "ERROR: cannot open file" << std::endl;
        return 1;
    }

    std::vector<Polygon> polygonsList;

    // Чтение фигур из файла
    while (!input.eof()) {
        std::copy(
            std::istream_iterator<Polygon>(input),
            std::istream_iterator<Polygon>(),
            std::back_inserter(polygonsList)
        );
        if (input.fail() && !input.eof()) {
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }


    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string command;
    StreamGuard guard(std::cout);
    std::cout << std::fixed << std::setprecision(1);

    while (std::cin >> command) {
        if (command == "AREA") {
            std::string value;
            std::cin >> value;

            if (value == "ODD" || value == "EVEN") {
                std::cout << areaEvenOdd(value, polygonsList) << std::endl;
            }
            else if (value == "MEAN") {
                if (polygonsList.empty()) {
                    invalComm();
                    continue;
                }
                std::cout << areaMean(polygonsList) << std::endl;
            }
            else {
                bool isNumber = true;
                for (char c : value) {
                    if (!std::isdigit(c)) { isNumber = false; break; }
                }
                if (isNumber) {
                    int num = std::stoi(value);
                    if (num >= 3) {
                        std::cout << areaNum(num, polygonsList) << std::endl;
                    } else {
                        invalComm();
                    }
                } else {
                    invalComm();
                }
            }
        }
        else if (command == "MAX" || command == "MIN") {
            if (polygonsList.empty()) {
                invalComm();
                continue;
            }
            std::string value;
            std::cin >> value;

            if ((command == "MAX" && value == "AREA") ||
                (command == "MAX" && value == "VERTEXES")) {
                double res = maxAreaVertex(value, polygonsList);
                if (value == "VERTEXES")
                    std::cout << static_cast<int>(res) << std::endl;
                else
                    std::cout << res << std::endl;
            }
            else if ((command == "MIN" && value == "AREA") ||
                     (command == "MIN" && value == "VERTEXES")) {
                double res = minAreaVertex(value, polygonsList);
                if (value == "VERTEXES")
                    std::cout << static_cast<int>(res) << std::endl;
                else
                    std::cout << res << std::endl;
            }
            else {
                invalComm();
            }
        }
        else if (command == "COUNT") {
            std::string value;
            std::cin >> value;

            if (value == "EVEN" || value == "ODD") {
                std::cout << countVertexOddNum(value, polygonsList) << std::endl;
            }
            else {
                bool isNumber = true;
                for (char c : value) {
                    if (!std::isdigit(c)) { isNumber = false; break; }
                }
                if (isNumber) {
                    int num = std::stoi(value);
                    if (num >= 3) {
                        std::cout << countVertexOddNum(static_cast<size_t>(num), polygonsList) << std::endl;
                    } else {
                        invalComm();
                    }
                } else {
                    invalComm();
                }
            }
        }
        else if (command == "INFRAME") {
            Polygon poly;
            std::string line;
            std::cin.clear();
            if (!std::getline(std::cin >> std::ws, line)) {
                invalComm();
                continue;
            }
            std::istringstream iss(line);
            if (!(iss >> poly)) {
                invalComm();
            } else {
                bool result = isInframe(poly, polygonsList);
                std::cout << (result ? "TRUE" : "FALSE") << std::endl;
            }
        }
        else if (command == "MAXSEQ") {
            Polygon target;
            std::string line;
            std::cin.clear();
            if (!std::getline(std::cin >> std::ws, line)) {
                invalComm();
                continue;
            }
            std::istringstream iss(line);
            if (!(iss >> target)) {
                invalComm();
            } else {
                int result = maxSeq(polygonsList, target);
                std::cout << result << std::endl;
            }
        }
        else {
            invalComm();
        }
    }
    return 0;
}
