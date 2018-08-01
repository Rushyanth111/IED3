#pragma once
#include<string>
#include<iostream>
#include<vector>
namespace ArgPar{
    /**********************************************
     * Argument Parser functionality.
     * *******************************************/
    class Params{
        private:
        std::string filename;
        std::string outputfilename;
        public:
        Params()
        {
            filename = "1.mp3";
            outputfilename = "1.txt";
        }
        Params(std::string input,std::string output)
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
            std::cout<<"Removing Parsing Variables."<<std::endl;
        }
        void ParseCommands(std::vector<std::string> Arguments);
        std::string retfilename()
        {
            return filename;
        }
        std::string retfileout()
        {
            return outputfilename;
        }
    };
}