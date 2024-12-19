
// main.cpp

// #include "controller.h"
#include "utils.h"
#include "view.h"

extern "C" {
#include "system_controller.h"
}


#include <stdio.h>

static ImGui_setup& imgui_setup = ImGui_setup::Instance();
static View&        view        = View::Instance();
// static Controller&  controller  = Controller::Instance();

int
main()
{
    initConfig();
    initDb();
    printf("Hello, main!\n");

    SystemControlerInit();
    view.ViewInit();

    printf("Showing view...\n");

    Event event;
    bool  is_running = true;
    while(is_running)
    {
        imgui_setup.On_frame_begin();

        while(SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if(event.type == SDL_QUIT)
            {
                is_running = false;
            }
        }

        view.ViewShowWindows();

        imgui_setup.On_frame_end(&view.clear_color);
    }

    view.ViewQuit();
    finalizeDb();
    return 0;
}
