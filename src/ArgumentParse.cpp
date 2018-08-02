#include "ArgumentParse.hpp"
#include <stdbool.h>
#include<array>
namespace ArgPar{
    void Params::ParseCommands(std::vector<std::string> Commands)
    {
        /*
        *The function parses the Given input parameters and returns their to the class members.
        * 
        */
       std::vector<std::string> Bad_Values = {"-f","-o"};
       //Lambda Function below for bad parameters like not specifying a good parameter.
        /*
        *Lambda function not capturing with reference.  
        */
        auto CheckBad_Values = [&Bad_Values](std::string token) -> bool{
            for(int i=0;i<Bad_Values.size();i++)
            {
                if(Bad_Values[i] == token)
                    return true;
            }
        };
        
        
        if((Commands.size()-1)%2 != 0)
            {
                std::cout<<"Unable To Parse. Missing Parameters.";
            }
        std::string Maker;
        
        for(int iter=1;iter<Commands.size();iter+=2)
        {
            if(Commands[iter]=="-f")
            {
                Maker = Commands[iter+1];
                if(CheckBad_Values(Maker) == false)
                {
                    if(Maker.at(0) == '"')
                    {
                        Maker.erase(0,1);
                        Maker.erase(Maker.size() - 1);
                    }
                    this->filename = Maker;
                }
                else
                {
                    std::cout<<"Bad argument.";
                }
            }
            if(Commands[iter]=="-o")
            {
                this->outputfilename = Commands[iter+1];
            }            
        }
    }
}