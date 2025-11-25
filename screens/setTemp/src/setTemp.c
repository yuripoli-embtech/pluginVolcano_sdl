#include "../inc/setTemp.h"
#include "main/inc/ui.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void event_handler(lv_event_t * e);
static void ta_event_cb(lv_event_t * e);

lv_obj_t * setTemp(void)
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

    lv_obj_t * icon_temp = lv_image_create(timer);
    lv_image_set_src(icon_temp, termometro_icon);
    lv_obj_set_height(icon_temp, 100);

    lv_obj_t * ta_temp = lv_textarea_create(timer);
    lv_textarea_set_one_line(ta_temp, true);
    lv_obj_set_style_bg_color(ta_temp, lv_color_hex(0xD1D2D4), 0);
    lv_obj_set_flag(ta_temp, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_size(ta_temp, 160, 100);
    lv_obj_set_style_radius(ta_temp, 23, 0);
    lv_obj_set_style_text_font(ta_temp, font50, 0);
    lv_textarea_add_text(ta_temp, "°C");
    lv_textarea_set_cursor_pos(ta_temp, 0);
    lv_obj_set_style_text_align(ta_temp, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_event_cb(btnm, event_handler, LV_EVENT_VALUE_CHANGED, ta_temp);
    lv_obj_set_flag(ta_temp, LV_OBJ_FLAG_CLICKABLE, false); 
    lv_textarea_set_max_length(ta_temp, 5);
    lv_obj_add_state(ta_temp, LV_STATE_FOCUSED);

    /* FOOTER */
    footer2_create(lv_obj_0);

    return lv_obj_0;
}

static void event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target_obj(e);
    lv_obj_t * ta_temp = (lv_obj_t *)lv_event_get_user_data(e);
    const char * txt = lv_buttonmatrix_get_button_text(obj, lv_buttonmatrix_get_selected_button(obj));
    const char * current = lv_textarea_get_text(ta_temp);

    if (lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        lv_textarea_delete_char(ta_temp);
    } else if (lv_strcmp(txt, LV_SYMBOL_OK) == 0) {
        if(strcmp(current, "°C") == 0) {
            snprintf(temperature_text, sizeof(temperature_text), "%d°C", 200);
        } else {
            char buffer[4];
            strncpy(buffer, current, sizeof(buffer));
            buffer[sizeof(buffer)-1] = '\0';
            char *end = strstr(buffer, "°C");
            if (end)
            {
                *end = '\0';
            }  

            int value = atoi(buffer); 
            snprintf(temperature_text, sizeof(temperature_text), "%d°C", value);
        }
        lv_obj_add_screen_create_event(obj, LV_EVENT_CLICKED, manualMode_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
    } else {
        lv_textarea_add_text(ta_temp, txt);
    }
}
