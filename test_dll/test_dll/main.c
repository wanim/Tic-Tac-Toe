#include "TTT_interface.h"

#pragma comment(lib,"lib.lib")


GsT gs;  /* make game status structure*/

int main()
{
    wellcome(&gs);

    while (gs.chr != '0')
    {
        draw_menu(&gs);
        get_key(&gs);
    }
}
