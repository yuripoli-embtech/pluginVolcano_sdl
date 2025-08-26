/**
 * @file refrigerador_gen.h
 */

#ifndef REFRIGERADOR_GEN_H
#define REFRIGERADOR_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/



/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/
extern lv_obj_t * principal;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/
extern const lv_font_t * font_large;
extern const lv_font_t * font_normal;


/*----------------
 * Images
 *----------------*/
extern const void * plugin1;
extern const void * plugin2;
extern const void * embtech;
extern const void * volcano_img1;
extern const void * volcano_img2;
extern const void * thermometer;
extern const void * humidity;

/*----------------
 * Subjects
 *----------------*/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void refrigerador_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "screens/principal/principal_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif