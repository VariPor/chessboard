#include "cell.h"
#include "board.h"

Cell::Cell (Graph_lib::Point xy, Graph_lib::Callback cb, Type t)
    : Button { xy, size, size, "", cb},
      type {t}
{}

void Cell::attach (Graph_lib::Window & win)
{
    Button::attach(win);
    reset_color();
}

void Cell::reset_color()
{
    if (!pw) throw ("Cell is not attached");
    if (is_black())
        pw->color(Graph_lib::Color::black);
    else
        pw->color(Graph_lib::Color::white);
}








