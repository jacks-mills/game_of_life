#ifndef _UI_H
#define _UI_H


int  ui_init(int width, int height);
void ui_cleanup(void);

void ui_clear(void);
int  ui_set_alive(int x, int y);
// void ui_set_dead(int x, int y);

void ui_update(void);


#endif //_UI_H
