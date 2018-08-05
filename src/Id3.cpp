#include "Id3.hpp"
#include<fstream>
#include<iostream>
namespace ID3{
    void IData::Parse(std::string Filename)
    {
        std::cout<<"Opening filestream"<<std::endl;
        std::ifstream filestream;
        char FD[128];
        filestream.open(Filename,std::ios::ate);
        if(!filestream)
        {
            std::cout<<"The File is not present, please provide a valid file."<<std::endl;
        }
        else
        {
            filestream.seekg(-128,std::ios::end);
            filestream.read(FD,128);
            for(int i=0;i<127;i++)
            {
                if(FD[i]=='\0')
                    FD[i]='_';
            }
            std::string FF = FD;
            this->Header = FF.substr(0,3);
            this->title = FF.substr(3,30);
            this->artist = FF.substr(33,30);
            this->album = FF.substr(63,30);
            this->year = FF.substr(93,4);
            this->comment = FF.substr(97,30);
            this->genre = FF.substr(126,2);
            Display();  
        }
    }
    void IData::Display()
    {
        std::cout<<Header<<std::endl;
        std::cout<<title<<std::endl;
        std::cout<<artist<<std::endl;
        std::cout<<album<<std::endl;
        std::cout<<year<<std::endl;
        std::cout<<comment<<std::endl;
        std::cout<<genre<<std::endl;
    }
}