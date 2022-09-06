

#include "ReadJson.hpp"
#include <fstream>

#include <string>

#include <nlohmann/json.hpp>



std::string ReadEntryFromJsonAsString(std::string filename, std::string Key)
{


    std::ifstream inputFileStream(filename);
    nlohmann::json InputJson;

    inputFileStream >> InputJson;

   return  InputJson[Key].get<std::string>();


}

//Look how I have to write a second function that is nearly identical just to get a double
double ReadDataEntryFromJsonAsDouble(std::string filename, std::string Key)
{


    std::ifstream inputFileStream(filename);
    nlohmann::json InputJson;

    inputFileStream >> InputJson;

   return  InputJson[Key].get<double>();


}



