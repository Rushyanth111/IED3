#include "Id3.hpp"
#include<stdexcept>

#define DEBUG(x) std::cout << x << std::endl;
namespace ID3
{
void IData_One::ParseBuffer(std::string Filename)
{
    std::cout << "Opening FileStream" << std::endl;
    std::ifstream FileStream;
    FileStream.open(Filename, std::ios::ate);
    if(FileStream.is_open() == false)
    {
        throw std::ios_base::failure("File Doesn't Exist or Wrong File name");
    }
    FileStream.seekg(-128, std::ios::end);
    FileStream.read(reinterpret_cast<char *>(&UPTag), 128);
}


void IData_One::InternalParse()
{
    //Defining Values for Genre.
    std::array<std::string, 192> Values = {"Blues", "Classic rock", "Country", "Dance", "Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", "Rhythm and Blues", "Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz & Funk", "Fusion", "Trance", "Classical", "Instrumental", "Acid", "House", "Game", "Sound clip", "Gospel", "Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space", "Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native US", "Cabaret", "New Wave", "Psychedelic", "Rave", "Show tunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock ’n’ Roll", "Hard Rock", "Folk", "Folk-Rock", "National Folk", "Swing", "Fast Fusion", "Bebop", "Latin", "Revival", "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock", "Psychedelic Rock", "Symphonic Rock", "Slow rock", "Big Band", "Chorus", "Easy Listening", "Acoustic", "Humour", "Speech", "Chanson", "Opera", "Chamber music", "Sonata", "Symphony", "Booty bass", "Primus", "Porn groove", "Satire", "Slow jam", "Club", "Tango", "Samba", "Folklore", "Ballad", "Power ballad", "Rhythmic Soul", "Freestyle", "Duet", "Punk Rock", "Drum solo", "A cappella", "Euro-House", "Dance Hall", "Goa", "Drum & Bass", "Club-House", "Hardcore Techno", "Terror", "Indie", "BritPop", "Negerpunk", "Polsk Punk", "Beat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover", "Contemporary Christian", "Christian rock", "Merengue", "Salsa", "Thrash Metal", "Anime", "Jpop", "Synthpop", "Abstract", "Art Rock", "Baroque", "Bhangra", "Big Beat", "Breakbeat", "Chillout", "Downtempo", "Dub", "EBM", "Eclectic", "Electro", "Electroclash", "Emo", "Experimental", "Garage", "Global", "IDM", "Illbient", "Industro-Goth", "Jam Band", "Krautrock", "Leftfield", "Lounge", "Math Rock", "New Romantic", "Nu-Breakz", "Post-Punk", "Post-Rock", "Psytrance", "Shoegaze", "Space Rock", "Trop Rock", "World Music", "Neoclassical", "Audiobook", "Audio theatre", "Neue Deutsche Welle", "Podcast", "Indie-Rock", "G-Funk", "Dubstep", "Garage Rock", "Psybient"};
    
}

/*************************************
ID3v2.3 Parsing.
**************************************/

void IData_Two::Read_Header(std::string Filename)
{
    std::ifstream FileStream;
    FileStream.open(Filename,std::fstream::in|std::ios::binary);
    if(FileStream.is_open() == false)
    {
        throw std::ios_base::failure("File Doesn't Exist or Wrong File name");
    }

    char Header_Buffer[10];
    std::string HB(Header_Buffer);
    FileStream.seekg(0, std::ios::beg);
    FileStream.read(reinterpret_cast<char *>(&Header),sizeof(Header));

}


} // namespace ID3