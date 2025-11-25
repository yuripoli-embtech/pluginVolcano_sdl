#include "../inc/manualMode_load.h"
#include "main/inc/ui.h"
#include <stdio.h>

static lv_obj_t * label1;
static lv_obj_t * label2;
static lv_obj_t * bar;

static int time;
static int current_time = 0;
static lv_timer_t * clock_manual_mode;
static lv_obj_t * box;
static lv_obj_t * btn;
static lv_obj_t * btn2;

static void timer_manual_mode_init(lv_timer_t * timer);


lv_obj_t * manualModeLoad_screen(void)
{
    time = ((minutes*60)+seconds); 

    current_time = 0;
    if(clock_manual_mode) {
        lv_timer_delete(clock_manual_mode); 
    }
    clock_manual_mode = NULL;
    
    static lv_style_t main;
    static lv_style_t style_bg;
    static lv_style_t style_indic;
    static lv_style_t style_part_main;

    static bool style_inited = false;
    if(!style_inited) {
        lv_style_init(&main);
        lv_style_set_pad_all(&main, 0);
        lv_style_set_border_width(&main, 0);
        lv_style_set_radius(&main, 0);
        lv_style_set_bg_color(&main, lv_color_black());

        lv_style_init(&style_bg);
        lv_style_set_border_color(&style_bg, lv_color_hex(0xF58220));
        lv_style_set_border_width(&style_bg, 5);
        lv_style_set_pad_all(&style_bg, 0);
        lv_style_set_radius(&style_bg, 13);

        lv_style_init(&style_indic);
        lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
        lv_style_set_bg_color(&style_indic, lv_color_hex(0xF58220));
        lv_style_set_radius(&style_indic, 0);

        lv_style_init(&style_part_main);
        lv_style_set_bg_color(&style_part_main, lv_color_black());

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_add_style(lv_obj_0, &main, 0);

    /* HEADER */
    lv_obj_t * header = header_create(lv_obj_0, "");


    /* PROGRESS BAR */
    bar = lv_bar_create(lv_obj_0);
    lv_obj_add_style(bar, &style_bg, 0);
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);
    lv_obj_add_style(bar, &style_part_main, LV_PART_MAIN);
    lv_obj_set_size(bar, 716, 60);
    lv_obj_set_pos(bar, 42, 214);
    lv_bar_set_range(bar, 0, time);
    
    lv_bar_set_value(bar, 0, LV_ANIM_OFF); 
    
    /* TITLE */
    lv_obj_t * title = lv_label_create(lv_obj_0);
    lv_label_set_text(title, "OPERAÇÃO EM MODO MANUAL");
    lv_obj_align(title, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_width(title, 226);
    lv_obj_set_style_text_font(title, font30, 0);
    lv_obj_set_style_text_color(title, lv_color_white(), 0);
    lv_obj_set_style_x(title, 27, 0);
    lv_obj_set_pos(title, 42, 51);

    lv_obj_t * title_icon = lv_img_create(lv_obj_0);
    lv_img_set_src(title_icon, ajustes_icon);
    lv_obj_align_to(title_icon, title, LV_ALIGN_OUT_RIGHT_MID, 422, 0);
    lv_obj_set_style_img_recolor_opa(title_icon, LV_OPA_COVER, 0); 
    lv_obj_set_style_img_recolor(title_icon, lv_color_white(), 0);

    label1 = lv_label_create(lv_obj_0);
    lv_label_set_text(label1, "EM ANDAMENTO");
    lv_obj_set_style_text_color(label1, lv_color_white(), 0);
    lv_obj_set_style_text_font(label1, font24, 0);
    lv_obj_align_to(label1, bar, LV_ALIGN_OUT_TOP_LEFT, 0, -10);

    /* LABEL TIMER */
    label2 = lv_label_create(lv_obj_0);
    lv_obj_set_style_text_color(label2, lv_color_white(), 0);
    lv_obj_set_style_text_font(label2, font24, 0);
    lv_obj_align_to(label2, bar, LV_ALIGN_OUT_TOP_RIGHT, -90, -10);

    int minutes_display = time / 60;
    int seconds_display = time % 60;
    lv_label_set_text_fmt(label2, "%02dMin%02dSeg", minutes_display, seconds_display);

    /* INFORMATION BOX */
    box = lv_obj_create(lv_obj_0);
    lv_obj_set_flag(box, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_size(box, 452, 158);
    lv_obj_align_to(box, bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 34);
    lv_obj_set_style_bg_color(box, lv_color_black(), 0);
    lv_obj_set_style_radius(box, 13, 0);
    lv_obj_set_style_border_width(box, 5, 0);

    lv_obj_t * info = lv_label_create(box);
    lv_label_set_text(info, "BOX PARA INFORMAÇÃO");
    lv_obj_set_width(info, 148);
    lv_obj_align(info, LV_ALIGN_LEFT_MID, -10, 0);
    lv_obj_set_style_text_font(info, font24, 0);
    lv_obj_set_style_text_color(info, lv_color_white(), 0);

    lv_obj_t * alert = lv_obj_create(box);
    lv_obj_set_size(alert, 100, 100);
    lv_obj_set_style_bg_color(alert, lv_color_hex(0xFF0F00), 0);
    lv_obj_set_style_border_width(alert, 0, 0);
    lv_obj_set_style_radius(alert, 23, 0);
    lv_obj_set_style_pad_all(alert, 0, 0);
    lv_obj_align(alert, LV_ALIGN_RIGHT_MID, 10, 0);
    lv_obj_t * icon = lv_image_create(alert);
    lv_image_set_src(icon, alert1_icon);
    lv_obj_center(icon);

    /* COPIAR PARAMETROS */
    btn2;

    /* BUTTON */
    btn = lv_button_create(lv_obj_0);
    lv_obj_set_size(btn, 100, 100);
    lv_obj_set_style_radius(btn, 23, 0);
    lv_obj_set_style_bg_color(btn, lv_color_hex(0xD1D2D4), 0);
    lv_obj_align_to(btn, bar, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 90);
    lv_obj_set_style_shadow_width(btn, 0, 0);
    lv_obj_t * btn_icon = lv_image_create(btn);
    lv_image_set_src(btn_icon, options_icon2);
    lv_obj_center(btn_icon);
    lv_obj_add_screen_create_event(btn, LV_EVENT_CLICKED, manualMode_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0);

    clock_manual_mode = lv_timer_create(timer_manual_mode_init, 1000, NULL); 

    return lv_obj_0;
}

static void timer_manual_mode_init(lv_timer_t * timer) 
{  
    if(current_time >= time) {
        lv_label_set_text(label1, "CONCLUIDO");
        lv_timer_delete(clock_manual_mode);
        lv_obj_set_style_bg_color(bar, lv_color_hex(0x06A24A), LV_PART_INDICATOR);
        clock_manual_mode = NULL;
        lv_obj_add_flag(label1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(label2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(box, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_pos(bar, 42, 140);
        lv_obj_t * label = lv_label_create(bar);
        lv_label_set_text(label, "PRONTO");
        lv_obj_set_style_text_font(label, font30, 0);
        lv_obj_set_style_text_color(label, lv_color_white(), 0);
        lv_obj_center(label);
    }
    
    current_time++;

    lv_bar_set_value(bar, current_time, LV_ANIM_OFF);

    int remaining_sec = time - current_time;
    if (remaining_sec < 0) {
        remaining_sec = 0;
    }
    
    int minutes_display = remaining_sec / 60;
    int seconds_display = remaining_sec % 60;

    lv_label_set_text_fmt(label2, "%02dMin%02dSeg", minutes_display, seconds_display);

}