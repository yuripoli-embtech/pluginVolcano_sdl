#include "../inc/footer1.h"
#include "main/inc/ui.h"

lv_obj_t * footer1_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * footer = lv_obj_create(parent);
    lv_obj_set_width(footer, 770);
    lv_obj_set_height(footer, 65);
    lv_obj_set_style_border_width(footer, 0, 0);
    lv_obj_set_style_bg_color(footer, lv_color_hex(0xD1D2D4), 0);
    lv_obj_set_style_margin_left(footer, 15, 0);
    lv_obj_set_style_radius(footer, 16, 0);
    lv_obj_set_style_pad_top(footer, 8, 0);
    lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flag(footer, LV_OBJ_FLAG_SCROLLABLE, false);

    //btn return
    lv_obj_t * btn_return = lv_button_create(footer);
    lv_obj_set_style_bg_color(btn_return, lv_color_hex(0xD1D2D4), 0);
    lv_obj_set_style_radius(btn_return, 16, 0);
    lv_obj_set_width(btn_return, 65);
    lv_obj_set_height(btn_return, 50);
    lv_obj_set_style_margin_left(btn_return, 59, 0);
    lv_obj_set_style_shadow_width(btn_return, 0, 0);

    lv_obj_t * lv_image_0 = lv_image_create(btn_return);
    lv_image_set_src(lv_image_0, return_icon);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);

    lv_obj_t * btn_home = lv_button_create(footer);
    lv_obj_set_style_bg_color(btn_home, lv_color_hex(0xD1D2D4), 0);
    lv_obj_set_style_radius(btn_home, 16, 0);
    lv_obj_set_width(btn_home, 65);
    lv_obj_set_height(btn_home, 50);
    lv_obj_set_style_margin_left(btn_home, 133, 0);
    lv_obj_set_style_shadow_width(btn_home, 0, 0);

    lv_obj_t * lv_image_1 = lv_image_create(btn_home);
    lv_image_set_src(lv_image_1, home_icon);
    lv_obj_set_align(lv_image_1, LV_ALIGN_CENTER);

    lv_obj_t * btn_options = lv_button_create(footer);
    lv_obj_set_style_bg_color(btn_options, lv_color_hex(0xD1D2D4), 0);
    lv_obj_set_style_radius(btn_options, 16, 0);
    lv_obj_set_width(btn_options, 65);
    lv_obj_set_height(btn_options, 50);
    lv_obj_set_style_margin_left(btn_options, 133, 0);
    lv_obj_set_style_shadow_width(btn_options, 0, 0);

    lv_obj_t * lv_image_2 = lv_image_create(btn_options);
    lv_image_set_src(lv_image_2, options_icon);
    lv_obj_set_align(lv_image_2, LV_ALIGN_CENTER);
  
    return footer;
}

