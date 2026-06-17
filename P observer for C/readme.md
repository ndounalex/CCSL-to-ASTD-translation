## Description
This document contains the specification of our observer-based system, illustrating the scenario in which we have a TASTD specification that observes a C specification, which is the result of translating a CCSL specification into TASTD, to which functional aspect models have been added directly in TASTD; the example is applied to our TCS case. Here, we simulate the scenario in which the observed C specification is correct, and our observer will therefore not report any errors.

* TCS_case_with_tastd_observer_c.eastd file contains the specification of our observer-based system.
* verificationobserver.cpp file contains the C++ code corresponding to our specification, generated from cASTD.
* inputs_3.txt file contains a test case with execution sequences that are always valid for both the observer and the observed programme.

## Commands
* valid input execution command: ./verification -1 300 -2 50 -3 0 -4 1 -5 2 -6 6 -7 4 -8 5 -9 8 -i inputs_3.txt
