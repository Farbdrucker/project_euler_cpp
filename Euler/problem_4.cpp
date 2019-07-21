//
//  problem_4.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//

#include "problem_4.hpp"
#include "util.hpp"

#include <iostream>

bool is_palindrome(int number)
{
    if (number - util::reverse_number(number) == 0)
        return true;
    else
        return false;
}

bool is_divided(int in_palin, int in_number_digits, int &left, int &right)
{
    right = static_cast<int>(pow(10, in_number_digits) -1);
    int lower_limit = static_cast<int>(pow(10, in_number_digits-1)-1);
    
    int mul=0;
    int r=0;
    while (right > lower_limit)
    {
        r = in_palin % right;
        if (r == 0)
        {
            left = static_cast<int>(in_palin / right);
            mul = left * right;
            if (left > lower_limit && mul == in_palin
                && in_number_digits == util::calc_number_of_digits(left)
                && in_number_digits == util::calc_number_of_digits(right))
            {
                return true;
            }
        }
        right--;
    }
    
    return false;
}

bool problem_four(int number_of_digits, int &palindrom, int &left, int &right)
{
    bool got_solution = false;
    int upper_limit, lower_limit;
    upper_limit = static_cast<int>(pow(pow(10, number_of_digits)-1,2));
    lower_limit = static_cast<int>(pow(pow(10, number_of_digits-1)-1,2));
    
    for(int k=upper_limit; k> lower_limit; k--)
    {
        if (is_palindrome(k))
        {
            got_solution = is_divided(k, number_of_digits, left, right);
            if (left * right == k)
            {
                palindrom = k;
                return true;
            }
        }
    }
    
    return false;
}
