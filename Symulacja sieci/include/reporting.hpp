#ifndef REPORTING_HPP_
#define REPORTING_HPP_

#include <ostream>
#include <string>
#include "data_type.hpp"
#include "Factory.hpp"

void generate_structure_report(const Factory& factory, std::ostream& os);
void generate_simulation_turn_report(const Factory& factory, std::ostream& os, Time currentTime);

#endif
