//
//  InputLayer.cpp
//  C++ Build
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include "Layer.hpp"


Layer::Layer(unsigned long num_neurons) : m_isOutputLayer(false), m_isInputLayer(true), m_num_neurons(num_neurons), m_num_prev_layer_neurons(0)
{
    m_neurons.reserve(m_num_neurons);
    std::unique_ptr<Neuron> ptr(new Neuron());
    
    for (unsigned long i = 0; i < m_num_neurons; i++)
    {
        ptr.reset(new Neuron());
        m_neurons.push_back(std::move(ptr));
    }
    
    // allocate space for storing ouputed values
    m_outputs.resize(m_num_neurons);
}

Layer::Layer(unsigned long num_neurons, std::shared_ptr<Layer> prev_layer, bool isOutputLayer)
: m_isOutputLayer(isOutputLayer), m_isInputLayer(false), m_prev_layer(prev_layer), m_num_neurons(num_neurons),  m_num_prev_layer_neurons(prev_layer->number_of_neurons())
{
    m_neurons.reserve(m_num_neurons);
    std::unique_ptr<Neuron> ptr(new Neuron(m_num_prev_layer_neurons));

    // allocate space for storing ouputed values
    m_outputs.resize(m_num_neurons);

    if (m_isInputLayer)
    {
        for (unsigned long i = 0; i < m_num_neurons; i++)
        {
            ptr.reset(new Neuron(m_num_prev_layer_neurons));
            m_neurons.push_back(std::move(ptr));
        }
    }
    else // adding bias coefficient
    {
        for (unsigned long i = 0; i < m_num_neurons; i++)
        {
            ptr.reset(new Neuron(m_num_prev_layer_neurons + 1));
            m_neurons.push_back(std::move(ptr));
        }
    }
}

unsigned long Layer::number_of_neurons() const
{
    return m_num_neurons;
}

std::vector<double>& Layer::feed_forward(std::vector<double>& inputs)
{
    if (m_isInputLayer)
    {
        for (unsigned long i = 0; i < m_num_neurons; i++) // for each neuron
        {
            m_neurons.at(i)->set_value(inputs.at(i));
            m_outputs.at(i) = inputs.at(i);
        }
        return m_outputs;
    }
    
    for (unsigned long i = 0; i < m_num_neurons; i++) // for each neuron
    {
        m_outputs[i] = m_neurons.at(i)->fire(inputs);
    }
    return m_outputs;
}

std::vector<double> Layer::feed_backward(std::vector<double> errors, double learning_rate)
{
    std::vector<double> neuron_errors;
    std::vector<double> return_errors;
    neuron_errors.reserve(m_num_neurons);
    return_errors.resize(m_num_prev_layer_neurons);
    
    if (!m_isInputLayer)
    {
        for (unsigned long i = 0; i < m_num_neurons; i++) // for each neuron
        {
            neuron_errors = (m_neurons.at(i)->propogate_error(errors.at(i), this->m_prev_layer->m_outputs, learning_rate));
            for (unsigned long j = 0; j < m_num_prev_layer_neurons; j++)
            {
                return_errors.at(j) += neuron_errors.at(j);
            }
        }
        return return_errors;
    }
    return errors;
}
