#ifndef CHARTS_H
#define CHARTS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * chart_screen(lv_obj_t * tab);

#ifdef __cplusplus
}
#endif

#endif