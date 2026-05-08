cmake_minimum_required(VERSION 3.10)
project(MontrealPotholes)

# Utiliser C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver les bibliothèques Wt
find_package(Wt REQUIRED)

# Inclure les répertoires d'en-têtes
include_directories(/usr/local/include)

# Créer l'exécutable
add_executable(potholes_app main.cpp)

# Lier les bibliothèques Wt
target_link_libraries(potholes_app
    wt
    wthttp
    boost_system
    boost_thread
    boost_filesystem
    pthread
)

# Configuration pour Wt
target_compile_definitions(potholes_app PRIVATE
    WT_NO_SPIRIT
    WT_NO_ASIO
)

# Options de compilation
target_compile_options(potholes_app PRIVATE -Wall -Wextra)