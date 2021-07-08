#include <iostream>
#include <unistd.h> // unix standard library for Unix based command line options
#include <string>

int main(int argc, char** argv)
{

    int aflag = 0; // Just to trigger event A
    int bflag = 0; // Just to trigger event B
    char *cvalue = NULL; // To store certain string information along with the flag

    // Other non-flag/non-option inputs can be read in later using optind.

    int input_arg;

    // Auto defined variables within unistd.h
    // Need not redefine these variables as int optind; int opterr; etc.
    // Just assign values from them or read values present in them.
    /*
    1. optarg -- char* value assigned/provided to a particular flag from command line
    2. optind -- value of arguments index ranging from 0 to argc
    3. opterr -- if set to zero, inbuilt error handling will not happen. So if bad/undefined flags are provided, no error will be thrown.
    */


    while ((input_arg = getopt (argc, argv, "abc:")) != -1)
    {
        switch (input_arg)
        {
            
            case 'a':
                std::cout << "Case a" << std::endl;
                aflag = 1;
                // aflag = optarg; -- Compile ERROR
                break;
            
            case 'b':
                std::cout << "Case b" << std::endl;
                bflag = 1;
                break;
            
            case 'c':
                std::cout << "Case c" << std::endl;
                cvalue = optarg;
                // cvalue = '1'; -- Compile ERROR (char assigned to char*)
                // cvalue = "1"; -- Warning that string assigned to char* and at runtime, any args assigned to -c are simply ignored. Not even considered as non-option/non-flag args.
                break;
            
            case 'h':
                std::cout << "Possible options are: -a -b -c" << std::endl;
                return 0;

            // Default case is taken care of by inbuilt error reporter.
            // This is however needed if opterr = 0 is set at the beginning.
            /*
            default:
                std::cout << "Unrecognized option." << std::endl;
                exit(1);
            */
        }
    }

    // print output of all the variables
    std::cout << "aflag: " << aflag << ", " << "bflag: " << bflag << ", " << 
        "cvalue: " << cvalue << std::endl;

    // print other non-option/non-flag variables
    std::cout << "optind: " << optind << std::endl;
    std::cout << "Non-option/non-flag arguments: ";
    for (int i = optind; i < argc; i++)
        std::cout << argv[i] << ", ";
    std::cout << std::endl;
    
    
    std::cout << "--- END ---" << std::endl;
    return 0;
}

/*
USAGE:

./cmdArgsCpp -a
./cmdArgsCpp -a -b
./cmdArgsCpp -c foo

./cmdArgsCpp -a -c foo

./cmdArgsCpp -d

./cmdArgsCpp -a asdf -c foo bar 
    [Assigns foo to c. Recognises a does not take any value and that asdf and bar are non-option/non-flag arguments. Recognises this since only char* type variables can accept optarg assignemtns.]
*/
