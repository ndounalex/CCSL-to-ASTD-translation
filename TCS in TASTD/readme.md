This folder contains:
- the file tcscasetastd.eastd, which corresponds to the TASTD specification for the case study.
- the file tcscasetastd.cpp, which is the C++ file generated from our specification using cASTD.
- The tcs file is the executable obtained after compiling the tcscasetastd.cpp file.
- The test1_inputs.txt file is a test file to be used for testing the tcs executable. It contains a valid example of an action sequence, so its execution does not result in any errors on the console. To run these tests, use a command of the form: ".\ tcs -1 300 -2 50 -i test1_inputs.txt" where the first two parameters specify the maximum and minimum temperatures, respectively.
- The file test2_inputs.txt is also a test file; however, it contains an example of actions that will cause an error, specifically an “Event is not executable” error due to the “insert_rod” action on line 18, which attempts to insert three consecutive rods into the reactor. Since this action is prohibited, it results in an error.
