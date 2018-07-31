#include "ArgumentParse.hpp"
#include <stdbool.h>
namespace ArgPar{
    void Params::ParseCommands(std::vector<std::string> Commands)
    {
        std::string Maker;
        for(int iter=1;iter<Commands.size();iter+=2)
        {
            if(Commands[iter]=="-f")
            {
                Maker = Commands[iter+1];
                if(Maker.at(0) == '"')
                {
                    Maker.erase(0,1);
                    Maker.erase(Maker.size() - 1);
                }
                this->filename = Maker;
            }
            if(Commands[iter]=="-o")
            {
                this->outputfilename = Commands[iter+1];
            }            
        }
    }
}