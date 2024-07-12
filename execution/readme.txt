We implemented 4 test cases to test our specification: 1 test case to simulate the execution of actions in diagnostic mode, 1 test case to simulate the execution of diagnostic mode then switch to control mode after 100s, 1 test case to test the execution of actions in diagnostic mode followed by a switch to control mode after 100 s and execution of actions in control mode, 1 test case to test execution of diagnostic mode followed
by a switch to control mode and a return to execution of diagnostic mode after a change in system temperature

tcs.exe -1 200 -2 150 -3 0 -4 1 -5 2 -6 3 -7 4 -8 5 -9 6 -i test4.txt
