#ifndef REVISEDSIMPLEX_H
#define REVISEDSIMPLEX_H

#include "Eigen/Dense"
#include <vector>

class RevisedSimplex
{
  public:
    Eigen::MatrixXd A, B;
    Eigen::VectorXd x, d, c, b;
    
    std::vector<int> basic_variables, non_basic_variables;

    int FindSmallestReducedCost();


};

#endif