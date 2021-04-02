cmake_minimum_required(VERSION 3.1.0)
project(AUV-Controller)
add_compile_options(-std=c++11)
include_directories( 
    /json
    /HAUVC-Model 
    //HAUVC-Model/PID-Controller
)
set(JSON_HEADERS
    json/config.h
    json/forwards.h
    json/json_features.h
    json/value.h
    json/reader.h
    json/version.h
    json/writer.h
    json/assertions.h
    json/allocator.h 
    json/json_tool.h 
    
)
set(JSON_SOURCES
    json/json_reader.cpp
    json/json_value.cpp
    json/json_writer.cpp
    json/json_valueiterator.inl
)
add_library(json_lib ${JSON_SOURCES} ${JSON_HEADERS})
add_library(pid_lib HAUVC-Model/PID-Controller/PID.cpp HAUVC-ModelPID-Controller/PID.h)
add_library(model_lib HAUVC-Model/model.cpp HAUVC-Model/action.h HAUVC-Model/model.h )
add_executable(model_build controller.cpp controller.h)
link_libraries(model_build pid_lib model_lib json_lib)
