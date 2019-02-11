//
//  Neuron.hpp
//  aUSie
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <vector>

class Neuron
{
public:
    /// Constructor for output layer neurons
    Neuron();
    
    /// Constructor for all other layer neurons
    Neuron(unsigned long num_neurons_this_layer, unsigned long num_next_layer_neurons);
    
    /// Destructor
    ~Neuron(){}
    
    /// multiply through by coefficients
    std::vector<double> fire(double input);
    
private:
    std::vector<double> m_coefficients;
};

#endif /* Neuron_hpp */
