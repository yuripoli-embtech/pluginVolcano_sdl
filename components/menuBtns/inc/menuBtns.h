#ifndef MENUBTNS_h
#define MENUBTNS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * menuBtns_create(lv_obj_t * parent, char * text, const void * img, uint32_t color);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif