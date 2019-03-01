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
#include <cmath>
#include "Neuron.hpp"

class Layer {
public:
    /// Constructor for input layer
    Layer(unsigned long num_neurons);
    
    /// Constructor for all other layers
    Layer(unsigned long num_neurons, std::shared_ptr<Layer> prev_layer, bool isOutputLayer);
    
    /// Destructor
    ~Layer(){}
    
    std::vector<double>& feed_forward(std::vector<double>& inputs);
    
    std::vector<double> feed_backward(std::vector<double> errors, double learning_rate);
    
    unsigned long number_of_neurons() const;
    
private:
    std::shared_ptr<Layer> m_prev_layer;
    bool m_isOutputLayer = false;
    bool m_isInputLayer = false;
    unsigned long m_num_neurons;
    unsigned long m_num_prev_layer_neurons;
    std::vector<std::unique_ptr<Neuron>> m_neurons;
    std::vector<double> m_outputs;
};

#endif /* Layer_hpp */
