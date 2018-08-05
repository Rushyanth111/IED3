#include<vector>
#include<string>

namespace ID3{
    class IData{
        std::string Header;
        std::string title;
        std::string artist;
        std::string album;
        std::string year;
        std::string comment;
        std::string track;
        std::string genre;
        void InternalParse();
        public:
        void ParseBuffer(std::string Filename);
        void Display();
    };
}