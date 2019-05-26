//
//  Neuron.hpp
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <vector>
#include "custom_types.hpp"

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
    double fire(VectorDbl input);
    
    /// set value
    void set_value(double input_value);
    
    VectorDbl propogate_error(double error, VectorDbl inputs_from_prev_layer, const double learning_rate);
    
private:
    double m_value = 0;
    double m_derivative = 0;
    double m_delta = 0;
    UnqPtrVectorDbl m_coefficients;
    double calculate_delta(double error);
    void transfer();
    double calculate_derivative();

};

#endif /* Neuron_hpp */
