#ifndef UI_H
#define UI_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

extern lv_obj_t * menu;

extern const lv_font_t * font20;
extern const lv_font_t * font24;
extern const lv_font_t * font30;
extern const lv_font_t * font50;

LV_FONT_DECLARE(exo2_20);
LV_FONT_DECLARE(exo2_24);
LV_FONT_DECLARE(exo2_30);
LV_FONT_DECLARE(exo2_50);

LV_IMAGE_DECLARE(folder_groups_icon);

extern const void * home_icon;
extern const void * return_icon;
extern const void * options_icon;
extern const void * options_icon2;
extern const void * question_icon;
extern const void * ajustes_icon;
extern const void * configs_icon;
extern const void * favs_icon;
extern const void * limpeza_icon;
extern const void * termometrob_icon;
extern const void * termometro_icon;
extern const void * timer_icon;
extern const void * play_icon;
extern const void * dourar_icon;
extern const void * aquecer_icon;
extern const void * alert1_icon;
extern const void * eye_icon;
extern const void * hidePass_icon;
extern const void * preAquec_icon;
extern const void * celsius_icon;
extern const void * editGroup_icon;
extern const void * editRecipes_icon;
extern const void * exportMenu_icon;
extern const void * sac_icon;
extern const void * system_icon;
extern const void * temperature_icon;
extern const void * usb_icon;

extern char temperature_text[10];
extern char timer_text[6];
extern char password[7];
extern char system_hour[6];
extern int minutes;
extern int seconds;
extern int count_groups;

typedef struct {
    int position, icon_idx;
    char name[20];
} groups_data;

extern groups_data recipes_group[64];

void fitLite_init(const char * asset_path);

extern const lv_img_dsc_t *groupIcons[82];
LV_IMAGE_DECLARE(group_1);
/*
LV_IMAGE_DECLARE(group_0);
LV_IMAGE_DECLARE(group_2);
LV_IMAGE_DECLARE(group_3);
LV_IMAGE_DECLARE(group_4);
LV_IMAGE_DECLARE(group_5);
LV_IMAGE_DECLARE(group_6);
LV_IMAGE_DECLARE(group_7);
LV_IMAGE_DECLARE(group_8);
LV_IMAGE_DECLARE(group_9);
LV_IMAGE_DECLARE(group_10);
LV_IMAGE_DECLARE(group_11);
LV_IMAGE_DECLARE(group_12);
LV_IMAGE_DECLARE(group_13);
LV_IMAGE_DECLARE(group_14);
LV_IMAGE_DECLARE(group_15);
LV_IMAGE_DECLARE(group_16);
LV_IMAGE_DECLARE(group_17);
LV_IMAGE_DECLARE(group_18);
LV_IMAGE_DECLARE(group_19);
LV_IMAGE_DECLARE(group_20);
LV_IMAGE_DECLARE(group_21);
LV_IMAGE_DECLARE(group_22);
LV_IMAGE_DECLARE(group_23);
LV_IMAGE_DECLARE(group_24);
LV_IMAGE_DECLARE(group_25);
LV_IMAGE_DECLARE(group_26);
LV_IMAGE_DECLARE(group_27);
LV_IMAGE_DECLARE(group_28);
LV_IMAGE_DECLARE(group_29);
LV_IMAGE_DECLARE(group_30);
LV_IMAGE_DECLARE(group_31);
LV_IMAGE_DECLARE(group_32);
LV_IMAGE_DECLARE(group_33);
LV_IMAGE_DECLARE(group_34);
LV_IMAGE_DECLARE(group_35);
LV_IMAGE_DECLARE(group_36);
LV_IMAGE_DECLARE(group_37);
LV_IMAGE_DECLARE(group_38);
LV_IMAGE_DECLARE(group_39);
LV_IMAGE_DECLARE(group_40);
LV_IMAGE_DECLARE(group_41);
LV_IMAGE_DECLARE(group_42);
LV_IMAGE_DECLARE(group_43);
LV_IMAGE_DECLARE(group_44);
LV_IMAGE_DECLARE(group_45);
LV_IMAGE_DECLARE(group_46);
LV_IMAGE_DECLARE(group_47);
LV_IMAGE_DECLARE(group_48);
LV_IMAGE_DECLARE(group_49);
LV_IMAGE_DECLARE(group_50);
LV_IMAGE_DECLARE(group_51);
LV_IMAGE_DECLARE(group_52);
LV_IMAGE_DECLARE(group_53);
LV_IMAGE_DECLARE(group_54);
LV_IMAGE_DECLARE(group_55);
LV_IMAGE_DECLARE(group_56);
LV_IMAGE_DECLARE(group_57);
LV_IMAGE_DECLARE(group_58);
LV_IMAGE_DECLARE(group_59);
LV_IMAGE_DECLARE(group_60);
LV_IMAGE_DECLARE(group_61);
LV_IMAGE_DECLARE(group_62);
LV_IMAGE_DECLARE(group_63);
LV_IMAGE_DECLARE(group_64);
LV_IMAGE_DECLARE(group_65);
LV_IMAGE_DECLARE(group_66);
LV_IMAGE_DECLARE(group_67);
LV_IMAGE_DECLARE(group_68);
LV_IMAGE_DECLARE(group_69);
LV_IMAGE_DECLARE(group_70);
LV_IMAGE_DECLARE(group_71);
LV_IMAGE_DECLARE(group_72);
LV_IMAGE_DECLARE(group_73);
LV_IMAGE_DECLARE(group_74);
LV_IMAGE_DECLARE(group_75);
LV_IMAGE_DECLARE(group_76);
LV_IMAGE_DECLARE(group_77);
LV_IMAGE_DECLARE(group_78);
LV_IMAGE_DECLARE(group_79);
LV_IMAGE_DECLARE(group_80);*/

#include "screens/menu/inc/menu.h"
#include "components/footer/inc/footer1.h"
#include "components/footer/inc/footer2.h"
#include "components/header/inc/header.h"
#include "components/menuBtns/inc/menuBtns.h"
#include "components/slider/inc/slider.h"
#include "components/init/inc/init.h"
#include "components/keyboard/inc/keyboard.h"
#include "screens/manualMode/inc/manualMode.h"
#include "screens/setTimer/inc/setTimer.h"
#include "screens/setTemp/inc/setTemp.h"
#include "screens/manualMode_load/inc/manualMode_load.h"
#include "screens/configPass/inc/configPass.h"
#include "screens/configMenu/inc/configMenu.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif