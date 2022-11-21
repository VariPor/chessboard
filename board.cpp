#include "board.h"
#include "cell.h"

std::string letters ()
{
    std::string s (Checkerboard::N_max, '\0');
    for (int i = 0; i < Checkerboard::N_max; ++i)
        s[i] = 'a' + i;
    return s;
}

std::string digits ()
{
    std::string s (Checkerboard::N_max, '\0');
    for (int i = 0; i < Checkerboard::N_max; ++i)
        s[i] = '1' + i;
    return s;
}

Cell::Type type_of_cell (int i, int j)
{
    if (i % 2 == 0)
        return (j % 2 == 0) ? Cell::black : Cell::white;
    else
        return (j % 2 == 0) ? Cell::white : Cell::black;
}

Checkerboard::Checkerboard (Point xy)
    : My_window {xy, width, height, "Checkboard"},
      x_labels { letters() },
      y_labels { digits() }
{
    size_range (width, height, width, height);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cells.push_back (new Cell {Point {margin + j * Cell::size, margin + (N-1-i)*Cell::size}, cb_clicked, type_of_cell(i, j)});
            attach(cells[cells.size() - 1]);
        }
    for (int i = 0; i < N; ++i)
    {
        // board corners: left up
        constexpr Point lu {margin + Cell::size/2, margin + Cell::size * N + 10};

        // add right button
        constexpr Point rb {margin - 10, margin + N*Cell::size - Cell::size/2};

        x_labels.add(Point {lu.x + i*Cell::size, lu.y});
        y_labels.add(Point{rb.x, rb.y - i * Cell::size});
    }
    attach(x_labels);
    attach(y_labels);
}

