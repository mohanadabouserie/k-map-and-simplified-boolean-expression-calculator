# K-Map and Simplified Boolean Expression Calculator

This code calculates the simplified Boolean expression using the Karnaugh map (K-Map) method. It takes as input the number of variables and the minterms, and generates the corresponding K-Map and simplified Boolean expression.

## Dependencies
- This code is written in C++.
- It uses the standard library header `<bits/stdc++.h>`.

## How to Use
1. Clone the repository or download the code file.
2. Compile the code using a C++ compiler.
3. Run the compiled program.
4. Enter the file directory of the input file when prompted.
5. Follow the instructions provided by the program to input the test cases.

## Input Format
The input file should follow the following format:
<number_of_test_cases>
<number_of_variables>
<number_of_minterms>
<minterm_1> <minterm_2> ... <minterm_n>
...
- `<number_of_test_cases>`: The number of test cases.
- `<number_of_variables>`: The number of variables (currently supports 3 variables only).
- `<number_of_minterms>`: The number of minterms in the K-Map.
- `<minterm_1> <minterm_2> ... <minterm_n>`: The minterms in the K-Map.

## Output
The program generates an output file named `out.txt` in the same directory as the input file.
- The output file contains the simplified Boolean expressions for the given test cases.

## Example
Suppose you have the following input file named `input.txt`:
2
3
4
0 1 3 7
3
2
2 6
After running the code using this input file, the output file `out.txt` will contain the following:
1
K-map =
0 0 0 1
0 0 0 0

F = A'BC' + ABC
2
K-map =
0 0 1 0
0 0 0 0

F = AB'C'
