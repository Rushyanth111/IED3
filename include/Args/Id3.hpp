#include<vector>
#include<string>

namespace ID3{
    class IData_One{
        std::string Header;
        std::string title;
        std::string artist;
        std::string album;
        std::string year;
        std::string comment;
        std::string track;
        int genre_int;
        std::string genre;
        void InternalParse();
        public:
        void ParseBuffer(std::string Filename);
        void Display();
    };

    class IData_Two{
        public:
        std::string Header;
        void ParseFile(std::string Filename);
    };
}