#include "../inc/configPass.h"
#include "main/inc/ui.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void event_handler(lv_event_t * e);
static void show_pass(lv_event_t * e);
const char * txt_pass;

lv_obj_t * configPass_screen(void){
    
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
    header_create(lv_obj_0, "CONFIGURAÇÕES");

    /* SCREEN */
    lv_obj_t * principal = lv_obj_create(lv_obj_0);
    lv_obj_set_flag(principal, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_size(principal, 770, 350);
    lv_obj_set_style_margin_left(principal, 15, 0);
    lv_obj_set_style_bg_color(principal, lv_color_black(), 0);
    lv_obj_set_style_pad_all(principal, 0, 0);
    lv_obj_set_style_border_width(principal, 0, 0);

    lv_obj_t * title = lv_label_create(principal);
    lv_label_set_text(title, "PARA ACESSAR AS CONFIGURAÇÕES, INFORME SUA SENHA");
    lv_obj_set_style_text_font(title, font24, 0);
    lv_obj_set_style_text_color(title, lv_color_white(), 0);
    lv_obj_set_width(title, 420);
    lv_obj_set_style_pad_top(title, 15, 0); 

    /* NUMERIC KEYBOARD */
    lv_obj_t * keyboard = keyboard_create(principal);
    lv_obj_t * btnm = lv_obj_get_child(keyboard, 0);
    lv_obj_align(keyboard, LV_ALIGN_RIGHT_MID, 0, 0);

    /* TEXTAREA */
    /*Create the password box*/
    lv_obj_t * ta = lv_textarea_create(principal);
    lv_textarea_set_text(ta, "");
    lv_textarea_set_password_mode(ta, true);
    lv_textarea_set_one_line(ta, true);
    lv_obj_set_width(ta, 250);
    lv_obj_align(ta, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_add_event_cb(btnm, event_handler, LV_EVENT_VALUE_CHANGED, ta);
    lv_obj_add_state(ta, LV_STATE_FOCUSED);
    lv_textarea_set_max_length(ta, 6);

    /*Create a label and position it above the text box*/
    lv_obj_t * pwd_label = lv_label_create(principal);
    lv_label_set_text(pwd_label, "SENHA:");
    lv_obj_align_to(pwd_label, ta, LV_ALIGN_OUT_TOP_LEFT, 0, -15);
    lv_obj_set_style_text_font(pwd_label, font24, 0);
    lv_obj_set_style_text_color(pwd_label, lv_color_white(), 0);

    /* SHOW PASSWORD */
    lv_obj_t * btn = lv_button_create(principal);
    lv_obj_align_to(btn, ta, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 2);
    lv_obj_set_style_bg_color(btn, lv_color_black(), 0);
    lv_obj_set_style_pad_all(btn, 0, 0);
    lv_obj_set_size(btn, 185, 30);
    lv_obj_set_style_shadow_width(btn, 0, 0);
    lv_obj_t * showpwd_label = lv_label_create(btn);
    lv_label_set_text(showpwd_label, "Mostrar senha");
    lv_obj_set_style_text_font(showpwd_label, font24, 0);
    lv_obj_set_style_text_color(showpwd_label, lv_color_white(), 0);
    lv_obj_t * img = lv_image_create(btn);
    lv_image_set_src(img, eye_icon);
    lv_obj_set_height(img, 30);
    lv_obj_align(img, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_add_event_cb(btn, show_pass, LV_EVENT_CLICKED, ta);

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
        txt_pass = lv_textarea_get_text(ta);
        if (strcmp(txt_pass, password) == 0)
        {
            lv_obj_add_screen_create_event(obj, LV_EVENT_CLICKED, configMenu_screen, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);
        } else {
            lv_textarea_set_text(ta, "");
        }
        
    } else {
        lv_textarea_add_text(ta, txt);
    }
}

static void show_pass(lv_event_t * e){
    lv_obj_t * btn = lv_event_get_target_obj(e);
    lv_obj_t * ta = (lv_obj_t *)lv_event_get_user_data(e);

    // alterna entre mostrar e ocultar
    static bool pass_mode = true;
    pass_mode = !pass_mode;
    lv_textarea_set_password_mode(ta, pass_mode);

    lv_obj_t * label = lv_obj_get_child(btn, 0);
    lv_obj_t * img = lv_obj_get_child(btn, 1);

    if(!pass_mode){
        lv_label_set_text(label, "Ocultar senha");
        lv_image_set_src(img, hidePass_icon);
    } else {
        lv_label_set_text(label, "Mostrar senha");
        lv_image_set_src(img, eye_icon);
    }
}