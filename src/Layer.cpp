//
//  InputLayer.cpp
//  C++ Build
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include "Layer.hpp"


Layer::Layer(unsigned long num_neurons) : m_num_neurons(num_neurons)
{
    m_isOutputLayer = true;
    m_neurons.reserve(m_num_neurons);
    for (unsigned long i = 0; i < m_num_neurons; i++)
    {
        m_neurons.push_back(Neuron());
    }
}


Layer::Layer(unsigned long num_neurons, Layer& next_layer)
    : m_num_neurons(num_neurons), m_num_next_layer_neurons(next_layer.number_of_neurons())
{
    m_isOutputLayer = false;
    m_neurons.reserve(m_num_neurons);
    for (unsigned long i = 0; i <= m_num_neurons; i++) // "<=" to add a bias neuron
    {
        m_neurons.push_back(Neuron(m_num_neurons, m_num_next_layer_neurons));
    }
}

unsigned long Layer::number_of_neurons() const
{
    return m_num_neurons;
}

std::vector<double> Layer::feed_forward(std::vector<double> inputs)
{
    std::vector<double> values_to_forward;
    if (m_isOutputLayer)
    {
        values_to_forward.resize(m_num_neurons);
        return inputs;
    }
    else
        values_to_forward.resize(m_num_next_layer_neurons);
    
    std::vector<double> current_neuron_values;
    
    for (unsigned long i = 0; i < inputs.size(); i++) // for each input
    {
        current_neuron_values = m_neurons.at(i).fire(inputs.at(i));
        for (unsigned long j = 0; j < current_neuron_values.size(); j ++)
        {
            values_to_forward.at(j) += current_neuron_values.at(j);
        }
    }
    
    // add bias neuron value
    current_neuron_values = m_neurons.at(m_num_neurons).fire(1);
    for (unsigned long j = 0; j < current_neuron_values.size(); j ++)
    {
        values_to_forward.at(j) += current_neuron_values.at(j);
    }
    
    return values_to_forward;
}
