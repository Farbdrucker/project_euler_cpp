//
//  problem_4.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//

#include "problem_4.hpp"
#include "util.hpp"
#include "iostream"
#include <Eigen/Core>

long calc_number_of_digits(int in_number)
{
    long max_number_of_digits =1000000;
    for(long k=0; k < max_number_of_digits; k++)
    {
        if (pow(10, k) > in_number)
        {
            return k;
        }
    }
    return max_number_of_digits;
}

void calc_digits(int in_number, Eigen::VectorXi &digits)
{
    int dec = 10;
    int digit;
    long max_size=calc_number_of_digits(in_number);
    
    digits.resize(max_size);

    digits = Eigen::VectorXi::Zero(max_size);
    int k =0;
    while (in_number > 0)
    {
        digit = in_number % dec;
        digits(k) = digit;
        k++;
//        util::print(digits);
        
        in_number = static_cast<int>(in_number / dec);
    }
}

int reverse_number(int in_number)
{
    int reversed_number = 0;
    int digit, dec;
    
    Eigen::VectorXi digits;
    
    calc_digits(in_number, digits);
    
    for(int k=0; k < digits.size(); k++)
    {
        digit = digits(k);
        dec = pow(10, digits.size() - k - 1);
        if (digit != 0) reversed_number += static_cast<int>(digit * dec);
    }
    return reversed_number;
}

bool is_palindrome(int number)
{
    if (number - reverse_number(number) == 0)
        return true;
    else
        return false;
}

bool is_divided(int in_palin, int number_of_digits, int &left, int &right)
{
    right = static_cast<int>(pow(10, number_of_digits) -1);
    int lower_limit = static_cast<int>(pow(10, number_of_digits-1)-1);
    
    int mul=0;
    int r=0;
    while (right > lower_limit)
    {
        r = in_palin % right;
        if (r == 0)
        {
            left = static_cast<int>(in_palin / right);
            mul = left * right;
            if (left > lower_limit && mul == in_palin && number_of_digits == calc_number_of_digits(left) && number_of_digits == calc_number_of_digits(right))
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
            std::cout << k << std::endl;
            got_solution = is_divided(k, number_of_digits, left, right);
            if (left * right == k)
            {
                std::cout << left << " * " << right << " = " << k << std::endl;
                palindrom = k;
                return true;
            }
        }
    }
    
    return false;
}
