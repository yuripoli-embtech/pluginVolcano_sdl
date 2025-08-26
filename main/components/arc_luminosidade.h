#ifndef ARC_LUMINOSIDADE_H
#define ARC_LUMINOSIDADE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * arc_luminosidade(lv_obj_t * tile);

#ifdef __cplusplus
}
#endif

#endif