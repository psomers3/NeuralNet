//
//  Brain.hpp
//
//  Created by Peter Somers on 2/10/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#ifndef Brain_hpp
#define Brain_hpp

#include <vector>
#include "Layer.hpp"



class Brain
{
public:
    /// Constructor: takes a vector of the number of neurons in each layer.
    /* The first value is the input layer and the last the output layer.
     */
    Brain(std::vector<unsigned long> layers);
    
    // returns index of output layer that is the highest
    unsigned long make_decision(std::vector<double> inputs);
    
    // returns output layer values
    std::vector<double> get_output(std::vector<double> inputs);
    
    // update neuron coefficients using gradient descent given error values
    void back_propagate(std::vector<double> error);
    
private:
    unsigned long m_num_layers;
    double m_learning_rate = 0.1;
    std::vector<std::shared_ptr<Layer>> m_layers;
};

#endif /* Brain_hpp */
