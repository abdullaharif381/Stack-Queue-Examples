# Stack-Queue-Examples

This repository contains a collection of C++ programs that demonstrate various algorithms and functionalities. Below is an overview of the included programs:

## Prefix to Postfix Conversion and Postfix Evaluation

### Overview

The `prefixToPostfix` function in this program converts a prefix expression to postfix notation. It takes a prefix expression as input and returns the equivalent postfix expression.

### Usage

To use the prefix to postfix conversion function:

1. Choose option (1) from the menu.
2. Select whether you want to convert a prefix expression to postfix or evaluate a postfix expression.
3. Enter the expression when prompted.
4. The program will display the converted postfix expression or the result of the postfix expression evaluation.

## Josephus Problem and Students' Lunch Preference

### Overview

The program also includes solutions to the Josephus problem and a scenario where students have lunch preferences for sandwiches.

- The `josephus` function solves the Josephus problem, where `N` people stand in a circle and every `M`-th person is eliminated until only one remains.

- The `students_deprived` function calculates the number of students unable to eat their preferred sandwiches. It takes two arrays as input, one representing students' preferences and the other representing available sandwich types.

### Usage

To use the Josephus problem or lunch preference functions:

1. Choose option (2) from the menu.
2. Select whether you want to solve the Josephus problem or calculate the number of students unable to eat their preferred sandwiches.
3. Follow the on-screen prompts to provide input, such as the number of people (N), passes (M), or student preferences and sandwich types.
4. The program will display the result based on your input.

## Prerequisites

- C++ compiler

## Getting Started

1. Clone this repository to your local machine.
2. Compile the `main.cpp` file using a C++ compiler.

```bash
g++ main.cpp -o cpp_programs
