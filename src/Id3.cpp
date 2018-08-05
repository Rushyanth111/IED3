#include "Id3.hpp"
#include <fstream>
#include <iostream>
#include <bitset>
namespace ID3
{
void IData::ParseBuffer(std::string Filename)
{
    std::cout << "Opening filestream" << std::endl;
    std::ifstream filestream;
    char FD[128];
    filestream.open(Filename, std::ios::ate);
    if (!filestream)
    {
        std::cout << "The File is not present, please provide a valid file." << std::endl;
    }
    else
    {
        filestream.seekg(-128, std::ios::end);
        filestream.read(FD, 128);
        for (int i = 0; i < 127; i++)
        {
            if (FD[i] == '\0')
                FD[i] = '_';
        }
        std::string FF = FD;

        auto Remove_Underscore = [](std::string Er) -> std::string {
            int pos = Er.find('_');
            return Er.erase(pos);
        };
        //Into the Data
        this->Header = FF.substr(0, 3);
        this->title = Remove_Underscore(FF.substr(3, 30));
        this->artist = Remove_Underscore(FF.substr(33, 30));
        this->album = Remove_Underscore(FF.substr(63, 30));
        this->year = FF.substr(93, 4);
        this->comment = Remove_Underscore(FF.substr(97, 28));
        std::bitset<sizeof(int)> tr(FF[126]);
        this->track = std::to_string(tr.to_ullong());
        std::bitset<sizeof(int)> gn(FF[127]);
        this->genre = std::to_string(gn.to_ullong());
        Display();
    }
}
void IData::Display()
{
    std::cout << Header << std::endl;
    std::cout << title << std::endl;
    std::cout << artist << std::endl;
    std::cout << album << std::endl;
    std::cout << year << std::endl;
    std::cout << comment << std::endl;
    std::cout << track << std::endl;
    std::cout << genre << std::endl;
}

void IData::InternalParse()
{
    //Defining Values for Genre.
    std::vector<std::string> Values = 
    {
    "Blues","Classic","rock","Country","Dance","Disco","Funk",
    "Grunge","Hip-Hop","Jazz","Metal","New","Age","Oldies","Other",
    "Pop","Rhythm","and","Blues","Rap","Reggae","Rock","Techno",
    "Industrial","Alternative","Ska","Death","Metal","Pranks","Soundtrack",
    "Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz","&","Funk","Fusion",
    "Trance","Classical","Instrumental","Acid","House","Game","Sound","clip",
    "Gospel","Noise","Alternative","Rock","Bass","Soul","Punk","Space","Meditative",
    "Instrumental","Pop","Instrumental","Rock","Ethnic","Gothic","Darkwave","Techno-Industrial",
    "Electronic","Pop-Folk","Eurodance","Dream","Southern","Rock","Comedy","Cult","Gangsta",
    "Top","40","Christian","Rap","Pop/Funk","Jungle","Native","US","Cabaret","New","Wave",
    "Psychedelic","Rave","Show","tunes","Trailer","Lo-Fi","Tribal","Acid","Punk","Acid",
    "Jazz","Polka","Retro","Musical","Rock","’n’","Roll","Hard","Rock"
    };
    for(int i=0; i<=Values.size();i++)
    {
        if(this->genre == Values[i])
            {
                this->genre = Values[i];
                break;
            }
    }
}
} // namespace ID3