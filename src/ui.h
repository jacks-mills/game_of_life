#ifndef _UI_H
#define _UI_H


struct UI;

int ui_alloc(struct UI **ui);
void ui_free(struct UI *ui);

void ui_init(struct UI *ui, int width, int height);

void ui_set_dead_all(struct UI *ui);
void ui_set_alive(struct UI *ui, int x, int y);

void ui_update();


#endif //_UI_H
