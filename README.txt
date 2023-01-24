In a Linux OS Terminal:

1. cd into the 'robotcode' folder

2. copy the instructions to test the program into the 'instructions.txt' file

3. To compile the programs, run the following command:
    
    g++ robot.cpp robotmain.cpp -o main

4. To run the program, enter the following command:

    ./main

You will see the output in the 'robotcode' folder in the 'log.txt' file

Written explanation: I decided to make robotmain.cpp the program that read the inputs and wrote
the outputs. I put all the robot functions into robot.cpp which will be called from robotmain.cpp.
I was able to read the instructions but I was not able to figure out how to read from a direct file path.
Additionally, I made sure the turn value was never greater than 2 or -2 by taking the remainder 
of 4 and making that the number of turns the robot took.