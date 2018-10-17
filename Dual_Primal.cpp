//
// Created by ankilp on 10/15/18.
//

#include "Dual_Primal.h"

Dual_Primal::Dual_Primal() {
    std::cin >> x;
    std::cin >> y;
    boost::numeric::ublas::matrix<double> A (x,y);
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < y; ++j){
            std::cin >> A(i, j);
        }
    }
}

