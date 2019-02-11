//
//  InputLayer.cpp
//  C++ Build
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include "Layer.hpp"


Layer::Layer(unsigned long num_neurons) : m_isOutputLayer(false), m_isInputLayer(true), m_num_neurons(num_neurons)
{
    m_neurons.reserve(m_num_neurons); // +1 for bias
    for (unsigned long i = 0; i < m_num_neurons; i++)
    {
        m_neurons.push_back(Neuron());
    }
}

Layer::Layer(unsigned long num_neurons, Layer& prev_layer, bool isOutputLayer)
    : m_isOutputLayer(isOutputLayer), m_isInputLayer(false), m_num_neurons(num_neurons), m_num_prev_layer_neurons(prev_layer.number_of_neurons())
{
    if (m_isOutputLayer)
    {
        m_neurons.reserve(m_num_neurons);
    }
    else // add bias neuron
    {
        m_neurons.reserve(m_num_neurons + 1);
        m_neurons.push_back(Neuron(m_num_prev_layer_neurons));
    }
    
    for (unsigned long i = 0; i < m_num_neurons; i++)
    {
        m_neurons.push_back(Neuron(m_num_prev_layer_neurons));
    }
}

unsigned long Layer::number_of_neurons() const
{
    return m_num_neurons;
}

std::vector<double> Layer::feed_forward(std::vector<double> inputs)
{
    std::vector<double> neuron_values;
    if (m_isInputLayer)
    {
        neuron_values.resize(m_num_neurons);
        return inputs;
    }
    else
        neuron_values.resize(m_num_neurons);
    
    for (unsigned long i = 0; i < m_num_neurons; i++) // for each neuron
    {
        neuron_values[i] = m_neurons.at(i).fire(inputs);
        
        // apply sigmoid function
        neuron_values.at(i) = 1 / (1 + exp(-neuron_values.at(i)));
    }
    return neuron_values;
}
