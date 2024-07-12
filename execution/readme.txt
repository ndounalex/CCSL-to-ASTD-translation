# CCSL-to-ASTD-translation test case

## Source code

The source file corresponding to the TCS case modelisaiton is tcs.cpp and associated execution file is tcs.exe

## Description

We implemented 4 test cases to test our specification:
- The first test case to simulate the execution of actions in diagnostic mode. The test1.txt file contains the input commands and the test1_output.txt file contains the expected outputs.
- The second test case to simulate the execution of diagnostic mode then switch to control mode after 100s. The test2.txt file contains the input commands and the test2_output.txt file contains the expected outputs.
- The third test case to test the execution of actions in diagnostic mode followed by a switch to control mode after 100 s and execution of actions in control mode.
  The test3.txt file contains the input commands and the test3_output.txt file contains the expected outputs.
- The fourth test case to test execution of diagnostic mode followed by a switch to control mode and a return to execution of diagnostic mode after a change in system temperature.
  The test4.txt file contains the input commands and the test4_output.txt file contains the expected outputs.




## ReadTheDocs

Check our full documentation [online](https://castd.readthedocs.io/).

## Slack channel

Join project discussions [here](https://astd-cse.slack.com/)



tcs.exe -1 200 -2 150 -3 0 -4 1 -5 2 -6 3 -7 4 -8 5 -9 6 -i test4.txt
