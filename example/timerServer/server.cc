#include <stdio.h>
#include <time.h>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "easy_reactor.h"
#include "event_loop.h"
#include <iostream>

void buz1(event_loop* loop, void* usr_data)
{
    static unsigned time_counter = 0;
    time_t date_time;
    time(&date_time);
    struct tm* tmNow = localtime(&date_time);
    FILE* fp = (FILE*)usr_data;
    fprintf(fp, "once display ts=%s times:%u\n", asctime(tmNow),++time_counter);
    fflush(fp);
}

void buz2(event_loop* loop, void* usr_data)
{
    time_t date_time;
    time(&date_time);
    struct tm* tmNow = localtime(&date_time);
    FILE* fp = (FILE*)usr_data;
    fprintf(fp, "always display ts %s\n", asctime(tmNow));
    fflush(fp);
}

int main()
{
    event_loop loop;
    config_reader::setPath("myconf.ini");
    std::string ip = config_reader::ins()->GetString("reactor", "ip", "0.0.0.0");
    short port = config_reader::ins()->GetNumber("reactor", "port", 12315);

    tcp_server server(&loop, ip.c_str(), port);

    FILE* fp = fopen("output.log", "w");
    //loop.run_after(buz1, fp, 0,40);
    //loop.run_every(buz2, fp, 0, 50);
    for(int i=0;i<1000000;++i)
    {
        loop.run_after(buz1, fp, 0,40);
        usleep(1);
    }

    loop.process_evs();

    fclose(fp);
    return 0;
}
