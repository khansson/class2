


add_executable(prog)

target_sources(prog PRIVATE main.cpp)

add_subdirectory(library)


target_link_libraries(prog PUBLIC MyLib)