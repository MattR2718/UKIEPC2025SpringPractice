# CMakeList.txt : CMake project for UKIEPC2025SpringPractice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("UKIEPC2025SpringPractice")

# Add source to this project's executable.
add_executable (UKIEPC2025SpringPractice "UKIEPC2025SpringPractice.cpp" "UKIEPC2025SpringPractice.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET UKIEPC2025SpringPractice PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.



add_subdirectory(A)
add_subdirectory(B)
add_subdirectory(C)
add_subdirectory(D)
add_subdirectory(E)
add_subdirectory(F)
add_subdirectory(G)
add_subdirectory(H)
add_subdirectory(I)