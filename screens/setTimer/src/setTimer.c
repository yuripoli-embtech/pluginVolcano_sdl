#include "../inc/setTimer.h"
#include "main/inc/ui.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char * txt_timer;

static void event_handler(lv_event_t * e);
static void ta_event_cb(lv_event_t * e);

lv_obj_t * setTimer(void)
{
    /* STYLES */
    static lv_style_t main;
    static lv_style_t style_btn_bg;
    static lv_style_t bg_checked;

    lv_style_init(&main);
    lv_style_set_pad_all(&main, 0);
    lv_style_set_border_width(&main, 0);
    lv_style_set_radius(&main, 0);
    lv_style_set_layout(&main, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(&main, LV_FLEX_FLOW_COLUMN);
    lv_style_set_pad_row(&main, 0);
    lv_style_set_bg_color(&main, lv_color_black());

    lv_style_init(&style_btn_bg);
    lv_style_set_bg_color(&style_btn_bg, lv_color_hex(0x383533));
    lv_style_set_text_color(&style_btn_bg, lv_color_white());
    lv_style_set_shadow_width(&style_btn_bg, 0);

    lv_style_init(&bg_checked);
    lv_style_set_bg_color(&bg_checked, lv_color_hex(0x23211E));

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_0, &main, 0);

    /* HEADER */
    header_create(lv_obj_0, "");

    /*PRINCIPAL SCREEN DIV*/
    lv_obj_t * principal = lv_obj_create(lv_obj_0);
    lv_obj_set_flag(principal, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(principal, LV_FLEX_FLOW_ROW);
    lv_obj_set_size(principal, 770, 350);
    lv_obj_set_style_margin_left(principal, 15, 0);
    lv_obj_set_style_bg_color(principal, lv_color_black(), 0);
    lv_obj_set_style_pad_all(principal, 0, 0);
    lv_obj_set_style_border_width(principal, 0, 0);
    lv_obj_set_style_pad_column(principal, 0, 0);

    /* NUMERIC KEYBOARD */
    lv_obj_t * keyboard = keyboard_create(principal);
    lv_obj_t * btnm = lv_obj_get_child(keyboard, 0);

    /* TIMER TEXTAREA */
    lv_obj_t * timer = lv_obj_create(principal);
    lv_obj_set_size(timer, 450, 350);
    lv_obj_set_style_border_width(timer, 0, 0);
    lv_obj_set_style_bg_color(timer, lv_color_black(), 0);
    lv_obj_set_style_pad_all(timer, 0, 0);
    lv_obj_set_flex_flow(timer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(timer, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_gap(timer, 60, 0);

    lv_obj_t * icon_timer = lv_image_create(timer);
    lv_image_set_src(icon_timer, timer_icon);
    lv_obj_set_height(icon_timer, 100);

    lv_obj_t * ta = lv_textarea_create(timer);
    lv_textarea_set_one_line(ta, true);
    lv_obj_set_style_bg_color(ta, lv_color_hex(0xD1D2D4), 0);
    lv_obj_set_flag(ta, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_size(ta, 160, 100);
    lv_obj_set_style_radius(ta, 23, 0);
    lv_obj_set_style_text_font(ta, font50, 0);
    lv_obj_add_event_cb(ta, ta_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_textarea_add_text(ta, ":");
    lv_textarea_set_cursor_pos(ta, 0);
    lv_obj_set_style_text_align(ta, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_event_cb(btnm, event_handler, LV_EVENT_VALUE_CHANGED, ta);
    lv_obj_set_flag(ta, LV_OBJ_FLAG_CLICKABLE, false); 
    lv_textarea_set_max_length(ta, 5);

    /* FOOTER */
    footer2_create(lv_obj_0);

    return lv_obj_0;
}

static void event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target_obj(e);
    lv_obj_t * ta = (lv_obj_t *)lv_event_get_user_data(e);
    const char * txt = lv_buttonmatrix_get_button_text(obj, lv_buttonmatrix_get_selected_button(obj));

    if (lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0){
        lv_textarea_delete_char(ta);
    } else if (lv_strcmp(txt, LV_SYMBOL_OK) == 0){
        char min[3], sec[3];
        int time;
        int minutes_display;
        int seconds_display;

        if (strlen(txt_timer) >= 2) {
            memcpy(min, txt_timer, 2);
            min[2] = '\0';
            minutes = atoi(min);
        } else {
            minutes = 0;
        }

        if (strlen(txt_timer) >= 5) {
            memcpy(sec, txt_timer + 3, 2);
            sec[2] = '\0';
            seconds = atoi(sec);
        } else {
            seconds = 0;
        }
        
        time = (minutes*60)+seconds;
        minutes_display = time / 60;
        seconds_display = time % 60;

        if(time > 300){
            snprintf(timer_text, sizeof(timer_text), "%02d:%02d", 5, 0);
            minutes = 5;
            seconds = 0;
        } else {
            snprintf(timer_text, sizeof(timer_text), "%02d:%02d", minutes_display, seconds_display);
        }

        lv_obj_add_screen_create_event(obj, LV_EVENT_CLICKED, manualMode_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
    } else {
        lv_textarea_add_text(ta, txt);
    }
}

static void ta_event_cb(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target_obj(e);
    txt_timer = lv_textarea_get_text(ta);
    size_t len = strlen(txt_timer);
    static bool ta_updating = false;
    lv_obj_add_state(ta, LV_STATE_FOCUSED);

    if(ta_updating) return;
    ta_updating = true;

    if (len == 2 && txt_timer[0] >= '0' && txt_timer[0] <= '9' && txt_timer[1] >= '0' && txt_timer[1] <= '9'){
        if(txt_timer[2] != ':') {
            lv_textarea_add_char(ta, ':'); 
            lv_textarea_set_cursor_pos(ta, 2);
            lv_textarea_delete_char(ta);
        }
    } else if(len == 3 && txt_timer[2] == ':') {
        lv_textarea_set_cursor_pos(ta, 3);
    }

    ta_updating = false;
}