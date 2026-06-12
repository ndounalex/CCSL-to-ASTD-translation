# Environment module for the observer-based verification system

## Source code

The source file corresponding to the environment module is environment.cpp and associated execution file is environment.exe

## Execution
Compilation Command:
* g++ -std=c++14 environment.cpp pugixml.cpp -o environment ./environment

An example of a command to run environment could be:
* ./environment diagnostic_trace diagnostic_clocks_index.txt control_trace control_clocks_index.txt --observer CCSL

with parameters:
* The command takes as its parameter a list of CCSL trace files to be combined to generate our input file; for each CCSL trace file, a file is specified following it that maps a clock to its index within the corresponding trace file.
* The --observer option is used to specify that you wish to generate an input file for a configuration where the CCSL-to-TASTD translation is used as an observer; otherwise, it is assumed that the translation itself will be the subject of observation.

We tested our environmental programme on the CCSL trace files: control_trace and diagnostic_trace. We obtained the files inputs_1.txt and inputs_2.txt respectively, to be used as inputs in the case where the translation is used as an observer and in the case where it is the programme being observed.


## Slack channel

Join project discussions [here](https://astd-cse.slack.com/)

