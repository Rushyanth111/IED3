#include "Id3.hpp"
#include <fstream>
#include <iostream>
#include <bitset>
#include<array>
#define DEBUG(x) std::cout<<x<<std::endl 
namespace ID3
{
void IData_One::ParseBuffer(std::string Filename)
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
        std::bitset<8> tr(FF[126]);
        this->track = std::to_string(tr.to_ullong());
        std::bitset<8> gn(FF[127]);
        this->genre_int = gn.to_ulong();
        this->InternalParse();
    }
}
void IData_One::Display()
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

void IData_One::InternalParse()
{
    //Defining Values for Genre.
    std::array<std::string,192> Values = {"Blues","Classic rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop","Jazz","Metal","New Age","Oldies","Other","Pop","Rhythm and Blues","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz & Funk","Fusion","Trance","Classical","Instrumental","Acid","House","Game","Sound clip","Gospel","Noise","Alternative Rock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop","Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic","Pop-Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native US","Cabaret","New Wave","Psychedelic","Rave","Show tunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock ’n’ Roll","Hard Rock","Folk","Folk-Rock","National Folk","Swing","Fast Fusion","Bebop","Latin","Revival","Celtic","Bluegrass","Avantgarde","Gothic Rock","Progressive Rock","Psychedelic Rock","Symphonic Rock","Slow rock","Big Band","Chorus","Easy Listening","Acoustic","Humour","Speech","Chanson","Opera","Chamber music","Sonata","Symphony","Booty bass","Primus","Porn groove","Satire","Slow jam","Club","Tango","Samba","Folklore","Ballad","Power ballad","Rhythmic Soul","Freestyle","Duet","Punk Rock","Drum solo","A cappella","Euro-House","Dance Hall","Goa","Drum & Bass","Club-House","Hardcore Techno","Terror","Indie","BritPop","Negerpunk","Polsk Punk","Beat","Christian Gangsta Rap","Heavy Metal","Black Metal","Crossover","Contemporary Christian","Christian rock","Merengue","Salsa","Thrash Metal","Anime","Jpop","Synthpop","Abstract","Art Rock","Baroque","Bhangra","Big Beat","Breakbeat","Chillout","Downtempo","Dub","EBM","Eclectic","Electro","Electroclash","Emo","Experimental","Garage","Global","IDM","Illbient","Industro-Goth","Jam Band","Krautrock","Leftfield","Lounge","Math Rock","New Romantic","Nu-Breakz","Post-Punk","Post-Rock","Psytrance","Shoegaze","Space Rock","Trop Rock","World Music","Neoclassical","Audiobook","Audio theatre","Neue Deutsche Welle","Podcast","Indie-Rock","G-Funk","Dubstep","Garage Rock","Psybient"};
    this->genre = Values[genre_int];
}

/*************************************
ID3v2.3 Parsing.
**************************************/

void IData_Two::ParseFile(std::string Filename)
{
    std::ifstream File;
    File.open(Filename,std::ios::in);
    if(!File)
    {
        std::cout<<"Error, File doesn't Exist";
    }
    char HF[10];
    File.seekg(0,std::ios::beg);
    File.read(HF,10);
    for (int i = 0; i < 10; i++)
    {
        if (HF[i] == '\0')
            HF[i] = '_';
    }
    std::cout<<HF;
}
} // namespace ID3