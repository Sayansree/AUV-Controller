cmake_minimum_required(VERSION 3.1.0)
project(AUV-Controller)
include_directories( /jsonlib)
# file(COPY ${CMAKE_SOURCE_DIR}/controllerconfig.json DESTINATION /build)
set(JSON_HEADERS
    jsonlib/config.h
    jsonlib/forwards.h
    jsonlib/json_features.h
    jsonlib/value.h
    jsonlib/reader.h
    jsonlib/version.h
    jsonlib/writer.h
    jsonlib/assertions.h
    jsonlib/allocator.h 
    jsonlib/json_tool.h 
    
)
set(JSON_SOURCES
    jsonlib/json_reader.cpp
    jsonlib/json_value.cpp
    jsonlib/json_writer.cpp
    jsonlib/json_valueiterator.inl
)
add_library(json ${JSON_SOURCES} ${JSON_HEADERS})
add_executable(parse controller.cpp controller.h)
target_link_libraries(parse json)