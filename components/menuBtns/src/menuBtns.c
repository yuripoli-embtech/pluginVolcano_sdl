#include "../inc/menuBtns.h"
#include "main/inc/ui.h"
#include <string.h>

lv_obj_t * menuBtns_create(lv_obj_t * parent, char * text, const void* img, uint32_t color) 
{
    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_width(lv_obj_0, 194);
    lv_obj_set_height(lv_obj_0, 159);
    lv_obj_set_style_pad_all(lv_obj_0, 0, 0);
    lv_obj_set_style_pad_top(lv_obj_0, 2, 0);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_layout(lv_obj_0, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_COLUMN);
    lv_obj_set_style_bg_color(lv_obj_0, lv_color_black(), 0);
    lv_obj_set_style_pad_row(lv_obj_0, 3, 0); 
    lv_obj_set_style_border_width(lv_obj_0, 0, 0);

    lv_obj_t * btn = lv_button_create(lv_obj_0);
    lv_obj_set_width(btn, 100);
    lv_obj_set_height(btn, 100);
    lv_obj_set_style_bg_color(btn, lv_color_hex(color), 0);
    lv_obj_set_style_shadow_width(btn, 0, 0);
    lv_obj_set_style_margin_left(btn, 45, 0);
    lv_obj_set_style_radius(btn, 23, 0);

    lv_obj_t * icon = lv_image_create(btn);    
    lv_image_set_src(icon, img);
    lv_obj_set_align(icon, LV_ALIGN_CENTER);

    lv_obj_t * label = lv_label_create(lv_obj_0);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label, strcmp(text, "MODO MANUAL") == 0 ? 160 : 190);
    lv_label_set_text(label, text);
    lv_obj_set_style_pad_left(label, strcmp(text, "MODO MANUAL") == 0 ? 32 : 2, 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_style_text_font(label, font24, 0);

    return btn;
}