#include "ui.h"
#include <stdio.h>

lv_obj_t * menu;
    
const lv_font_t * font20;
const lv_font_t * font24;
const lv_font_t * font30;
const lv_font_t * font50;

const void * home_icon;
extern const void * Home;
const void * return_icon;
extern const void * Img_return;
const void * options_icon;
extern const void * Options;
const void * question_icon;
extern const void * question;
const void * ajustes_icon;
extern const void * ajustes;
const void * configs_icon;
extern const void * configs;
const void * favs_icon;
extern const void * favs;
const void * limpeza_icon;
extern const void * limpeza;
const void * termometrob_icon;
extern const void * TermometroB;
const void * termometro_icon;
extern const void * termometro;
const void * timer_icon;
extern const void * timer;
const void * play_icon;
extern const void play;
const void * dourar_icon;
extern const void dourar;
const void * aquecer_icon;
extern const void aquecer;
const void * alert1_icon;
extern const void alert1;
const void * options_icon2;
extern const void options2;
const void * eye_icon;
extern const void * eye;
const void * hidePass_icon;
extern const void HidePass;
const void * preAquec_icon;
extern const void aquec;
const void * celsius_icon;
extern const void celsius;
const void * editGroup_icon;
extern const void editGroup;
const void * editRecipes_icon;
extern const void editRecipes;
const void * exportMenu_icon;
extern const void exportMenu;
const void * sac_icon;
extern const void sac;
const void * system_icon;
extern const void system;
const void * temperature_icon;
extern const void temperature;
const void * usb_icon;
extern const void USB;

char temperature_text[10];
char timer_text[6];
char password[7];
char system_hour[6];
int minutes;
int seconds;
int count_groups;

groups_data recipes_group[64];

const lv_img_dsc_t *groupIcons[82] = {
    &group_1,
};


void fitLite_init(const char * asset_path)
{

    font20 = &exo2_20;
    font24 = &exo2_24;
    font30 = &exo2_30;
    font50 = &exo2_50;

    home_icon = &Home;
    return_icon = &Img_return;
    options_icon = &Options;
    question_icon = &question;
    ajustes_icon = &ajustes;
    configs_icon = &configs;
    favs_icon = &favs;
    limpeza_icon = &limpeza;
    termometrob_icon = &TermometroB;
    termometro_icon = &termometro;
    timer_icon = &timer;
    play_icon = &play;
    dourar_icon = &dourar;
    aquecer_icon = &aquecer;
    alert1_icon = &alert1;
    options_icon2 = &options2;
    eye_icon = &eye;
    hidePass_icon = &HidePass;
    preAquec_icon = &aquec;
    celsius_icon = &celsius;
    editGroup_icon = &editGroup;
    editRecipes_icon = &editRecipes;
    exportMenu_icon = &exportMenu;
    sac_icon = &sac;
    system_icon = &system;
    temperature_icon = &temperature;
    usb_icon = &USB;

    minutes = 0;
    seconds = 0;
    count_groups = 0;
        
    snprintf(temperature_text, sizeof(temperature_text), "%d°C", 200);
    snprintf(timer_text, sizeof(timer_text), "%02d:%02d", 0, 0);
    snprintf(password, sizeof(password), "%s", "456789");
    snprintf(system_hour, sizeof(system_hour), "%02d:%02d", 10, 26);

    menu = menu_create();
    lv_screen_load(menu);
}
