//
//  main.cpp
//  Euler
//
//  Created by Lukas Sanner on 20.07.19.
//  Copyright © 2019 Lukas Sanner. All rights reserved.
//
#include <boost/program_options.hpp>
#include <iostream>

#include "problem_1.hpp"
#include "problem_2.hpp"
#include "problem_3.hpp"

int main(int argc, const char * argv[]) {
    
    int problem_id;
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("problem-id", boost::program_options::value(&problem_id)->default_value(3), "project euler problem id");
    
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);
    
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 0;
    }
    
    if (vm.count("problem-id"))
    {
        std::cout << "Project Euler Problem id "
        << problem_id << ".\n";
        
        if (problem_id == 1)
        {
            std::cout << "Solution of problem one is "
            << problem_one() << std::endl;
        }
        else if (problem_id == 2)
        {
            std::cout << "Solution of problem two is "
            << problem_two() << std::endl;
        }
        else if (problem_id == 3)
        {
            std :: cout << "Solution of problem three is "
            << problem_three() << std::endl;
        }
        else
        {
            std::cout << "NOT IMPLEMENTED for problem id " << problem_id;
        }
    } else {
        std::cout << "Project Euler Problem Id was not set.\n";
    }
    
    
    return 0;
}
