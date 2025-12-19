#include "ui.h"


struct UI {
    int screenWidth;
    int screenHeight;
    int width;
    int height;
};


int ui_alloc(struct UI **ui);
void ui_free(struct UI *ui);

void ui_init(int width, int height);

void ui_set_dead_all(struct UI *ui);
void ui_set_alive(struct UI *ui, int x, int y);

void ui_update();
