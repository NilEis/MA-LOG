#include "ma-log.h"

int main(int argc, char const *argv[])
{
    LOG(LOG_ALL, "ALL\n");
    LOG(LOG_DEBUG, "DEBUG\n");
    LOG(LOG_ERROR, "ERROR\n");
    return 0;
}
