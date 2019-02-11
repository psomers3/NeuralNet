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

Neuron::Neuron(unsigned long num_neurons_this_layer, unsigned long num_next_layer_neurons)
{
    double He_factor = std::sqrt(2./num_neurons_this_layer);
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    
    std::normal_distribution<double> distribution (0.0,1.0);
    
    m_coefficients.reserve(num_next_layer_neurons);
    
    for (unsigned long i = 0; i < num_next_layer_neurons; i++)
    {
        m_coefficients.push_back(distribution(generator) * He_factor);
    }
}

std::vector<double> Neuron::fire(double input)
{
    std::vector<double> values_to_return(m_coefficients.size());
    for (unsigned long i = 0; i < m_coefficients.size(); i++)
    {
        values_to_return.at(i) = m_coefficients.at(i) * input;
    }
    return values_to_return;
}
