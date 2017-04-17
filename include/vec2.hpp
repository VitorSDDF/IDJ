#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>

class Vec2{
	
	private:
		
		float x,y;

	public:

		Vec2();
		Vec2(float x,float y);

		void SetX(float x);
		void SetY(float y);

		float GetX();
		float GetY();

		Vec2 distance(Vec2 destino);

		Vec2 operator+(Vec2 const &b) const;
		Vec2 operator-(Vec2 const &b) const;
		Vec2 operator*(float b) const;

};

#endif