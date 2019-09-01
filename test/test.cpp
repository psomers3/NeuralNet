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
    Brain brain({2,4,3,2});
    std::cout << "Done.\n";
    std::vector<double> output(2);
    std::vector<double> error(2);
    std::vector<std::vector<double>> correct_output;
    std::vector<std::vector<double>> training_values;
    std::vector<std::vector<double>> test_values = {{0,0},{0,1},{1,0},{1,1}};
    int num_samples;
    
    
    std::cout << "\nInput how many training samples should be used: ";
    std::cin >> num_samples;
    std::cout << "Generating training samples..." << std::flush;
    correct_output.reserve(num_samples);
    training_values.reserve(num_samples);
    for (int i = 0; i < num_samples; i++)
    {
        training_values.push_back({fmod(rand(), 2), fmod(rand(), 2)});
        if ((training_values.at(i).at(0) == 0) && (training_values.at(i).at(1) == 0))
            correct_output.push_back({1, 0});
        if ((training_values.at(i).at(0) == 0) && (training_values.at(i).at(1) == 1))
            correct_output.push_back({0, 1});
        if ((training_values.at(i).at(0) == 1) && (training_values.at(i).at(1) == 0))
            correct_output.push_back({0, 1});
        if ((training_values.at(i).at(0) == 1) && (training_values.at(i).at(1) == 1))
            correct_output.push_back({1, 0});
    }
    std::cout << "\n\nTraining the brain to be an XOR gate with "<< std::to_string(num_samples) <<" random samples...\n";

    for (int i = 0; i < num_samples; i++)
    {
        output = brain.get_output(training_values.at(i));
        for (unsigned long j = 0; j < output.size(); j++)
        {
            error.at(j) = (correct_output.at(i).at(j) - output.at(j));
        }
        
        brain.back_propagate(error);
    }
    
    std::cout << "Training Complete. Testing samples...\n";
    std::cout << "input values    decision        Actual\n";
    output = brain.get_output(test_values.at(0));
    std::cout << "0      0          " << brain.make_decision(test_values.at(0))
    << "          {" << std::to_string(output.at(0)) << ", " << std::to_string(output.at(1)) << "}\n";
    output = brain.get_output(test_values.at(1));
    std::cout << "0      1          " << brain.make_decision(test_values.at(1))
    << "          {" << std::to_string(output.at(0)) << ", " << std::to_string(output.at(1)) << "}\n";
    output = brain.get_output(test_values.at(2));
    std::cout << "1      0          " << brain.make_decision(test_values.at(2))
    << "          {" << std::to_string(output.at(0)) << ", " << std::to_string(output.at(1)) << "}\n";
    output = brain.get_output(test_values.at(3));
    std::cout << "1      1          " << brain.make_decision(test_values.at(3))
    << "          {" << std::to_string(output.at(0)) << ", " << std::to_string(output.at(1)) << "}\n";

    return 0;
}
