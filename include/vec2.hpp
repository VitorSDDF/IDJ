class Vec2{
	
	private:
		
		float x,y;

	public:

		Vec2(float x,float y);
		Vec2 operator+(Vec2 const &b)const;
		Vec2 operator-(Vec2 const &b) const;

}
