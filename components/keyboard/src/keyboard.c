#include "../inc/keyboard.h"
#include "main/inc/ui.h"

static void event_handler(lv_event_t * e);

static const char * btnm_map[] = {
    "1","2","3","\n",
    "4","5","6","\n",
    "7","8","9","\n",
    LV_SYMBOL_BACKSPACE,"0",LV_SYMBOL_OK,""
};

lv_obj_t * keyboard_create(lv_obj_t * parent) {

    static lv_style_t style_btn_bg;
    static lv_style_t bg_checked;

    lv_style_init(&style_btn_bg);
    lv_style_set_bg_color(&style_btn_bg, lv_color_hex(0x383533));
    lv_style_set_text_color(&style_btn_bg, lv_color_white());
    lv_style_set_shadow_width(&style_btn_bg, 0);

    lv_style_init(&bg_checked);
    lv_style_set_bg_color(&bg_checked, lv_color_hex(0x23211E));

    /* NUMERIC KEYBOARD */
    lv_obj_t * keyboard = lv_obj_create(parent);
    lv_obj_set_size(keyboard, 320, 350);
    lv_obj_set_flag(keyboard, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(keyboard, lv_color_black(), 0);
    lv_obj_set_style_border_width(keyboard, 0, 0);

    lv_obj_t * btnm1 = lv_buttonmatrix_create(keyboard);
    lv_buttonmatrix_set_map(btnm1, btnm_map);
    lv_obj_set_size(btnm1, 320, 350);
    lv_obj_set_style_bg_color(btnm1, lv_color_black(), 0);
    lv_obj_set_style_border_width(btnm1, 0, 0);
    lv_buttonmatrix_set_button_ctrl(btnm1, 9, LV_BUTTONMATRIX_CTRL_CHECKED);
    lv_buttonmatrix_set_button_ctrl(btnm1, 11, LV_BUTTONMATRIX_CTRL_CHECKED);
    lv_obj_align(btnm1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(btnm1, &style_btn_bg, LV_PART_ITEMS);
    lv_obj_add_style(btnm1, &bg_checked, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_text_font(btnm1, &lv_font_montserrat_24, LV_PART_ITEMS);

    return keyboard;
}