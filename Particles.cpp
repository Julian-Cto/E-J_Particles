#include "Particle.h"

Particle::Particle(RenderTarget& target, int numPoints, Vector2i mouseClickPosition)
{

}
void Particle::draw(RenderTarget& target, RenderStates states) const
{

}
void Particle::update(float dt)
{

}
///rotate Particle by theta radians counter-clockwise
 ///construct a RotationMatrix R, left mulitply it to m_A
void Particle::rotate(double theta)
{

}

///Scale the size of the Particle by factor c
///construct a ScalingMatrix S, left multiply it to m_A
void Particle::scale(double c)
{

}

///shift the Particle by (xShift, yShift) coordinates
///construct a TranslationMatrix T, add it to m_A
void Particle::translate(double xShift, double yShift)
{

}