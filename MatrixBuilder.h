//
// Created by amitai on 12/01/2020.
//

#ifndef UNTITLED2_MATRIXBUILDER_H
#define UNTITLED2_MATRIXBUILDER_H

#define DELIMITER ','

#include "MyMatrixSearchable.h"
#include "State.h"
class MatrixBuilder {
public:
    static MyMatrixSearchable createMatrix(string input);

private:
    static string extractLastLine(vector<string> &input);

    static vector<int> parseRow(const string &line);

    static pair<int, int> parseCoordinates(const string &data);

    static vector<string> splitInput(const string &input);
};
#endif //UNTITLED2_MATRIXBUILDER_H