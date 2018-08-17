#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <iostream>
#include <array>
#include <stdexcept>

namespace ID3v2
{
class IData
{ //ID3v2.3 Data Parsing Class. Why Class? No clue. <- Find that out.
  private:
    //Header Flags for
    struct Header_Flags
    {
        bool Unsyncronization = false;
        bool Extended_Header = false;
        bool Experimental_Header = false;
    } Flags;

    struct Header_Structure
    {
        char File_Indentifier[3];
        char Major_Revision; //ID3v2 Majour Version.
        char Revision_Number;
        char flags;
        char size[4]; //In the form of 0xxxxxxx for all 4. MSB discarded.
    } Header;

  public:
    void Read_Header(std::string Filename);
    void HeaderParse(); //Sets Flags.
};
} // namespace ID3v2