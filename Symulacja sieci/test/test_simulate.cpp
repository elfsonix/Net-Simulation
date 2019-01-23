// 4b_4: Wittek (297473), Wątorska (297469), Rabajczyk (286498)
// Created by Katarzyna Wątorska
/*


#include "gtest/gtest.h"
#include "Simulation.hpp"
#include "gmock/gmock.h"
#include "reporting.hpp"

using ::testing::Return;
using ::testing::AtLeast;


std::function<void()> globalFunction = generate_structure_report_ramp;

class IGlobalFunctionMock {
public:
    virtual void global_function_mocked_implementation() = 0;
    virtual ~IGlobalFunctionMock() = default;
};

// Definicja klasy-mocka zawierającej "implementacje" globalnej funkcji.
class GlobalFunctionMock: public IGlobalFunctionMock {
public:
    MOCK_METHOD0(global_function_mocked_implementation, void());
};


TEST(SimulateTest, )*/
