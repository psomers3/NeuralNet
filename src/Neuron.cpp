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

Neuron::Neuron(): m_coefficients(new VectorDbl())
{
    m_coefficients->push_back(1);
}

Neuron::Neuron(unsigned long num_prev_layer_neurons): m_coefficients(new VectorDbl())
{
    double He_factor = std::sqrt(2./num_prev_layer_neurons);
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    
    std::normal_distribution<double> distribution (0.0,1.0);
    
    m_coefficients->reserve(num_prev_layer_neurons);
    
    for (unsigned long i = 0; i < num_prev_layer_neurons; i++)
    {
        m_coefficients->push_back(distribution(generator) * He_factor);
    }
}

double Neuron::fire(VectorDbl input)
{
    m_value = 0;
    unsigned long num_inputs = input.size();
    unsigned long num_coeff = m_coefficients->size();
    
    for (unsigned long i = 0; i < num_inputs; i++)
    {
        m_value += m_coefficients->at(i) * input.at(i);
    }
    if (num_inputs < num_coeff)
        m_value += m_coefficients->at(num_coeff - 1); // bias term "*1"
    
    return m_value;
}

void Neuron::set_value(double input_value)
{
    m_value = input_value;
}

double Neuron::calculate_derivative()
{
    m_derivative = m_value * (1 - m_value);
    return m_derivative;
}

double Neuron::calculate_delta(double error)
{
    m_delta = error * calculate_derivative();
    return m_delta;
}

VectorDbl Neuron::propogate_error(double error, VectorDbl inputs_from_prev_layer, const double learning_rate)
{
    std::vector<double> return_error(m_coefficients->size()-1);
    
    this->calculate_delta(error);
    
    for (unsigned long i = 0; i < m_coefficients->size() - 1; i++)
    {
        // find contribution to error
        return_error.at(i) = m_delta * m_coefficients->at(i);
        // upate coefficient
        m_coefficients->at(i) += learning_rate * m_delta * inputs_from_prev_layer.at(i);
    }
    m_coefficients->at(m_coefficients->size()-1) += learning_rate * m_delta; // bias coefficient update
    
    return return_error;
}
