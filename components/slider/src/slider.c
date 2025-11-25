#include "../inc/slider.h"
#include "main/inc/ui.h"

static lv_obj_t * label_dourar;
static lv_obj_t * label_aquecer;

static void slider1_event_cb(lv_event_t * e);
static void slider2_event_cb(lv_event_t * e);

lv_obj_t * slider_create(lv_obj_t * parent)
{
    static lv_style_t main;
    static lv_style_t style_main;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;
    static lv_style_t style_pressed_color;

    lv_style_init(&main);
    lv_style_set_text_color(&main, lv_color_white());
    lv_style_set_text_font(&main, font24);

    lv_style_init(&style_main);
    lv_style_set_bg_opa(&style_main, LV_OPA_COVER);
    lv_style_set_bg_color(&style_main, lv_color_white());
    lv_style_set_radius(&style_main, LV_RADIUS_CIRCLE);

    lv_style_init(&style_indicator);
    lv_style_set_bg_color(&style_indicator, lv_color_white());
    lv_style_set_radius(&style_indicator, LV_RADIUS_CIRCLE);

    lv_style_init(&style_knob);
    lv_style_set_bg_color(&style_knob, lv_color_white());
    lv_style_set_border_color(&style_knob, lv_color_white());
    lv_style_set_radius(&style_knob, LV_RADIUS_CIRCLE);
    lv_style_set_pad_all(&style_knob, 10); /*Makes the knob larger*/

    lv_style_init(&style_pressed_color);
    lv_style_set_bg_color(&style_pressed_color, lv_color_hex(0x06A24A));

    /* SLIDERS */
    lv_obj_t * sliders = lv_obj_create(parent);
    lv_obj_set_flag(sliders, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(sliders, LV_FLEX_COLUMN);
    lv_obj_set_width(sliders, 800);
    lv_obj_set_height(sliders, 170);
    lv_obj_set_style_bg_color(sliders, lv_color_black(), 0);
    lv_obj_set_style_pad_all(sliders, 0, 0);
    lv_obj_set_style_border_width(sliders, 0, 0);
    lv_obj_set_style_pad_gap(sliders, 0, 0);
    lv_obj_set_style_text_font(sliders, font30, 0);
    lv_obj_set_style_margin_top(sliders, 10, 0);

    /* MESURES INDICATOR */
    lv_obj_t * mesures = lv_obj_create(sliders);
    lv_obj_set_flag(mesures, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_size(mesures, 700, 28);
    lv_obj_set_style_border_width(mesures, 0, 0);
    lv_obj_set_style_margin_left(mesures, 60, 0);
    lv_obj_set_style_pad_all(mesures, 0, 0);
    lv_obj_add_style(mesures, &main, 0);
    lv_obj_set_style_bg_color(mesures, lv_color_black(), 0);
    lv_obj_t * mesures_0 = lv_label_create(mesures);
    lv_label_set_text(mesures_0, "0");
    lv_obj_t * mesures_10 = lv_label_create(mesures);
    lv_label_set_text(mesures_10, "10");
    lv_obj_set_style_x(mesures_10, 65, 0);
    lv_obj_t * mesures_20 = lv_label_create(mesures);
    lv_label_set_text(mesures_20, "20");
    lv_obj_set_style_x(mesures_20, 130, 0);
    lv_obj_t * mesures_30 = lv_label_create(mesures);
    lv_label_set_text(mesures_30, "30");
    lv_obj_set_style_x(mesures_30, 195, 0);
    lv_obj_t * mesures_40 = lv_label_create(mesures);
    lv_label_set_text(mesures_40, "40");
    lv_obj_set_style_x(mesures_40, 260, 0);
    lv_obj_t * mesures_50 = lv_label_create(mesures);
    lv_label_set_text(mesures_50, "50");
    lv_obj_set_style_x(mesures_50, 325, 0);
    lv_obj_t * mesures_60 = lv_label_create(mesures);
    lv_label_set_text(mesures_60, "60");
    lv_obj_set_style_x(mesures_60, 390, 0);
    lv_obj_t * mesures_70 = lv_label_create(mesures);
    lv_label_set_text(mesures_70, "70");
    lv_obj_set_style_x(mesures_70, 455, 0);
    lv_obj_t * mesures_80 = lv_label_create(mesures);
    lv_label_set_text(mesures_80, "80");
    lv_obj_set_style_x(mesures_80, 520, 0);
    lv_obj_t * mesures_90 = lv_label_create(mesures);
    lv_label_set_text(mesures_90, "90");
    lv_obj_set_style_x(mesures_90, 585, 0);
    lv_obj_t * mesures_100 = lv_label_create(mesures);
    lv_label_set_text(mesures_100, "100");
    lv_obj_set_style_x(mesures_100, 650, 0);

    //SLIDER 1 - DOURAR
    lv_obj_t *div_slider1 = lv_obj_create(sliders);
    lv_obj_set_flag(div_slider1, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(div_slider1, lv_color_black(), 0);
    lv_obj_set_height(div_slider1, 71);
    lv_obj_set_width(div_slider1, 800);
    lv_obj_set_style_border_width(div_slider1, 0, 0);
    lv_obj_set_style_pad_all(div_slider1, 20, 0);
    lv_obj_set_style_text_color(div_slider1, lv_color_white(), 0);

    label_dourar = lv_label_create(div_slider1);
    lv_label_set_text(label_dourar, "0");
    lv_obj_align(label_dourar, LV_ALIGN_LEFT_MID, 0, 0);  

    lv_obj_t * slider = lv_slider_create(div_slider1);
    lv_obj_set_size(slider, 650, 5);                        
    lv_obj_center(slider);                                  
    lv_obj_add_event_cb(slider, slider1_event_cb, LV_EVENT_VALUE_CHANGED, NULL);    
    lv_obj_add_style(slider, &style_main, LV_PART_MAIN);
    lv_obj_add_style(slider, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(slider, &style_pressed_color, LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_obj_add_style(slider, &style_knob, LV_PART_KNOB);
    lv_obj_add_style(slider, &style_pressed_color, LV_PART_KNOB | LV_STATE_PRESSED);

    lv_obj_t * img = lv_image_create(div_slider1);
    lv_image_set_src(img, dourar_icon);
    lv_obj_set_height(img, 71);
    lv_obj_align(img, LV_ALIGN_RIGHT_MID, 0, 0);  
    
    //SLIDER 2 - AQUECER
    lv_obj_t *div_slider2 = lv_obj_create(sliders);
    lv_obj_set_flag(div_slider2, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_bg_color(div_slider2, lv_color_black(), 0);
    lv_obj_set_height(div_slider2, 71);
    lv_obj_set_width(div_slider2, 800);
    lv_obj_set_style_border_width(div_slider2, 0, 0);
    lv_obj_set_style_pad_all(div_slider2, 20, 0);
    lv_obj_set_style_text_color(div_slider2, lv_color_white(), 0);

    label_aquecer = lv_label_create(div_slider2);
    lv_label_set_text(label_aquecer, "0");
    lv_obj_align(label_aquecer, LV_ALIGN_LEFT_MID, 0, 0);   

    lv_obj_t * slider2 = lv_slider_create(div_slider2);
    lv_obj_set_size(slider2, 650, 5);                   
    lv_obj_center(slider2);                                  
    lv_obj_add_event_cb(slider2, slider2_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     
    lv_obj_add_style(slider2, &style_main, LV_PART_MAIN);
    lv_obj_add_style(slider2, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(slider2, &style_pressed_color, LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_obj_add_style(slider2, &style_knob, LV_PART_KNOB);
    lv_obj_add_style(slider2, &style_pressed_color, LV_PART_KNOB | LV_STATE_PRESSED);  

    lv_obj_t * img2 = lv_image_create(div_slider2);
    lv_image_set_src(img2, aquecer_icon);
    lv_obj_set_height(img2, 71);
    lv_obj_align(img2, LV_ALIGN_RIGHT_MID, 0, 0); 

    return sliders;
}

static void slider1_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target_obj(e);
    int32_t value = lv_slider_get_value(slider);

    int32_t step = 10;
    value = (value + step / 2) / step * step;

    lv_slider_set_value(slider, value, LV_ANIM_OFF);
    lv_label_set_text_fmt(label_dourar, "%" LV_PRId32, value);
    lv_obj_align(label_dourar, LV_ALIGN_LEFT_MID, 0, 0);
}


static void slider2_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target_obj(e);

    /*Refresh the text*/
    lv_label_set_text_fmt(label_aquecer, "%" LV_PRId32, lv_slider_get_value(slider));
    lv_obj_align(label_aquecer, LV_ALIGN_LEFT_MID, 0, 0); 
}

