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
    Neuron(unsigned long num_prev_layer_neurons);
    
    /// Destructor
    ~Neuron(){}
    
    /// multiply through by coefficients
    double fire(std::vector<double> input);
    
    /// for bias neuron
    double fire(int input);

    
private:
    std::vector<double> m_coefficients;
};

#endif /* Neuron_hpp */
