cmake_minimum_required(VERSION "3.28.3-msvc11")

project("DryCleaners")

add_executable("${PROJECT_NAME}" "src/main.cpp" "src/order.cpp" "src/customer.cpp" "src/handle.cpp" "src/search.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #$(CMAKE_INSTALL_PREFIX)/bin <= basically the bin folder where cmake is installed. 
#install(FILES "" DESTINATION src) #$(CMAKE_INSTALL_PREFIX)/src