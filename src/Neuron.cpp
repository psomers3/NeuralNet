//
//  Neuron.cpp
//  C++ Build
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include <random>
#include <chrono>
#include <cmath>
#include "Neuron.hpp"

Neuron::Neuron()
{
    m_coefficients.push_back(1);
}

Neuron::Neuron(unsigned long num_prev_layer_neurons)
{
    double He_factor = std::sqrt(2./num_prev_layer_neurons);
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    
    std::normal_distribution<double> distribution (0.0,1.0);
    
    m_coefficients.reserve(num_prev_layer_neurons);
    
    for (unsigned long i = 0; i < num_prev_layer_neurons; i++)
    {
        m_coefficients.push_back(distribution(generator) * He_factor);
    }
}

double Neuron::fire(std::vector<double> input)
{
    double value_to_return = 0;
    unsigned long num_inputs = input.size();
    unsigned long num_coeff = m_coefficients.size();
    
    for (unsigned long i = 0; i < num_inputs; i++)
    {
        value_to_return += m_coefficients.at(i) * input.at(i);
    }
    if (num_inputs < num_coeff)
        value_to_return += m_coefficients.at(num_coeff - 1); // bias term "*1"
    
    return value_to_return;
}

double Neuron::fire(int input)
{
    double value_to_return = 0;
    
    for (unsigned long i = 0; i < m_coefficients.size(); i++)
    {
        value_to_return += m_coefficients.at(i) * input;
    }
    return value_to_return;
}
