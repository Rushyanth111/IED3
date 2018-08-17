#include<vector>
#include<string>
#include<bitset>
#include <fstream>
#include <iostream>
#include <array>
namespace ID3{
    class IData_One{
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
        }UPTag;

        //Parsed Data from the Tag.
        struct
        {
            std::string Title;
            std::string Artist;
            std::string Album;
            short int Year;
            std::string Comment;
            std::string Genre;
        }Parsed;
        void InternalParse();
        void ParseBuffer(std::string Filename);
        void Display();
    };

    class IData_Two{ //ID3v2.3 Data Parsing Class. Why Class? No clue. <- Find that out.
        private:

        //Header Flags for  
        struct Header_Flags{
            bool Unsyncronization = false;
            bool Extended_Header = false;
            bool Experimental_Header = false;
        }Flags;

        struct Header_Structure{
            char File_Indentifier[3];
            char Major_Revision;//ID3v2 Majour Version.
            char Revision_Number; 
            char flags;
            char size[4]; //In the form of 0xxxxxxx for all 4. MSB discarded.
        }Header;
        public:
        void Read_Header(std::string Filename);
        void HeaderParse(); //Sets Flags.
    };
}