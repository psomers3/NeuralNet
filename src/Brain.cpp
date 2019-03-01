//
//  Brain.cpp
//  aUSsie
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#include <algorithm> // std::reverse
#include "Brain.hpp"


Brain::Brain(std::vector<unsigned long> layers) : m_num_layers(layers.size())
{
    m_layers.reserve(m_num_layers);
    // add input layer
    std::shared_ptr<Layer> ptr(new Layer(layers.at(0)));
    
    m_layers.push_back(ptr);
    for (unsigned long i = 1; i < m_num_layers; i++)
    {
        if (i == m_num_layers - 1)
            m_layers.push_back(std::shared_ptr<Layer>(new Layer(layers.at(i), m_layers.at(i-1), true)));
        else
            m_layers.push_back(std::shared_ptr<Layer>(new Layer(layers.at(i), m_layers.at(i-1), false)));
    }
}

unsigned long Brain::make_decision(std::vector<double> inputs)
{
    std::vector<double> current_values = Brain::get_output(inputs);
    double max_value = 0;
    double index_of_decision = 0;
    
    max_value = *std::max_element(current_values.begin(), current_values.end());

    for (unsigned long i = 0; i < current_values.size(); i++)
    {
        if (current_values.at(i) == max_value)
        {
            index_of_decision = i;
            break;
        }
    }
    return index_of_decision;
}

std::vector<double> Brain::get_output(std::vector<double> inputs)
{
    std::vector<double> current_values = inputs;
    std::vector<double> &output_ref_ptr = current_values;
    for (unsigned long i = 0; i < m_num_layers; i++)
    {
        output_ref_ptr = m_layers.at(i)->feed_forward(output_ref_ptr);
    }
    return current_values;
}

void Brain::back_propagate(std::vector<double> error)
{
    std::vector<double> current_error = error;

    // increment backwards through layers
    for (signed long i = m_layers.size()-1; i >= 0; i--)
    {
        current_error = m_layers.at(i)->feed_backward(current_error, m_learning_rate);
    }
    
}
