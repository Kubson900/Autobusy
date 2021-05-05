/** @file */

#include <iostream>

#include "struct.h"
#include "fun.h"

int main(int argc, char* argv[])
{
    Stop* pHeadStop = nullptr;
    if (Przelacznik(argc, argv))
    {
        UploadLine(pHeadStop, argc, argv);
        StopToFile(pHeadStop);
        DeleteAll(pHeadStop);
        std::cout << "Poprawnie zakonczono dzialanie programu!" << std::endl;
        return 0;
    }
    else
    {
        return 0;
    }
}