#include "../inc/init.h"
#include "main/inc/ui.h"

lv_obj_t * init_create(lv_obj_t * parent)
{
    static lv_style_t btns;

    lv_style_init(&btns);
    lv_style_set_bg_color(&btns, lv_color_hex(0xD1D2D4));
    lv_style_set_shadow_width(&btns, 0);
    lv_style_set_size(&btns, 160, 100);
    lv_style_set_text_color(&btns, lv_color_black());
    lv_style_set_text_font(&btns, font50);
    lv_style_set_pad_all(&btns, 0);
    lv_style_set_radius(&btns, 23);

    lv_obj_t * init = lv_obj_create(parent);
    lv_obj_set_flag(init, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(init, LV_FLEX_FLOW_ROW);
    lv_obj_set_width(init, 760);
    lv_obj_set_height(init, 170);
    lv_obj_set_style_margin_left(init, 20, 0);
    lv_obj_set_style_bg_color(init, lv_color_black(), 0);
    lv_obj_set_style_pad_all(init, 30, 0);
    lv_obj_set_style_border_width(init, 0, 0);
    lv_obj_set_style_pad_gap(init, 0, 0);
    lv_obj_set_flex_align(init, LV_FLEX_ALIGN_SPACE_BETWEEN, 0, 0);

    lv_obj_t * btn_temp = lv_button_create(init);
    lv_obj_add_style(btn_temp, &btns, 0);
    lv_obj_t * label_temp = lv_label_create(btn_temp);
    lv_label_set_text(label_temp, temperature_text);
    lv_obj_set_align(label_temp, LV_ALIGN_CENTER);
    lv_obj_add_screen_create_event(btn_temp, LV_EVENT_CLICKED, setTemp, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

    lv_obj_t * icon_temp = lv_image_create(init);
    lv_image_set_src(icon_temp, termometro_icon);
    lv_obj_set_height(icon_temp, 100);

    lv_obj_t * btn_start = lv_button_create(init);
    lv_obj_set_size(btn_start, 100, 100);
    lv_obj_set_style_shadow_width(btn_start, 0, 0);
    lv_obj_set_style_radius(btn_start, 23, 0);
    lv_obj_set_style_bg_color(btn_start, lv_color_hex(0x06A24A), 0);
    lv_obj_t * icon_play = lv_image_create(btn_start);
    lv_image_set_src(icon_play, play_icon);
    lv_obj_center(icon_play);
    lv_obj_add_screen_create_event(btn_start, LV_EVENT_CLICKED, manualModeLoad_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

    lv_obj_t * icon_timer = lv_image_create(init);
    lv_image_set_src(icon_timer, timer_icon);
    lv_obj_set_height(icon_timer, 100);

    lv_obj_t * btn_timer = lv_button_create(init);
    lv_obj_add_style(btn_timer, &btns, 0);
    lv_obj_t * label_timer = lv_label_create(btn_timer);
    lv_label_set_text(label_timer, timer_text);
    lv_obj_set_align(label_timer, LV_ALIGN_CENTER);
    lv_obj_add_screen_create_event(btn_timer, LV_EVENT_CLICKED, setTimer, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
}