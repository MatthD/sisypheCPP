cmake_minimum_required(VERSION 3.8)
project(sisypheCpp)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(ZLIB REQUIRED)
find_package(LibMagic REQUIRED)

message(INFO "${ZLIB_LIBRARY}")

include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${ZLIB_INCLUDE_DIRS} )
include_directories( ${LibMagic_INCLUDE_DIRS} )

file(COPY magic DESTINATION .)
file(COPY src/worker.json DESTINATION .)


set(SOURCE_FILES main.cpp src/worker/filetype/filetype.cpp src/worker/filetype/filetype.h src/worker/out/out.cpp src/worker/out/out.h src/worker/walkerfs/walkerfs.cpp src/worker/walkerfs/walkerfs.h)
add_executable(sisypheCpp ${SOURCE_FILES})
target_link_libraries( sisypheCpp  ${Boost_LIBRARIES} ${ZLIB_LIBRARY} ${LibMagic_LIBRARY} ${JSONCPP_LIBRARIES})
