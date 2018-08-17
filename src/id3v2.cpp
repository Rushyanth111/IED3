#include "Id3v2.hpp"
namespace ID3v2
{
void IData::Read_Header(std::string Filename)
{
    std::ifstream FileStream;
    FileStream.open(Filename, std::fstream::in | std::ios::binary);
    if (FileStream.is_open() == false)
    {
        throw std::ios_base::failure("File Doesn't Exist or Wrong File name");
    }

    char Header_Buffer[10];
    std::string HB(Header_Buffer);
    FileStream.seekg(0, std::ios::beg);
    FileStream.read(reinterpret_cast<char *>(&Header), sizeof(Header));
}
} // namespace ID3v2