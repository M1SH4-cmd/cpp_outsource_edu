cmake_minimum_required(VERSION 3.10)
project(MyBoostProject)

# Указываем путь к vcpkg (если не установлен глобально)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

# Ищем Boost (укажите нужные компоненты, например, filesystem, system)
find_package(Boost REQUIRED COMPONENTS filesystem system)

# Добавляем исполняемый файл
add_executable(my_app main.cpp)

# Линкуем Boost к проекту
target_link_libraries(my_app PRIVATE
        Boost::filesystem
        Boost::system
)