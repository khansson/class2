

#include "ReadJson.hpp"
#include <fstream>

#include <string>

#include <nlohmann/json.hpp>



std::string ReadDataEntryFromJson(std::string filename, std::string Key)
{


    std::ifstream inputFileStream(filename);
    nlohmann::json InputJson;

    inputFileStream >> InputJson;

   return  InputJson[Key].get<std::string>();


}