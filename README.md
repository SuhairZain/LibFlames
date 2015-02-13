# LibFlames
A just-for-fun C++ Library to check compatibility between people

## What is FLAMES?
FLAMES stands for
**F**riend
**L**over
**A**ffection
**M**arriage
**E**nemy
**S**ister

## How is it calculated?
It is done by removing the common characters from 2 names one by one and then counting the remaining characters(*n*) to find the relation between them. The letters FLAMES are written and the *n*th character is removed one by one in a cyclic manner until only one remains and that letter denotes the relation between the names.

## How to use this library
1. Create an instance of LibFlames::Flames and call calculate() with the names and use a switch to analyze the results.
2. calculate() returns a status message, stating Success, Perfect Match, Empty Name or Invalid number of options.
3. result() returns the actual result, the index of the option, or -1 in case of an error.
4. @param FirstName, @param SecondName - Convenience function, uses FLAMES(6) by default.
5. @param FirstName, @param SecondName, @param @nOptions - Use this if you want to use a non-default number of options.
6. This example calls calulate() with the names "Suhair" and "Rahul" whose result is 0, indicating Friend in FLAMES.
7. *Do not forget to remove the main funtion in the library*.
