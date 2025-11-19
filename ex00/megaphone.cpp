#include <string>
#include <cctype>
#include <iostream>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s = argv[i];
        for (std::string::iterator j = s.begin(); j != s.end(); j++)
        {
            unsigned char c = static_cast<unsigned char>(*j);
            *j = static_cast<char>(std::toupper(c));
        }
        std::cout << s;
        if (i < argc - 1)
            std::cout << ' ';
    }
    std::cout << '\n';
    return 0;
}
