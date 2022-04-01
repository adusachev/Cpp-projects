#include <iostream>
#include <sstream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <limits>

using namespace std;

#include "matrix_class.h"
#include "matrix_operations.h"
#include "tests.h"

#include "SOLE_methods.h"
#include "tests_SOLE.h"




int main() {

    /// Basic tests
    Test_Sum();
    Test_Matrix_Num_Mult();
    Test_Matrix_Mult();
    Test_Transpose();
    cout << endl;

    /// SOLE tests
    tests_TDMA(true);
    tests_Gauss_Seidel(true);


    return 0;
}
