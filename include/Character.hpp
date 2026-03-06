#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        float distance = glm::distance(m_Transform.translation, other->GetPosition());

        if (distance < 50.0f)
            return true;

        return false;
    }

    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.
    void move_forward() {
        m_Transform.translation.y += 2.0f;
    }
    void move_back() {
        m_Transform.translation.y -= 2.0f;
    }
    void move_right() {
        m_Transform.translation.x += 2.0f;
    }
    void move_left() {
        m_Transform.translation.x -= 2.0f;
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP
