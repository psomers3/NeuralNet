//
//  InputLayer.hpp
//  C++ Build
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include <vector>

#include "Neuron.hpp"

class Layer {
public:
    /// Constructor for output layer
    Layer(unsigned long num_neurons);
    
    /// Constructor for all other layers
    Layer(unsigned long num_neurons, Layer& next_layer);
    
    /// Destructor
    ~Layer(){}
    
    std::vector<double> feed_forward(std::vector<double> inputs);
    
    unsigned long number_of_neurons() const;
    
private:
    bool m_isOutputLayer = false;
    unsigned long m_num_neurons;
    unsigned long m_num_next_layer_neurons;
    std::vector<Neuron> m_neurons;
};

#endif /* Layer_hpp */
