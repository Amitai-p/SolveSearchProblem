//
// Created by amitai on 12/01/2020.
//


#include "MatrixBuilder.h"
#include "Point.h"

MyMatrixSearchable *MatrixBuilder::createMatrix(vector<vector<double> > detailsOnMatrix, string matrixToString) {
    vector<double> detailsGoalPoint = detailsOnMatrix.back();
    detailsOnMatrix.pop_back();
    Point* goal = new Point((int) detailsGoalPoint[0], (int) detailsGoalPoint[1]);
    vector<double> detailsStartPoint = detailsOnMatrix.back();
    detailsOnMatrix.pop_back();
    Point* start = new Point((int) detailsStartPoint[0],  (int) detailsStartPoint[1]);
    State<Point>* goalState = new State<Point>(goal, detailsOnMatrix[goal->getX()][goal->getY()], nullptr, NOT);
    State<Point>* startState = new State<Point>(start, detailsOnMatrix[start->getX()][start->getY()], nullptr, NOT);
    vector<vector<State<Point>*>> matrix;
    unsigned int i = 0;
    for (; i < detailsOnMatrix.size(); ++i) {
        vector<State<Point>*> cellInMatrix;
        unsigned int j = 0;
        for (; j < detailsOnMatrix[i].size(); ++j) {
            Point* point = new Point(i, j);
            cellInMatrix.push_back(new State<Point>(point, detailsOnMatrix[i][j], nullptr, NOT));
        }
        matrix.push_back(cellInMatrix);
    }
    MyMatrixSearchable* myMatrixSearchable = new MyMatrixSearchable(matrix, startState, goalState, matrixToString);
    return myMatrixSearchable;
}
