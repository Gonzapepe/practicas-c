# CMakeList.txt: archivo del proyecto de CMake de nivel superior, establezca la configuración global
# e incluya los subproyectos aquí.
#
cmake_minimum_required (VERSION 3.8)

project ("practice-c")

# Incluya los subproyectos.

add_subdirectory ("arrays")
add_subdirectory ("linked-lists")
add_subdirectory ("stacks")