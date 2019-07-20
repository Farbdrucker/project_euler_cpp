//
//  problem_1.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//
#include <Eigen/Core>
#include "problem_1.hpp"
#include <iostream>

//////////////////////////////////////////////
// sums up every integer that can be divided by a list of factors that is below a given size
int find_the_sum_of_all_the_multiples_of_factors(unsigned int size, Eigen::VectorXi factors)
{
    long number_of_factors = factors.size();
    unsigned int sum = 0;
    for(int i=0; i < size; i++)
    {
        for(int j=0; j < number_of_factors; j++)
        {
            if (i % factors[j] == 0)
            {
                sum += i;
            }
        }
    }
    return sum;
}


int problem_one()
{
    /*
     If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
     
     Find the sum of all the multiples of 3 or 5 below 1000.
     */
    Eigen::VectorXi factors(2);
    factors << 3, 5;
    
    unsigned int number_below = 1000;
    
    return find_the_sum_of_all_the_multiples_of_factors(number_below, factors);
}

