//
//  Brain.cpp
//  aUSie
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
    m_layers.push_back(Layer(layers.at(0)));
    for (unsigned long i = 1; i < m_num_layers; i++)
    {
        if (i == m_num_layers - 1)
            m_layers.push_back(Layer(layers.at(i), m_layers.at(i-1), true));
        else
            m_layers.push_back(Layer(layers.at(i), m_layers.at(i-1), false));
    }
}

unsigned long Brain::make_decision(std::vector<double> inputs)
{
    std::vector<double> current_values = inputs;
    unsigned long index_of_decision = 0;
    double max_value = 0;
    
    for (unsigned long i = 0; i < m_num_layers; i++)
    {
        current_values = m_layers.at(i).feed_forward(current_values);
    }
    
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
