#include <iostream>

#include "Simplex.h"

int main()
{
    /*https://jaredantrobus.com/squirrel/2015/Summer/MA162/4.1.php*/
    /*http://simplex.tode.cz/en/#steps*/

    Simplex a;
    double M = 10000;
    //a.tableau = {{1, 2, 3, 4, 0, 0, 0}, {0, 3, 2, 1, 1, 0, 10}, {0, 2, 5, 3, 0, 1, 15}};
    a.tableau = {{1,-3,-5,0,0,M,M,0}, {0,1,1,-1,0,1,0,2}, {0,0,1,0,1,0,0,6}, {0,3,2,0,0,0,1,18}};
    a.basic_variables = {4,3,5};
std::cout << a.ToString();
    a.Solve();
    std::cout << a.objective_value << "\n";
    std::cout << a.ToString();
}