#include "../inc/manualMode.h"
#include "main/inc/ui.h"

lv_obj_t * manualMode_screen(void) {

    static lv_style_t main;

    lv_style_init(&main);
    lv_style_set_pad_all(&main, 0);
    lv_style_set_border_width(&main, 0);
    lv_style_set_radius(&main, 0);
    lv_style_set_layout(&main, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(&main, LV_FLEX_FLOW_COLUMN);
    lv_style_set_pad_row(&main, 0);
    lv_style_set_bg_color(&main, lv_color_black());

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_0, &main, 0);

    /* HEADER */
    lv_obj_t * header = header_create(lv_obj_0, "MODO MANUAL");

    /* SLIDERS */
    slider_create(lv_obj_0);

    /* SET TEMP & TIMER and START */
    init_create(lv_obj_0);

    /* FOOTER */
    footer2_create(lv_obj_0);

    return lv_obj_0;
}
