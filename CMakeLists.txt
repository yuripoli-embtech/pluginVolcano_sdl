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
    ${PROJECT_SOURCE_DIR}/main/src/main.c
    ${PROJECT_SOURCE_DIR}/main/src/mouse_cursor_icon.c
    ${PROJECT_SOURCE_DIR}/main/src/ui.c
    ${PROJECT_SOURCE_DIR}/screens/menu/src/menu.c
    ${PROJECT_SOURCE_DIR}/screens/manualMode/src/manualMode.c
    ${PROJECT_SOURCE_DIR}/screens/setTimer/src/setTimer.c
    ${PROJECT_SOURCE_DIR}/screens/setTemp/src/setTemp.c
    ${PROJECT_SOURCE_DIR}/screens/manualMode_load/src/manualMode_load.c
    ${PROJECT_SOURCE_DIR}/screens/configPass/src/configPass.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/configMenu.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/groups.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/new_group.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/edit_groups.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/group_name.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/group_icon.c
    ${PROJECT_SOURCE_DIR}/screens/configMenu/src/keyboard_carac.c
    ${PROJECT_SOURCE_DIR}/components/footer/src/footer1.c
    ${PROJECT_SOURCE_DIR}/components/footer/src/footer2.c
    ${PROJECT_SOURCE_DIR}/components/header/src/header.c
    ${PROJECT_SOURCE_DIR}/components/menuBtns/src/menuBtns.c
    ${PROJECT_SOURCE_DIR}/components/slider/src/slider.c
    ${PROJECT_SOURCE_DIR}/components/init/src/init.c
    ${PROJECT_SOURCE_DIR}/components/keyboard/src/keyboard.c
    ${PROJECT_SOURCE_DIR}/images/Home.c
    ${PROJECT_SOURCE_DIR}/images/Options.c
    ${PROJECT_SOURCE_DIR}/images/options2.c
    ${PROJECT_SOURCE_DIR}/images/Img_return.c
    ${PROJECT_SOURCE_DIR}/images/question.c
    ${PROJECT_SOURCE_DIR}/images/ajustes.c
    ${PROJECT_SOURCE_DIR}/images/configs.c
    ${PROJECT_SOURCE_DIR}/images/favs.c
    ${PROJECT_SOURCE_DIR}/images/limpeza.c
    ${PROJECT_SOURCE_DIR}/images/TermometroB.c
    ${PROJECT_SOURCE_DIR}/images/termometro.c
    ${PROJECT_SOURCE_DIR}/images/group_1.c
    ${PROJECT_SOURCE_DIR}/images/play.c
    ${PROJECT_SOURCE_DIR}/images/timer.c
    ${PROJECT_SOURCE_DIR}/images/dourar.c
    ${PROJECT_SOURCE_DIR}/images/aquecer.c
    ${PROJECT_SOURCE_DIR}/images/eye.c
    ${PROJECT_SOURCE_DIR}/images/aquec.c
    ${PROJECT_SOURCE_DIR}/images/celsius.c
    ${PROJECT_SOURCE_DIR}/images/editGroup.c
    ${PROJECT_SOURCE_DIR}/images/editRecipes.c
    ${PROJECT_SOURCE_DIR}/images/exportMenu.c
    ${PROJECT_SOURCE_DIR}/images/sac.c
    ${PROJECT_SOURCE_DIR}/images/system.c
    ${PROJECT_SOURCE_DIR}/images/temperature.c
    ${PROJECT_SOURCE_DIR}/images/USB.c
    ${PROJECT_SOURCE_DIR}/images/HidePass.c
    ${PROJECT_SOURCE_DIR}/images/folder_groups_icon.c
    ${PROJECT_SOURCE_DIR}/images/new_icon.c
    ${PROJECT_SOURCE_DIR}/images/alert1.c
    ${PROJECT_SOURCE_DIR}/fonts/exo2_20.c
    ${PROJECT_SOURCE_DIR}/fonts/exo2_24.c
    ${PROJECT_SOURCE_DIR}/fonts/exo2_30.c
    ${PROJECT_SOURCE_DIR}/fonts/exo2_50.c
)

target_compile_definitions(main PRIVATE LV_CONF_INCLUDE_SIMPLE)

target_link_libraries(main lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} m pthread)
