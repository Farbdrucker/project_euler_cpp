//
//  problem_3.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//

#include "problem_3.hpp"
#include <cmath>
#include <iostream>
#include <Eigen/Core>

int problem_three()
{
    /*
     The prime factors of 13195 are 5, 7, 13 and 29.
     
     What is the largest prime factor of the number 600851475143 ?
     */
    long target = 600851475143;
    
    long limit = static_cast<long>(sqrt(static_cast<double>(target)));
    
    Eigen::VectorXi primes;
    
    for(int k=2; k<limit; k++)
    {
        if (target % k == 0)
        {
            target = static_cast<long>(target / k);
            primes.resize(primes.size() + 1);
            primes(primes.size() - 1) = k;
        }
    }
    
    return primes.maxCoeff();
}

bool is_prime(long prime_candidate, Eigen::VectorXi &primes)
{
    long limit = static_cast<long>(sqrt(static_cast<double>(prime_candidate)));
    
    long iter = 2;
    while (iter < limit)
    {
        if (prime_candidate % iter == 0)
        {
            return false;
        }
        iter += 1;
    }
    
    return true;
}
