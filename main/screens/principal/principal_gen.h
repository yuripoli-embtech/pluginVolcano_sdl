/**
 * @file principal_gen.h
 */

#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "../../lvgl/lvgl.h"
#endif

lv_obj_t * principal_create(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PRINCIPAL_H*/