//
//  problem_3.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//

#include "problem_3.hpp"
#include "util.hpp"

#include <cmath>
#include <iostream>


int problem_three()
{
    /*
     The prime factors of 13195 are 5, 7, 13 and 29.
     
     What is the largest prime factor of the number 600851475143 ?
     */
    long target = 600851475143;
    
    Eigen::VectorXi primes, factors;
    util::primes_in(target, primes);
    util::prime_factors(target, primes, factors);
    
    return primes.maxCoeff();
}


