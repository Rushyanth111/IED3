#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <iostream>
#include <array>
#include <stdexcept>

namespace ID3v1
{
class IData
{
    //Raw Data from the tag.
    struct
    {
        char Header[3];
        char title[30];
        char artist[30];
        char album[30];
        char year[4];
        char comment[30];
        char genre[1];
    } Tag;

    //Parsed Data from the Tag.
    struct
    {
        std::string Title;
        std::string Artist;
        std::string Album;
        short int Year;
        std::string Comment;
        std::string Genre;
    } Parsed;

    //Internal Class Tags
    bool IsTagParsed = false;
    bool To_Stdout = true;
    bool To_FileOut = false;
    bool Verbose = false;

    //Internal Class Handlers.
    std::string Parsing_Filename;
    std::string Output_Filename;
    void InternalParse(); //Parsing the Internal
    void Output();
    void Option_Parse();
    void ReadHeader();
    void Verbose_out(std::string Message); //Will only print if Verbose == true;
  public:
    IData(std::string Filename, bool std_out, std::string Output_Name = "", bool fileout = false, bool verbose_toggle = false);
};

} // namespace ID3v1