#pragma once
#include <string>
#include <iostream>
#include <vector>
#include<stdbool.h>
namespace ArgPar
{
/**********************************************
     * Argument Parser functionality.
     * *******************************************/
class Params
{
  private:
    std::string filename;
    std::string outputfilename;
    bool verbose = false;
  public:
    Params()
    {
        filename.clear();
        outputfilename.clear();
    }
    Params(std::string input, std::string output)
    {
        filename = input;
        outputfilename = output;
    }
    Params(std::string input)
    {
        filename = input;
    }
    Params(std::vector<std::string> init)
    {
        ParseCommands(init);
    }
    ~Params()
    {
        std::cout << "Removing Parsing Variables." << std::endl;
    }
    void ParseCommands(std::vector<std::string> &Arguments);
    inline std::string retfilename()
    {
        return filename;
    }
    inline std::string retfileout()
    {
        return outputfilename;
    }
    void Helptext(); //To Do, not implemented.
};
} // namespace ArgPar