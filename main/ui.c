/**
 * @file refrigerador_gen.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "ui.h"

#if LV_USE_XML
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/
lv_obj_t * principal;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/
const lv_font_t * font_large;
const lv_font_t * font_normal;


/*----------------
 * Images
 *----------------*/
const void * plugin1;
extern const void * plugin_img1;
const void * embtech;
extern const void * embtech_img;
const void * plugin2;
extern const void * plugin_img2;
const void * volcano_img1;
extern const void * volcano1;
const void * volcano_img2;
extern const void * volcano2;
const void * thermometer;
extern const void * thermometer_data;
const void * humidity;
extern const void * humidity_icon;

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void refrigerador_init_gen(const char * asset_path)
{
    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/

    /*----------------
     * Images
     *----------------*/
    plugin1 = &plugin_img1;
    plugin2 = &plugin_img2;
    volcano_img1 = &volcano1;
    volcano_img2 = &volcano2;
    embtech = &embtech_img;
    thermometer = &thermometer_data;
    humidity = &humidity_icon;

    font_large = &lv_font_montserrat_20;
    font_normal = &lv_font_montserrat_16;

    principal = principal_create();
}

/* callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/