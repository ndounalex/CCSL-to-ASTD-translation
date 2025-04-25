# CCSL-to-ASTD-translation test case

## Source code

The source file corresponding to the TCS case modelisaiton is tcs.cpp and associated execution file is tcs.exe

## Description

We implemented 4 test cases to test our specification:
- The first test case to simulate the execution of actions in diagnostic mode.
  The test1.txt file contains the input commands and the test1_output.txt file contains the expected outputs.
- The second test case to simulate the execution of diagnostic mode then switch to control mode after 100s. 
  The test2.txt file contains the input commands and the test2_output.txt file contains the expected outputs.
- The third test case to test the execution of actions in diagnostic mode followed by a switch to control mode after 100 s and execution of actions in control mode.
  The test3.txt file contains the input commands and the test3_output.txt file contains the expected outputs.
- The fourth test case to test execution of diagnostic mode followed by a switch to control mode and a return to execution of diagnostic mode after a change in system temperature.
  The test4.txt file contains the input commands and the test4_output.txt file contains the expected outputs.

To validate our ASTD specification using our CCSL to ASTD translation, we've created an observer that we've synchronized with our specification to validate it, so an event will be valid if it's accepted by our specification and also accepted at the same time by our observer. The tcs_observer.exe file contains the executable to test our observer and the traces_observer.txt file contains the test commands to validate it. The file tcs__observer.cpp contains the c++ source code of our observer coupled with our ASTD specification for validation. The observer is executed in the same way as for the other test cases presented above.

  

## Execution

An example of a command to run test 1 could be:
./tcs -1 200 -2 150 -3 0 -4 1 -5 2 -6 3 -7 4 -8 5 -9 6 -i test1.txt
(compiled on linux)

with parameters:
* -1 which corresponds to the MAX temperature value
* -2 corresponds to the MIN temperature value
* -3 which corresponds to the index of clock d in the chain of clock ticks
* -4, which corresponds to the index of clock c in the chain of clock ticks
* -5 which corresponds to the clock index s in the clock tick string
* -6 which corresponds to the index of clock p in the clock tick string
* -7 which corresponds to the index of clock i in the clock tick string
* -8 which corresponds to the index of clock r in the clock tick string
* -9 which corresponds to the index of clock z in the clock tick string
* -i which corresponds to the name of the file containing the test commands


## ReadTheDocs

Check our full documentation [online](https://castd.readthedocs.io/).

## Slack channel

Join project discussions [here](https://astd-cse.slack.com/)
