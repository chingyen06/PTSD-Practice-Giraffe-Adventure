#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        m_Giraffe->move_forward();
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_Giraffe->move_back();
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_Giraffe->move_right();
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Giraffe->move_left();
    }

    if (m_Chest->GetVisibility() && m_Giraffe->IfCollides(m_Chest)) {
        m_Chest->SetVisible(false);
    }

    if (m_Phase == Phase::BEE_ANIMATION) {
        m_Bee->SetLooping(true);
        m_Bee->play();

        if (m_Bee->IfAnimationEnds()) {
            m_Bee->SetLooping(false);
        }
    }


    for (auto& door : m_Doors) {
        if (door->GetVisibility() && m_Giraffe->IfCollides(door)) {
            door->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
    }

    if (m_Phase == Phase::COUNTDOWN) {
        m_Ball->SetVisible(true);

        if (!m_Ball->IsPlaying() && !m_Ball->IfAnimationEnds()) {
            m_Ball->SetLooping(false);
            m_Ball->play();
        }

        if (m_Ball->IfAnimationEnds()) {
            m_Ball->SetLooping(false);
        }
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
