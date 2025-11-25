#include "../inc/header.h"
#include "main/inc/ui.h"

lv_obj_t * header_create(lv_obj_t * parent, char * text) 
{
    lv_obj_t * header = lv_obj_create(parent);
    lv_obj_set_width(header, 770);
    lv_obj_set_height(header, 30);
    lv_obj_set_style_bg_color(header, lv_color_black(), 0);
    lv_obj_set_style_border_width(header, 0, 0);
    lv_obj_set_style_margin_left(header, 15, 0);
    lv_obj_set_style_margin_top(header, 15, 0);
    lv_obj_set_style_margin_bottom(header, 5, 0);
    lv_obj_set_style_pad_all(header,0, 0);
    lv_obj_set_flag(header, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_t * time = lv_label_create(header);
    lv_label_set_text(time, system_hour);
    lv_obj_set_style_text_color(time, lv_color_white(), 0);
    lv_obj_set_style_text_font(time, font20, 0);
    lv_obj_align(time, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_t * title = lv_label_create(header);
    lv_label_set_text(title, text);
    lv_obj_set_style_text_color(title, lv_color_white(), 0);
    lv_obj_set_style_text_font(title, font30, 0);
    lv_obj_align(title, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * question = lv_button_create(header);
    lv_obj_set_width(question, 20);
    lv_obj_set_height(question, 20);
    lv_obj_set_style_bg_color(question, lv_color_black(), 0);
    lv_obj_set_style_shadow_width(question, 0, 0);
    lv_obj_align(question, LV_ALIGN_RIGHT_MID, 0, 0);

    lv_obj_t * lv_image_0 = lv_image_create(question);
    lv_image_set_src(lv_image_0, question_icon);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    
    return header;
}   