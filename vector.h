
struct vector2
{
	double X, Y;
	vector2(double _X, double _Y) :X(_X), Y(_Y){};
	vector2 operator +(const vector2&V)
	{
		vector2 V_res(X, Y);
		V_res.X += V.X;
		V_res.Y += V.Y;
		return V_res;
	};
	

}