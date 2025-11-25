#ifndef SETTIMER_H
#define SETTIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * setTimer(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif