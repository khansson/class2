#ifndef MPIC_READJSON
#define MPIC_READJSON




#include <fstream>

#include <string>

#include <nlohmann/json.hpp>

std::string ReadEntryFromJsonAsString(std::string filename, std::string Key);


//Look how I have to write a second function that is nearly identical just to get a double
double ReadDataEntryFromJsonAsDouble(std::string filename, std::string Key);


//With a template I can do both in one shot!
template<typename T>
T ReadDataEntryFromJson(std::string filename, std::string Key)
{


    std::ifstream inputFileStream(filename);
    nlohmann::json InputJson;

    inputFileStream >> InputJson;

   return  InputJson[Key].get<T>();


}



#endif /* MPIC_READJSON */
