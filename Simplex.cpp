//
// Created by ankilp on 10/15/18.
//

#include "Simplex.h"

Simplex::Simplex() {
    std::cout << "Enter 1 for max and -1 for min" << std::endl;
    std::cin >> maxmin;
    std::cout << maxmin;

    std::cout << "Enter the number of constraints" << std::endl;
    std::cin >> x;
    std::cout << "Enter the number of variables" << std::endl;
    std::cin >> y;

    Simplex::assign(A, x, y);

    std::cout << "Enter the weights for the constraints" << std::endl;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            std::cin >> A(i, j);
        }
    }

    Simplex::assign(b, x);

    for(int i = 0; i < x; ++i){
        std::cin >> b(i);
    }

    Simplex::assign(c, y);

    for (int j = 0; j < y; ++j) {
        std::cin >> c(j);
    }

    Simplex::assign(nonnegativity, x);
    //0 is for unbounded, 1 for greater than, -1 for less than
    for (int i = 0; i < x; ++i) {
        std::cin >> nonnegativity(i);
    }

    list_of_basic_vars.reserve(y);

}

void Simplex::initial_sanitize_step() {
    //to make everything max
    b *= maxmin;
    for (int i = 0; i < x; ++i) {
        if (nonnegativity(i) == 0) {
            Simplex::assign(nonnegativity, x + 1);
            nonnegativity(i) = 1;
            //creating negative version
            nonnegativity(x) = 1;

        }
    }

    //in the initial sanitization step, determine which basic vars need to be in the list of basic vars vector

}

void Simplex::canonical_form() {
    return;
}

void Simplex::iterate() {
    //determine ratios for which variable will be leaving and which will be entering
    double smallest_ratio = 100; //TODO: change later so we don't rely on the ratio never being higher than 100
    for (auto index_of_decision_var : list_of_basic_vars) {
        if (c[index_of_decision_var] < 0) {
            double previous_ratio;
            for (int i = 0; i < x; ++i) {
                previous_ratio = smallest_ratio;
                if (A(i, index_of_decision_var) > 0) {
                    smallest_ratio = std::min(smallest_ratio, b[i] / A(i, index_of_decision_var));
                }

            }
        }
    }

}

void Simplex::big_m() {

}

void Simplex::two_phase() {

}

template<typename T>
void Simplex::assign(boost::numeric::ublas::matrix<T> &m, std::size_t r, std::size_t c) {
    m.resize(r, c);
}

template<typename T>
void Simplex::assign(boost::numeric::ublas::vector<T> &v, std::size_t r) {
    v.resize(r);
}