#### From https://github.com/kaizouman/gtest-cmake-example/blob/master/test/CMakeLists.txt

find_package(Threads REQUIRED)

# Add executables
#add_executable(Threads Threads.cc)
#target_link_libraries(Threads pthread)

add_executable(BinaryGap BinaryGap.cc)
add_executable(CyclicRotation CyclicRotation.cc)
add_executable(OddOccurencesInArray OddOccurencesInArray.cc)

add_executable(main main.cc)
