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

void primes_in(long in_number, Eigen::VectorXi &io_primes)
{
    io_primes.resize(0);
    
    long limit = static_cast<long>(sqrt(static_cast<double>(in_number)));
    
    for(int k=2; k<limit; k++)
    {
        if (in_number % k == 0)
        {
            in_number = static_cast<long>(in_number / k);
            io_primes.resize(io_primes.size() + 1);
            io_primes(io_primes.size() - 1) = k;
        }
    }
}

void prime_factors(long in_number, Eigen::VectorXi &in_primes, Eigen::VectorXi &io_factors)
{
    io_factors.resize(in_primes.size());
    int factor = 0;
    for(int k = 0; k < in_primes.size(); k++)
    {
        factor = 0;
        while (in_number % in_primes(k) == 0)
        {
            factor++;
            in_number /= in_primes(k);
        }
        io_factors(k) = factor;
    }
}

int problem_three()
{
    /*
     The prime factors of 13195 are 5, 7, 13 and 29.
     
     What is the largest prime factor of the number 600851475143 ?
     */
    long target = 600851475143;
    Eigen::VectorXi primes, factors;
    primes_in(target, primes);
    prime_factors(target, primes, factors);
    
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
