//
//  custom_types.h
//  NeuralNet
//
//  Created by Peter Somers on 3/1/19.
//  Copyright © 2019 Peter Somers. All rights reserved.
//

#ifndef custom_types_hpp
#define custom_types_hpp

#include <vector>

typedef std::vector<double> VectorDbl;

typedef std::shared_ptr<std::vector<double>> ShrPtrVectorDbl;

typedef std::unique_ptr<std::vector<double>> UnqPtrVectorDbl;

#endif /* custom_types_hpp */
