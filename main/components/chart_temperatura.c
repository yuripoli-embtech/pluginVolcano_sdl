#include "chart_temperatura.h"
#include "main/ui.h"

static lv_obj_t * create_chart_with_scales(lv_obj_t * parent, const char * title,  const char * hor_text[]);
static void chart_event_cb(lv_event_t * e);
static void draw_event_cb(lv_event_t * e);

static lv_style_t style_title;

lv_obj_t * chart_temperatura(lv_obj_t * tile) {

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_title);
        lv_style_set_text_font(&style_title, font_large);

        style_inited = true;
    }

    lv_obj_t * chart1_cont = lv_obj_create(tile);
    lv_obj_set_height(chart1_cont, 380);
    lv_obj_set_style_max_height(chart1_cont, 380, 0);
    lv_obj_set_width(chart1_cont, 740);
    lv_obj_set_flex_grow(chart1_cont, 1);
    lv_obj_set_align(chart1_cont, LV_ALIGN_CENTER);

    static const char * chart_texts[] = {"00:00", "01:00", "02:00", "03:00", "04:00", "05:00", "06:00", "07:00", "08:00", "09:00", "10:00", "11:00", NULL};
    lv_obj_t * chart1 = create_chart_with_scales(chart1_cont, "Temperatura", chart_texts);

    lv_chart_series_t * ser1 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);

    uint32_t i;
    for(i = 0; i < 12; i++) {
        lv_chart_set_next_value(chart1, ser1, lv_rand(10, 80));
    }
}

