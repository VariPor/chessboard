#ifndef CELL_H
#define CELL_H
#include <Graph_lib/Graph.h>
#include <Graph_lib/Simple_window.h>

struct Cell : Graph_lib::Button
{
    enum Type {black, white};
    Cell (Graph_lib::Point xy, Graph_lib::Callback cb, Type t);
    void attach (Graph_lib::Window& win) override;
    bool is_black() const { return type == black; }
    static constexpr int size = 100;
private:
    Type type;
    void reset_color();
    /*static void cb_clicked(Graph_lib::Address widget, Graph_lib::Address win)
    {
        auto& btn = Graph_lib::reference_to<Cell>(widget);
        dynamic_cast <Checkerboard&> (btn.window()).clicked(win);
    }*/
};

#endif // CELL_H
