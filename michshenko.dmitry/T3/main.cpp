#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <iterator>

#include <fstream>
#include <sstream>

#include "algoritms.hpp"
#include "service.hpp"
#include "Polygon.hpp"
#include "Streamguard.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR: incorrect input"<<std::endl;
        return -1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "ERROR: cannot open file"<<std::endl;
        return -1;
    }

    std::vector<Polygon> polygonsList;

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

    std::string command;
    StreamGuard guard(std::cout);
    std::cout << std::fixed << std::setprecision(1);

    while (std::cin >> command) {
        std::cin.clear();
        std::string value;

        if (command == "AREA") {
            std::cin >> value;

            if ((value == "ODD") || (value == "EVEN")) {
                std::cout << areaEvenOdd(value, polygonsList) << std::endl;
            }
            else if (value == "MEAN") {
                if (isEmpty(polygonsList)) {
                    invalComm();
                    continue;
                }
                std::cout << areaMean(polygonsList) << std::endl;
            }
            else {
                if (std::stoi(value) >= 3) {
                    std::cout << areaNum(std::stoi(value), polygonsList) << std::endl;
                }
                else {
                    invalComm();
                }
            }
        }
        //
        else if ((command == "MAX") || (command == "MIN")) {

            if (isEmpty(polygonsList)) {
                invalComm();
                continue;
            }

            std::string value;
            std::cin >> value;

            if ((command == "MAX") && (value == "AREA")) {
                std::cout << maxAreaVertex(value, polygonsList) << std::endl;
            }

            else if ((command == "MAX") && (value == "VERTEXES")) {
                std::cout << static_cast<int>(maxAreaVertex(value, polygonsList)) << std::endl;
            }

            else if ((command == "MIN") && (value == "AREA")) {
                std::cout << minAreaVertex(value, polygonsList) << std::endl;
            }

            else if ((command == "MIN") && (value == "VERTEXES")) {
                std::cout << static_cast<int>(minAreaVertex(value, polygonsList)) << std::endl;
            }

            else {
                invalComm();
            }
        }
        //
        else if (command == "COUNT") {

            std::string value;
            std::cin >> value;

            if ((value == "EVEN") || (value == "ODD")) {
                std::cout << countVertexOddNum(value, polygonsList) << std::endl;
            }
            else {
                if (std::stoi(value) >= 3) {
                    std::cout << countVertexOddNum(std::stoi(value), polygonsList) << std::endl;
                }
                else {
                    invalComm();
                }
            }
        }
        //
        else if (command == "INFRAME") {
            Polygon poly;
            std::string line;

            std::getline(std::cin >> std::ws, line);
            std::istringstream iss(line);

            if (!(iss >> poly)) {
                std::cout << "<INVALID COMMAND>\n";
                std::cin.clear();
            }
            else {
                bool result = isInframe(poly, polygonsList);
                std::cout << (result ? "TRUE" : "FALSE") << std::endl;
            }
        }
        //
        else if (command == "MAXSEQ") {
            Polygon target;
            std::string line;

            std::getline(std::cin >> std::ws, line);
            std::istringstream iss(line);

            if (!(iss >> target)) {
                std::cout << "<INVALID COMMAND>\n";
                std::cin.clear();
            }
            else {
                int result = maxSeq(polygonsList, target);
                std::cout << result << std::endl;
            }
        }
        //
        else {
            invalComm();
        }
    }
}