static lv_obj_t * create_chart_with_scales(lv_obj_t * parent, const char * title,  const char * hor_text[])
{
    static const int32_t col_dsc[] = {40, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static const int32_t row_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), 40, LV_GRID_TEMPLATE_LAST};

    lv_obj_set_grid_dsc_array(parent, col_dsc, row_dsc);
    lv_obj_set_style_pad_column(parent, 0, 0);
    lv_obj_set_style_pad_row(parent, 0, 0);

    lv_obj_t * label = lv_label_create(parent);
    lv_label_set_text(label, title);
    lv_obj_add_style(label, &style_title, 0);
    lv_obj_set_grid_cell(label, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    lv_obj_t * scale_ver = lv_scale_create(parent);
    lv_scale_set_mode(scale_ver, LV_SCALE_MODE_VERTICAL_LEFT);
    lv_obj_set_grid_cell(scale_ver, LV_GRID_ALIGN_END, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_scale_set_total_tick_count(scale_ver, 10);
    lv_scale_set_major_tick_every(scale_ver, 1);
    lv_scale_set_range(scale_ver, -45, 125);

    lv_obj_t * wrapper = lv_obj_create(parent);
    lv_obj_remove_style(wrapper, NULL, LV_PART_MAIN);
    lv_obj_set_grid_dsc_array(wrapper, NULL, NULL);
    lv_obj_set_grid_cell(wrapper, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 2);
    lv_obj_set_scroll_dir(wrapper, LV_DIR_HOR);

    lv_obj_t * chart = lv_chart_create(wrapper);
    lv_group_add_obj(lv_group_get_default(), chart);
    lv_obj_add_flag(chart, LV_OBJ_FLAG_SCROLL_ON_FOCUS | LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
    lv_chart_set_div_line_count(chart, 0, 12);
    lv_chart_set_point_count(chart, 12);
    lv_obj_set_grid_cell(chart, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_style_border_width(chart, 0, 0);
    lv_obj_add_event_cb(chart, chart_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_width(chart, lv_pct(200));
    lv_obj_set_style_radius(chart, 0, 0);

    lv_obj_t * scale_hor = lv_scale_create(wrapper);
    lv_scale_set_mode(scale_hor, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
    lv_obj_set_grid_cell(scale_hor, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 1, 1);
    lv_scale_set_total_tick_count(scale_hor, 12);
    lv_scale_set_major_tick_every(scale_hor, 1);
    lv_scale_set_text_src(scale_hor, hor_text);
    lv_obj_set_width(scale_hor, lv_pct(200));
    lv_obj_set_height(scale_hor, 40);
    lv_obj_set_style_pad_hor(scale_hor, lv_obj_get_style_pad_left(chart, 0), 0);
    lv_obj_set_style_pad_ver(scale_ver, lv_obj_get_style_pad_top(chart, 0), 0);
    return chart;
}   

static void chart_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    if(code == LV_EVENT_DRAW_TASK_ADDED) {
        lv_draw_task_t * draw_task = lv_event_get_param(e);
        lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task);

        lv_draw_line_dsc_t * draw_line_dsc = lv_draw_task_get_line_dsc(draw_task);
        if(base_dsc->part == LV_PART_ITEMS && draw_line_dsc) {
            lv_area_t obj_coords;
            lv_obj_get_coords(obj, &obj_coords);
            const lv_chart_series_t * ser = lv_chart_get_series_next(obj, NULL);
            if(base_dsc->id1 == 1) ser = lv_chart_get_series_next(obj, ser);

            lv_draw_triangle_dsc_t tri_dsc;
            lv_draw_triangle_dsc_init(&tri_dsc);
            tri_dsc.p[0].x = (int32_t)draw_line_dsc->p1.x;
            tri_dsc.p[0].y = (int32_t)draw_line_dsc->p1.y;
            tri_dsc.p[1].x = (int32_t)draw_line_dsc->p2.x;
            tri_dsc.p[1].y = (int32_t)draw_line_dsc->p2.y;
            tri_dsc.p[2].x = (int32_t)(draw_line_dsc->p1.y < draw_line_dsc->p2.y ? draw_line_dsc->p1.x : draw_line_dsc->p2.x);
            tri_dsc.p[2].y = (int32_t)LV_MAX(draw_line_dsc->p1.y, draw_line_dsc->p2.y);
            tri_dsc.grad.dir = LV_GRAD_DIR_VER;

            int32_t full_h = lv_obj_get_height(obj);
            int32_t fract_uppter = (int32_t)(LV_MIN(draw_line_dsc->p1.y, draw_line_dsc->p2.y) - obj_coords.y1) * 255 / full_h;
            int32_t fract_lower = (int32_t)(LV_MAX(draw_line_dsc->p1.y, draw_line_dsc->p2.y) - obj_coords.y1) * 255 / full_h;
            tri_dsc.grad.stops[0].color = lv_chart_get_series_color(obj, ser);
            tri_dsc.grad.stops[0].opa = 255 - fract_uppter;
            tri_dsc.grad.stops[0].frac = 0;
            tri_dsc.grad.stops[1].color = lv_chart_get_series_color(obj, ser);
            tri_dsc.grad.stops[1].opa = 255 - fract_lower;
            tri_dsc.grad.stops[1].frac = 255;

            lv_draw_triangle(base_dsc->layer, &tri_dsc);

            lv_draw_rect_dsc_t rect_dsc;
            lv_draw_rect_dsc_init(&rect_dsc);
            rect_dsc.bg_grad.dir = LV_GRAD_DIR_VER;
            rect_dsc.bg_grad.stops[0].color = lv_chart_get_series_color(obj, ser);
            rect_dsc.bg_grad.stops[0].frac = 0;
            rect_dsc.bg_grad.stops[0].opa = 255 - fract_lower;
            rect_dsc.bg_grad.stops[1].color = lv_chart_get_series_color(obj, ser);
            rect_dsc.bg_grad.stops[1].frac = 255;
            rect_dsc.bg_grad.stops[1].opa = 0;

            lv_area_t rect_area;
            rect_area.x1 = (int32_t)draw_line_dsc->p1.x;
            rect_area.x2 = (int32_t)draw_line_dsc->p2.x;
            rect_area.y1 = (int32_t)LV_MAX(draw_line_dsc->p1.y, draw_line_dsc->p2.y);
            rect_area.y2 = (int32_t)obj_coords.y2;
            lv_draw_rect(base_dsc->layer, &rect_dsc, &rect_area);
        }
    }
}



