//
//  problem_2.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//
#define SQRT_5 2.23606797749979f

#include "problem_2.hpp"
#include <cmath>
#include <iostream>


long explicit_fibonacci_sequence(int size)
{
    double d_size = static_cast<double>(size);
    double f_n;
    f_n = (std::pow((1.f + SQRT_5), d_size) - std::pow((1.f - SQRT_5), d_size)) / (std::pow(2.f, d_size) * SQRT_5);
    
    return static_cast<long>(f_n);
}

unsigned long problem_two()
{
    /*
     Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
     
     1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
     
     By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
     */
    unsigned long limit = 4000000;
    
    unsigned long fibonacci_before = 0;
    unsigned long fibonacci = 1;
    
    unsigned long sum = 0;
    
    while (fibonacci < limit)
    {
        if (fibonacci % 2 == 0)
        {
            sum += fibonacci;
        }
        
        fibonacci += fibonacci_before;
        fibonacci_before = fibonacci;
    }
    
    return sum;
}
