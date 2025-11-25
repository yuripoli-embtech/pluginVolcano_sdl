#include "humidity.h"
#include "main/ui.h"

lv_obj_t * humidity_comp(lv_obj_t * tile){
    
    /*Umidade atual*/
    lv_obj_t * lv_obj_0 = lv_obj_create(tile);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_width(lv_obj_0, 100);
    lv_obj_set_height(lv_obj_0, 40);
    lv_obj_set_style_pad_all(lv_obj_0, 0, 0);
    lv_obj_set_style_border_width(lv_obj_0, 0, 0);


    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, humidity);
    lv_obj_set_y(lv_image_0, 5);

    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_y(lv_label_0, 4);
    lv_label_set_text(lv_label_0, "48%");
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x003D6E), 0);
    lv_obj_set_width(lv_label_0, 70);
    lv_obj_set_style_border_width(lv_label_0, 2, 0);
    lv_obj_set_x(lv_label_0, 25);
    lv_obj_set_style_radius(lv_label_0, 5, 0);
    lv_obj_set_style_border_color(lv_label_0, lv_color_hex(0xE0E0E0), 0);
    lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_top(lv_label_0, 5, 0);
    lv_obj_set_style_pad_bottom(lv_label_0, 5, 0);

    lv_obj_set_y(lv_obj_0, 40);
    lv_obj_set_x(lv_obj_0, 785);
}