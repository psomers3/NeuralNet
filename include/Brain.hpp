//
//  Brain.hpp
//  aUSie
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
    
    unsigned long make_decision(std::vector<double> inputs);
    
private:
    unsigned long m_num_layers;
    std::vector<Layer> m_layers;
};

#endif /* Brain_hpp */
