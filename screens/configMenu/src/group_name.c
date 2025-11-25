#include "../inc/configMenu.h"
#include "main/inc/ui.h"
#include "stdio.h"


static void event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target_obj(e);
    lv_obj_t * ta = (lv_obj_t *)lv_event_get_user_data(e);
    const char * txt = lv_buttonmatrix_get_button_text(obj, lv_buttonmatrix_get_selected_button(obj));

    if (lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0){
        lv_textarea_delete_char(ta);
    } else if (lv_strcmp(txt, LV_SYMBOL_OK) == 0){
        const char * name = lv_textarea_get_text(ta);
        snprintf(recipes_group[count_groups].name, sizeof(recipes_group[count_groups].name), "%s", name);
        lv_screen_load_anim(group_icon_screen(), LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
    } else if (lv_strcmp(txt, LV_SYMBOL_UP) == 0){

    } else if (lv_strcmp(txt, "abc") == 0){

    } else if (lv_strcmp(txt, "&123") == 0){

    } else {
        lv_textarea_add_text(ta, txt);
    }
}

lv_obj_t * group_name_screen(void)
{   
    static lv_style_t main;
    static lv_style_t btn_style;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&main);
        lv_style_set_pad_all(&main, 0);
        lv_style_set_border_width(&main, 0);
        lv_style_set_radius(&main, 0);
        lv_style_set_pad_row(&main, 0);
        lv_style_set_bg_color(&main, lv_color_black());

         lv_style_init(&btn_style);
        lv_style_set_shadow_width(&btn_style, 0);
        lv_style_set_size(&btn_style, 60, 50);
        lv_style_set_radius(&btn_style, 5);
    }

    lv_obj_t * screen = lv_obj_create(NULL);
    lv_obj_add_style(screen, &main, 0);

    lv_obj_t * keyboard = keyboard_carac(screen);
    lv_obj_t * btnm = lv_obj_get_child(keyboard, 0);
    lv_obj_set_pos(keyboard, 15, 156);

    /* TEXTAREA */
    /*Create the password box*/
    lv_obj_t * ta = lv_textarea_create(screen);
    lv_obj_set_style_bg_color(ta, lv_color_black(), 0);
    if(recipes_group[count_groups].name[0] != '\0') {
        lv_textarea_set_text(ta, recipes_group[count_groups].name);
    } else {
        lv_textarea_set_placeholder_text(ta, "group_name");
        lv_obj_set_style_text_color(ta, lv_color_hex(0x525252), LV_PART_TEXTAREA_PLACEHOLDER);
    }
    lv_obj_set_style_border_width(ta, 0, 0);
    lv_textarea_set_one_line(ta, true);
    lv_obj_set_style_text_color(ta, lv_color_white(), 0);
    lv_obj_set_style_text_font(ta, font30, 0);
    lv_obj_set_size(ta, 770, 85);
    lv_obj_add_state(ta, LV_STATE_FOCUSED);
    lv_textarea_set_max_length(ta, 18);
    lv_obj_set_pos(ta, 15, 50);
    lv_obj_add_event_cb(btnm, event_handler, LV_EVENT_VALUE_CHANGED, ta);

    return screen;
}