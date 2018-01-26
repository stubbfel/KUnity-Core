#include "kunity.h"
//{ global include region

#include <linux/string.h>

//}
//{ local include region

//}


//{ local define region

//}


//{ local enum region

//}


//{ local typedef region

//}


//{local struct region

#pragma pack(push, 1)

#pragma pack(pop)

//}


//{ local function prototype region

//}

//{ local global var region
static string_builder_s sb;
//}


//{ global function implements region

//}


//{ local function implements region
void putchark(char a)
{
    if (a == '\n')
    {
        const char * c = (const char *)&sb.buffer[0];
        printk(c);
        sb.write_postion = 0;
        memset(sb.buffer, 0, 1024);
        return;
    }

    sb.buffer[sb.write_postion] = a;
    sb.write_postion = (sb.write_postion + 1) % 1024;
}
//}
