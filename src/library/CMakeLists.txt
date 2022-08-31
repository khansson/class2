
add_library(MyLib ReadJson.cpp)


find_package(nlohmann_json QUIET)

if(nlohmann_json_FOUND)
  message("json is found")

else()


include(FetchContent)

  FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)

  FetchContent_MakeAvailable(json)

#COMMANDS RUN ABOVE

#cd  ./build/_deps
  #git clone ${GIT_REPOSITORY}
  # cd json
  #mkdir build
  #cmake ..
  #cmake --build .


  endif()

  target_link_libraries(MyLib PUBLIC nlohmann_json::nlohmann_json)




target_include_directories(MyLib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>  
$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}> )