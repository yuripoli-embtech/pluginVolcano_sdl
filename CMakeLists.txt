cmake_minimum_required(VERSION 3.12.4)
project(lvgl C CXX)

include_directories(${PROJECT_SOURCE_DIR}/main/inc)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)

add_subdirectory(lvgl)
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})

add_executable(main
    ${PROJECT_SOURCE_DIR}/main/main.c
    ${PROJECT_SOURCE_DIR}/main/mouse_cursor_icon.c
    ${PROJECT_SOURCE_DIR}/main/ui.c
    ${PROJECT_SOURCE_DIR}/main/screens/principal/principal_gen.c
    ${PROJECT_SOURCE_DIR}/main/pages/charts.c
    ${PROJECT_SOURCE_DIR}/main/pages/plugin.c
    ${PROJECT_SOURCE_DIR}/main/pages/volcano.c
    ${PROJECT_SOURCE_DIR}/main/images/plugin_img1.c
    ${PROJECT_SOURCE_DIR}/main/images/plugin_img2.c
    ${PROJECT_SOURCE_DIR}/main/images/embtech_img.c
    ${PROJECT_SOURCE_DIR}/main/images/volcano1.c
    ${PROJECT_SOURCE_DIR}/main/images/volcano2.c
    ${PROJECT_SOURCE_DIR}/main/images/thermometer_data.c
    ${PROJECT_SOURCE_DIR}/main/components/thermometer.c
    ${PROJECT_SOURCE_DIR}/main/components/humidity.c
    ${PROJECT_SOURCE_DIR}/main/images/humidity_icon.c
    ${PROJECT_SOURCE_DIR}/main/components/arc_humidity.c
    ${PROJECT_SOURCE_DIR}/main/components/arc_luminosidade.c
    ${PROJECT_SOURCE_DIR}/main/components/chart_temperatura.c
)

target_compile_definitions(main PRIVATE LV_CONF_INCLUDE_SIMPLE)

target_link_libraries(main lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} m pthread)
