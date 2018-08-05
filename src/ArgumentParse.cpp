#include "ArgumentParse.hpp"
#include <stdbool.h>
#include <array>
namespace ArgPar
{
void Params::ParseCommands(std::vector<std::string> &Commands)
{
    if(Commands.size()==1)
    {
        std::cout<<"Error! There's no argument. Please Provide Arguments.";
    }
    else if(Commands.size()==2)
    {
        if(Commands[2]=="help"|Commands[2]=="Help")
        {
            this->Helptext();
        }
        else
        {
            std::cout<<"Error! There's no Proper argument. Please Provide Proper Arguments.";
            this->Helptext();
        }
    }
    else if(Commands.size()<3)
    {
        std::cout<<"Not Enough Arguments."<<std::endl<<"Please Check the Number of arguments again.";
        this->Helptext();
    }
    else 
    {
        //Bad Values that need to be check against
        std::vector<std::string> Bad_Values = {"-f", "-o","-h","help","-v"};
        Commands.erase(Commands.begin());

        //Lambda Function below for bad parameters like not specifying a good parameter.
        auto CheckBad_Values = [&Bad_Values](std::string token) -> bool {
            for (int i = 0; i < Bad_Values.size(); i++)
            {
                if (Bad_Values[i] == token)
                    return true;
            }
        };


        //Parsing Input parameters.
        if ((Commands.size() - 1) % 2 != 0)
        {
            std::cout << "Unable To Parse. Missing Parameters.";
        }
        for (int iter = 0; iter < Commands.size(); iter ++)
        {
            if (Commands[iter] == "-f")
            {
                std::string Maker = Commands.at(iter + 1);
                if (CheckBad_Values(Maker) == false)
                {
                    //To erase the first and last double quote.
                    Maker.erase(0, 1);
                    Maker.erase(Maker.size() - 1);
                    this->filename = Maker;
                    Maker.clear();
                }
                else
                    continue;
            }
            else if (Commands[iter] == "-o")
            {
                std::string Maker = Commands.at(iter + 1);
                if (CheckBad_Values(Maker) == false)
                {
                    //To erase the first and last double quote.
                    Maker.erase(0, 1);
                    Maker.erase(Maker.size() - 1);
                    this->outputfilename = Maker;
                    Maker.clear();
                }
                else
                    continue;
            }
            else if (Commands[iter] == "-v")
            {
                this->verbose = true;
            }
        }
    }
}
} // namespace ArgPar