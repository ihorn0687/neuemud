#include <stdio.h>
#include <iostream>
#include "modules/data/functions/coreutil.h"
#include "modules/data/functions/writefile.h"

int main(int argc, char* argv[])
{
    writefile::write("modules/data/region", "01", "14:33");
    return 0;
}