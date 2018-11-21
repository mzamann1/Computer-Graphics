class Color {
private:
	float red, green, blue;

public:
	
	float GetRed()
	{
		return red;
	}

	float GetGreen()
	{
		return green;
	}
	float GetBlue()
	{
		return blue;
	}

	void Set_Color(float r, float g, float b)
	{
		this->red = r;
		this->green = g;
		this->blue = b;
	}
};