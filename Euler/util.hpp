//
//  util.hpp
//  Euler
//
//  Created by Lukas Sanner on 21.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//

#ifndef util_hpp
#define util_hpp
#include <Eigen/Core>
#include <iostream>

#include <stdio.h>

namespace util
{
    template<typename derived>
    void append(Eigen::Matrix<derived, Eigen::Dynamic, 1> &vector, derived &value)
    {
        vector.resize(vector.size() + 1);
        vector(vector.size() - 1) = value;
    };


    template<typename derived>
    void print(Eigen::Matrix<derived, Eigen::Dynamic, 1> a)
    {
        std::cout << "[ ";
        for(int k=0; k < a.size(); k++)
        {
            std::cout << a(k) << " ";
        }
        std::cout << " ]" << std::endl;
    }
}
#endif /* util */
