//
// Created by ankilp on 10/15/18.
//

#include <string>
#include <iostream>
#include <vector>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector.hpp>

#ifndef SIMPLEX_SIMPLEX_H
#define SIMPLEX_SIMPLEX_H

//TODO: account for degenerate and mulitple optimal solutions cases

class Simplex
{
protected:
    int maxmin;
    int x;
    int y;
    boost::numeric::ublas::matrix<double> A;
    boost::numeric::ublas::vector<double> c; // weights for objective function
    boost::numeric::ublas::vector<double> b; //

    boost::numeric::ublas::vector<int> nonnegativity;

    std::vector<int> list_of_basic_vars;

public:
    Simplex();
    void initial_sanitize_step();
    void iterate();
    void canonical_form();
    void big_m();
    void two_phase();

    //helper functions
    template<typename T>
    void assign(boost::numeric::ublas::matrix<T> &m, std::size_t r, std::size_t c);

    template<typename T>
    void assign(boost::numeric::ublas::vector<T> &v, std::size_t r);
};






#endif //SIMPLEX_SIMPLEX_H
