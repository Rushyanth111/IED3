#include <iostream>
#include <string>
#include <vector>
#include "ArgumentParse.hpp"
#include "Id3.hpp"
#include<unistd.h>
/******************************************************
    Main.cpp is used for parsing the given file and 
    passing it on to the function. Do not use this 
    file for anything beying making passing on the
    parsed file name to the actual backend.
******************************************************/
int main(int argc, char *argv[])
{
    /*
    String input can be something like -f "Filename.mp3" -o "Fileout.txt"
    Both can be together, actually, and it's fine if it's like that too.
    We Need to split them up.
    */

    //Gaurding the argument list, else return.
    if (argc > 1)
    {
        std::vector<std::string> arguments(argv, argv + argc);
        ArgPar::Params Par(arguments);
        ID3::IData Ar;
        std::cout << Par.retfilename() << std::endl;
        Ar.ParseBuffer(Par.retfilename());
        Ar.Display();
        std::cout<<std::endl;
    }
    /*
   The first argument is always the process execution name.
   The second onward are the file parameters. 
   */
    return 0;
}