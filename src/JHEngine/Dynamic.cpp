#include "Dynamic.h"

Dynamic::Dynamic(){}

Dynamic::Dynamic(Object obj, Vector2 velocity) : Object(obj), m_velocity(velocity){}

Dynamic::Dynamic(SDL_Texture* t, Rectangle renderPosition, SDL_Color renderColor, int renderOrder, Vector2 velocity, float rotation){
    m_renderPosition = renderPosition;
    m_renderColor = renderColor;
    m_renderOrder = renderOrder;
    m_velocity = velocity;
    m_rotation = rotation;
    m_texture = t;
}

Dynamic::~Dynamic(){}

void Dynamic::SetVelocity(Vector2 set)
{
    m_velocity = set;
}

Vector2 Dynamic::GetVelocity()
{
    return m_velocity;
}

void Dynamic::Update(float deltaTime)
{
    Object::SetPos(Object::GetPos() + m_velocity * deltaTime);
}

bool Dynamic::CheckCollision(Object collidable)
{
    return m_renderPosition.Intersects(collidable.GetRect());
}