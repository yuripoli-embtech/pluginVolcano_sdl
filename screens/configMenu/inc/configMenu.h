#ifndef CONFIGMENU_H
#define CONFIGMENU_H
#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * configMenu_screen(void);
lv_obj_t * groups_screen(int type);
lv_obj_t * edit_groups(int pos);
lv_obj_t * new_group_screen(void);
lv_obj_t * group_name_screen(void);
lv_obj_t * keyboard_carac(lv_obj_t * screen);
lv_obj_t * group_icon_screen(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif