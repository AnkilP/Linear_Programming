//
// Created by ankilp on 10/15/18.
//

#include <string>
#include <iostream>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector.hpp>

#ifndef SIMPLEX_SIMPLEX_H
#define SIMPLEX_SIMPLEX_H

class Simplex
{
protected:
    std::string maxmin;
    int x;
    int y;
    boost::numeric::ublas::vector<double>

public:
    Simplex();

    void initial_sanitize_step();
    void iterate();
    void canonical_form();
    void big_m();
    void two_phase();
};






#endif //SIMPLEX_SIMPLEX_H
