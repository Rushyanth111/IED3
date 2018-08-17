#include "Id3v1.hpp"

#define DEBUG(x) std::cout << x << std::endl;
namespace ID3v1
{
IData::IData(std::string Filename, bool std_out, std::string Output_Name, bool fileout, bool verbose_toggle)
{
    //Setting Flags:
    Verbose = verbose_toggle;

    To_Stdout = std_out;
    To_FileOut = fileout;

    if (To_FileOut == true || Output_Name != "")
    {
        Output_Filename = Output_Name;
    }

}

void IData::ReadHeader()
{
    std::cout << "Opening FileStream" << std::endl;
    std::ifstream FileStream;
    FileStream.open(Parsing_Filename, std::ios::ate);
    if (FileStream.is_open() == false)
    {
        throw std::ios_base::failure("File Doesn't Exist or Wrong File name. Cannot Open File.");
    }
    FileStream.seekg(-128, std::ios::end);
    FileStream.read(reinterpret_cast<char *>(&Tag), sizeof(Tag));
    InternalParse();
}

void IData::InternalParse()
{
    const std::array<std::string, 192> Values = {"Blues", "Classic rock", "Country", "Dance", "Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", "Rhythm and Blues", "Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz & Funk", "Fusion", "Trance", "Classical", "Instrumental", "Acid", "House", "Game", "Sound clip", "Gospel", "Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space", "Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native US", "Cabaret", "New Wave", "Psychedelic", "Rave", "Show tunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock ’n’ Roll", "Hard Rock", "Folk", "Folk-Rock", "National Folk", "Swing", "Fast Fusion", "Bebop", "Latin", "Revival", "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock", "Psychedelic Rock", "Symphonic Rock", "Slow rock", "Big Band", "Chorus", "Easy Listening", "Acoustic", "Humour", "Speech", "Chanson", "Opera", "Chamber music", "Sonata", "Symphony", "Booty bass", "Primus", "Porn groove", "Satire", "Slow jam", "Club", "Tango", "Samba", "Folklore", "Ballad", "Power ballad", "Rhythmic Soul", "Freestyle", "Duet", "Punk Rock", "Drum solo", "A cappella", "Euro-House", "Dance Hall", "Goa", "Drum & Bass", "Club-House", "Hardcore Techno", "Terror", "Indie", "BritPop", "Negerpunk", "Polsk Punk", "Beat", "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover", "Contemporary Christian", "Christian rock", "Merengue", "Salsa", "Thrash Metal", "Anime", "Jpop", "Synthpop", "Abstract", "Art Rock", "Baroque", "Bhangra", "Big Beat", "Breakbeat", "Chillout", "Downtempo", "Dub", "EBM", "Eclectic", "Electro", "Electroclash", "Emo", "Experimental", "Garage", "Global", "IDM", "Illbient", "Industro-Goth", "Jam Band", "Krautrock", "Leftfield", "Lounge", "Math Rock", "New Romantic", "Nu-Breakz", "Post-Punk", "Post-Rock", "Psytrance", "Shoegaze", "Space Rock", "Trop Rock", "World Music", "Neoclassical", "Audiobook", "Audio theatre", "Neue Deutsche Welle", "Podcast", "Indie-Rock", "G-Funk", "Dubstep", "Garage Rock", "Psybient"};
    Parsed.Title = Tag.title;
    Parsed.Artist = Tag.artist;
    Parsed.Album = Tag.album;
    Parsed.Comment = Tag.comment;
    std::bitset<32> YParse(Tag.year);
    Parsed.Year = YParse.to_ulong();
    std::bitset<8> GParse(Tag.genre);
    Parsed.Genre = Values[GParse.to_ulong()];
}

void IData::Output()
{
}

} // namespace ID3v1