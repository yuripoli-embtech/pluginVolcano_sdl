#ifndef CHART_TEMPERATURA_H
#define CHART_TEMPERATURA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * chart_temperatura(lv_obj_t * tile);

#ifdef __cplusplus
}
#endif

#endif