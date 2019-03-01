//
//  test.cpp
//  NeuralNet
//
//  Created by Peter Somers on 2/11/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include <iostream>
#include "Brain.hpp"
#include <math.h>

int main()
{
    std::cout << "Creating a brain with 2 inputs and 2 outputs and 2 hidden layers.\n";
    std::cout << "The first hidden layer has 4 neurons and the 2nd has 3... ";
    Brain brain({2,4,1});
    std::cout << "Done.\n";
    std::vector<double> output(1);
    std::vector<double> error(1);
    std::vector<double> training_values = {0,0};
    std::vector<double> correct_output = {0};
    
    std::cout << "Training the brain to be an XOR gate with 500 random samples...\n";
    
    for (unsigned long i = 0; i < 2500; i++)
    {
        training_values = {fmod(rand(), 2), fmod(rand(), 2)};
        output = brain.get_output(training_values);
        
        if ((training_values.at(0) == 0) && (training_values.at(1) == 0))
            correct_output = {0};
        if ((training_values.at(0) == 0) && (training_values.at(1) == 1))
            correct_output = {1};
        if ((training_values.at(0) == 1) && (training_values.at(1) == 0))
            correct_output = {1};
        if ((training_values.at(0) == 1) && (training_values.at(1) == 1))
            correct_output = {0};
        
        for (int j = 0; j < 1; j++)
        {
            error.at(j) = correct_output.at(j) - output.at(j);
        }
        brain.back_propagate(error);
    }
    
    std::cout << "Training Complete. Testing samples...\n";
    std::cout << "input values      Output\n";
    training_values = {0, 0};
    std::cout << "0      0          " << brain.get_output(training_values)[0] << "\n";
    training_values = {0, 1};
    std::cout << "0      1          " << brain.get_output(training_values)[0] << "\n";
    training_values = {1, 0};
    std::cout << "1      0          " << brain.get_output(training_values)[0] << "\n";
    training_values = {1, 1};
    std::cout << "1      1          " << brain.get_output(training_values)[0] << "\n";

    return 0;
}
