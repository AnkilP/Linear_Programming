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


}

void Simplex::iterate() {

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