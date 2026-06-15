## Description
This folder contains the specification of our observer-based system, representing the scenario where we have a TASTD specification that observes a specification resulting from a translation from CCSL to TASTD applied to our TCS case. Here, we simulate the scenario where the CCSL specification is incorrect, and so our observer will report violations.
* The file TCS_case_with_tastd_observer_p.eastd contains the specification of our observer-based system
* The file verificationobserver.cpp contains the C++ file corresponding to our specification, generated from cASTD
* The file inputs_4.txt contains a test case with execution sequences that do not conform to the specifications and will trigger violations
