cmake_minimum_required(VERSION 3.0)
project (Forca VERSION 1.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17)#versao do c++

include_directories( ./include) #botar os includes

# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp
add_executable(forca
               ./src/File.cpp 
               ./src/Forca.cpp 
               ./src/main.cpp 
               ./src/Player.cpp )
