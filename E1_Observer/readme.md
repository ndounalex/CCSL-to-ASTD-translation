## Descriptions
This folder contains the specification of our observer-based system, representing the scenario where we have a specification that translates from CCSL to TASTD, which in turn observes a TASTD specification applied to our TCS case. Here, we simulate the scenario where the TASTD specification is correct, and so our observer ensures that everything is correct.
* The file TTCS_case_E1_observer.eastd contains the specification of our observer-based system
* The file verificationobserver.cpp contains the C++ file corresponding to our specification, generated from cASTD
* The files inputs_1.txt and inputs_2.txt contain the test cases.

## Commands
* invalid inputs execution command: ./verification -1 300 -2 50 -3 0 -4 1 -5 2 -6 6 -7 4 -8 5 -9 8 -i inputs_2.txt
* valid inputs execution command: ./verification -1 300 -2 50 -3 0 -4 1 -5 2 -6 4 -7 6 -8 5 -9 7 -i inputs_1.txt

