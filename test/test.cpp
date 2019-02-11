//
//  test.cpp
//  NeuralNet
//
//  Created by Peter Somers on 2/11/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include <iostream>
#include "Brain.hpp"

int main()
{
    Brain brain({4,5,6,3});
    
    std::cout << "decision: "<<brain.make_decision({0,.2,23,3}) << "\n";
    
    return 0;
}
