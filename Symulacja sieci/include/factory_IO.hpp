#ifndef FACTORY_IO_HPP_
#define FACTORY_IO_HPP_

#include "Factory.hpp"

#include <iostream>
#include <string>
#include <vector>

void load_factory_structure(std::string pathToFile);
void save_factory_structure(const Factory& factory);


#endif /* INCLUDE_FACTORY_IO_HPP_ */
