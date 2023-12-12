cmake_minimum_required(VERSION 3.12)
project(TGN_v2)

set(CMAKE_CXX_STANDARD 11)

# Общие файлы заголовков
set(COMMON_HEADERS
    include/model.h
    include/view.h
    include/controller.h
)

# Добавление исполняемого файла
add_executable(main
    model/model.cpp
    view/view.cpp
    controller/controller.cpp
    main.cpp
    ${COMMON_HEADERS} #Включение общих файлов заголовков
)

# Установка стандарта C++11
set_target_properties(main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(main PRIVATE include)
# Установка каталога для исполняемого файла
set(EXECUTABLE_OUTPUT_PATH bin)

# Установка каталога для объектных файлов
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY obj)

# Дополнительные настройки, если необходимо
# ...

# Добавление тестов, библиотек и т.д., если необходимо
# ...

