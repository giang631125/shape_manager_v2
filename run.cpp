#include "menu.h"

int main()
{
    class_menu m_menu;
    m_menu.load_shape_data("data.txt");
    m_menu.show_menu();
    return 0;
}