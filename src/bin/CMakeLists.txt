include_directories(${CMAKE_SOURCE_DIR}/src/lib)

add_definitions(-g)
add_definitions(-Wall)
#add_definitions(-DNDEBUG)

add_executable(nvmemulctl ${CMAKE_CURRENT_SOURCE_DIR}/nvmemulctl.c)
target_link_libraries(nvmemulctl pthread nvmemul)
