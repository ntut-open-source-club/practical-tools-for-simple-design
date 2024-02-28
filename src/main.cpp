#include "App.hpp"

#include "Core/Context.hpp"

#include "Util/Input.hpp"

int main(int, char **) {
    auto context = Core::Context::GetInstance();
    App app;

    while (!context->GetExit()) {
        // TODO: perhaps find a better way to integrate with `Core::Context`
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;

        case App::State::UPDATE:
            app.Update();
            break;

        case App::State::END:
            app.End();
            context->SetExit(true);
            break;
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        context->Update();
    }
    return 0;
}
