class Point2d
{

private:
	float x, y;

public:
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}

	Point2d()
	{
	x = 0.0, y = 0.0;
	}

	Point2d(int a,int b)
	{
		x = a; y = b;
	}
	void setPoint(int ax, int by)
	{
		this->x = ax;
		this->y = by;
	}
	


};


