#include "Particle.h"

Particle::Particle(RenderTarget& target, int numPoints, Vector2i mouseClickPosition)
	: m_A(2, numPoints)
{
	m_ttl = TTL;
	m_numPoints = numPoints;
	m_radiansPerSec = M_PI * ((float)rand() / (RAND_MAX));
	m_cartesianPlane.setCenter(0, 0);
	m_cartesianPlane.setSize(target.getSize().x, (-1.0) * target.getSize().y);
	m_centerCoordinate = target.mapPixelToCoords(mouseClickPosition, m_cartesianPlane);
	m_vx = rand() % (500 - 100 + 1) + 100;
	m_vy = rand() % (500 - 100 + 1) + 100;
	m_color1 = Color::White;
	m_color2 = Color(rand() % 255, rand() % 255, rand() % 255);
	double theta = (M_PI / 2) * ((float)rand() / (RAND_MAX));
	double dTheta = 2 * M_PI / (numPoints - 1);
	for (int j = 0; j < numPoints; j++)
	{
		float r = rand() % (80 - 20 + 1) + 20;
		float dx = r * cos(theta);
		float dy = r * sin(theta);
		m_A(0, j) = m_centerCoordinate.x + dx;
		m_A(1, j) = m_centerCoordinate.y + dy;
		theta += dTheta;
	}
}	
void Particle::draw(RenderTarget& target, RenderStates states) const
{
	VertexArray lines(TriangleFan, m_numPoints + 1);
	Vector2f center;
	Vector2i(center) = target.mapCoordsToPixel(m_centerCoordinate, m_cartesianPlane);
	lines[0].position = center;
	lines[0].color = m_color1;
	for (int j = 1; j <= m_numPoints; j++)
	{
		Vector2i(lines[j].position) = target.mapCoordsToPixel({ m_A(0, j - 1), m_A(1, j - 1) }, m_cartesianPlane);
		lines[j].color = m_color2;
	}
	target.draw(lines);
}
void Particle::update(float dt)
{
	m_ttl -= dt;
	rotate(dt * m_radiansPerSec);
	scale(SCALE);
	float dx = m_vx * dt;
	m_vy -= G * dt;
	float dy = m_vy * dt;
	translate(dx, dy);
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