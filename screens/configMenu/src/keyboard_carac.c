#include "../inc/configMenu.h"
#include "main/inc/ui.h"

static const char * const kb_map_characters[] = {"q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n",
                                                 " ", "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_OK, "\n",
                                                 LV_SYMBOL_UP ,"z", "x", "c", "v", "b", "n", "m", ".", ",", LV_SYMBOL_UP, "\n",
                                                 "&123", " ", "'", ""
                                                };

static const char * const kb_map_uppercase[] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n",
                                                " ", "A", "S", "D", "F", "G", "H", "J", "K", "L", LV_SYMBOL_OK, "\n",
                                                LV_SYMBOL_UP ,"Z", "X", "C", "V", "B", "N", "M", ".", ",", LV_SYMBOL_UP, "\n",
                                                "&123", " ", "'", ""
                                               };

static const char * const default_kb_map_spec[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
                                                    " ", "+", "&", "/", "*", "=", "%", "!", "?", "#", LV_SYMBOL_OK, "\n",
                                                   "\\", "@", "$", "(", ")", "{", "}", "[", "]", ";", "\"", "\n",
                                                   "abc", " ", LV_SYMBOL_OK, ""
                                                  };

                                            
/* Este é o seu mapa de controle para letras (você já tem) */
static const lv_buttonmatrix_ctrl_t kb_ctrl_characters[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 4,
    LV_BUTTONMATRIX_CTRL_HIDDEN | 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    LV_BUTTONMATRIX_CTRL_CHECKED | 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 4,
    LV_BUTTONMATRIX_CTRL_CHECKED | 2, 6, 2
};

static const lv_buttonmatrix_ctrl_t kb_ctrl_spc[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 4,
    LV_BUTTONMATRIX_CTRL_HIDDEN | 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BUTTONMATRIX_CTRL_CHECKED | 7,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    LV_BUTTONMATRIX_CTRL_CHECKED | 2, 6, 2
};


static void keyboard_click_event_cb(lv_event_t * e)
{
    lv_obj_t * btnm = lv_event_get_target(e);

    const char * txt = lv_buttonmatrix_get_button_text(btnm, lv_buttonmatrix_get_selected_button(btnm));
    if(txt == NULL) return;

    if (lv_strcmp(txt, "&123") == 0) {
        lv_buttonmatrix_set_map(btnm, default_kb_map_spec);
        lv_buttonmatrix_set_ctrl_map(btnm, kb_ctrl_spc);
        return;
    }
    
    if (lv_strcmp(txt, "abc") == 0) {
        lv_buttonmatrix_set_map(btnm, kb_map_characters);
        lv_buttonmatrix_set_ctrl_map(btnm, kb_ctrl_characters); 
        return;
    }

    if (lv_strcmp(txt, LV_SYMBOL_UP) == 0) {
        const char * const * current_map = lv_buttonmatrix_get_map(btnm);
        
        if (current_map == kb_map_characters) {
            lv_buttonmatrix_set_map(btnm, kb_map_uppercase);
        } 
        else if (current_map == kb_map_uppercase) {
            lv_buttonmatrix_set_map(btnm, kb_map_characters);
        }
        return;
    }
}

static void event_cb(lv_event_t * e)
{
    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t * base_dsc = (lv_draw_dsc_base_t *)lv_draw_task_get_draw_dsc(draw_task);

    if(base_dsc->part == LV_PART_ITEMS) {
        lv_draw_label_dsc_t * label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
        if(label_draw_dsc) {
            
            if(lv_strcmp(label_draw_dsc->text, LV_SYMBOL_UP) == 0) {
                label_draw_dsc->opa = 0;    

                LV_IMAGE_DECLARE(img_star);

                lv_image_header_t header;
                lv_result_t res = lv_image_decoder_get_info(&img_star, &header);
                if(res != LV_RESULT_OK) return;

                lv_area_t img_coords;
                lv_area_set(&img_coords, 0, 0, header.w - 1, header.h - 1);

                lv_area_t button_area;
                lv_draw_task_get_area(draw_task, &button_area);

                lv_area_align(&button_area, &img_coords, LV_ALIGN_CENTER, 0, 0);

                lv_draw_image_dsc_t img_draw_dsc;
                lv_draw_image_dsc_init(&img_draw_dsc);
                img_draw_dsc.src = &img_star;
                lv_draw_image(base_dsc->layer, &img_draw_dsc, &img_coords);
            }
        }
    }
}

lv_obj_t * keyboard_carac(lv_obj_t * screen)
{   
    static lv_style_t style_btn_bg;
    static lv_style_t bg_checked;

    lv_style_init(&style_btn_bg);
    lv_style_set_bg_color(&style_btn_bg, lv_color_hex(0x383533));
    lv_style_set_text_color(&style_btn_bg, lv_color_white());
    lv_style_set_shadow_width(&style_btn_bg, 0);

    lv_style_init(&bg_checked);
    lv_style_set_bg_color(&bg_checked, lv_color_hex(0x23211E));

    lv_obj_t * keyboard = lv_obj_create(screen);
    lv_obj_set_size(keyboard, 770, 230);
    lv_obj_set_flag(keyboard, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(keyboard, lv_color_black(), 0);
    lv_obj_set_style_border_width(keyboard, 1, 0);
    lv_obj_set_style_pad_all(keyboard, 0, 0);

    lv_obj_t * btnm1 = lv_buttonmatrix_create(keyboard);
    lv_buttonmatrix_set_map(btnm1, kb_map_characters);
    lv_buttonmatrix_set_ctrl_map(btnm1, kb_ctrl_characters);
    lv_obj_set_size(btnm1, 800, 270);
    lv_obj_set_style_bg_color(btnm1, lv_color_black(), 0);
    lv_obj_set_style_border_width(btnm1, 0, 0);
    lv_obj_align(btnm1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(btnm1, &style_btn_bg, LV_PART_ITEMS);
    lv_obj_add_style(btnm1, &bg_checked, LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_text_font(btnm1, &lv_font_montserrat_24, LV_PART_ITEMS);
    lv_obj_add_event_cb(btnm1, keyboard_click_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(btnm1, event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(btnm1, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    return keyboard;
}