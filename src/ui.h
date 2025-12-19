#ifndef _UI_H
#define _UI_H

#include <stddef.h>
#include "state.h"

void ui_init(size_t width, size_t height);
void ui_update(struct State *s);

#endif //_UI_H
