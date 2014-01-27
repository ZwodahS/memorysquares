#include "f_common.hpp"
#include "f_conversion.hpp"

namespace zf
{
    std::vector<std::string> splitString(std::string str, int maxChar)
    {
        std::vector<std::string> strings;
        std::vector<std::string> tokens = zf::tokenize(str);
        std::string curr = "";
        int token = 0 ;
        for(std::vector<std::string>::iterator it = tokens.begin() ; it != tokens.end() ; ++it)
        {
            if(curr.size() + 1 + (*it).size() > maxChar)
            {
                if(token == 0)
                {
                    token = 0;
                    strings.push_back(*it);
                }
                else
                {
                    strings.push_back(curr);
                    curr = "";
                    curr += *it;
                    token = 1;
                }
            }
            else
            {
                if(token != 0)
                {
                    curr += " ";
                }
                curr += *it;
                token++;
            }
        }
        if(token != 0)
        {
            strings.push_back(curr);
        }
        return strings;
    }
}

