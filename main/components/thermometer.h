#ifndef THERMOMETER_H
#define THERMOMETER_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * thermometer_comp(lv_obj_t * tile);

#ifdef __cplusplus
}
#endif

#endif