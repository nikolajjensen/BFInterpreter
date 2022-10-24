# BF Interpreter
This sample project provides a (painfully !!!!) slow BF interpreter. There are many optimisations to do to make it run faster, but all functionality should be present.

Please note: The '`,`' operator is not supported.

## How to run
To compile, run the following command:

    make

Which will create a `BFInterpreter` executable in the same directory. To run the project, run either:

    ./BFInterpreter -t

which will run the test suite; or:

    ./BFInterpreter ./bf/collatz.bf
    
(replace path if needed) to run a BF program at the designated path.


## How to clean
To clean the project, execute:

    make clean

which will remove the executable.