#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main()
{
	const int maxShape = 4;
	IShape* shape[maxShape];
	shape[0] =  new Circle(1.0f);
	shape[1] = new Rectangle({ 20,10 });
	shape[2] = new Circle(5.0f);
	shape[3] = new Rectangle({ 150,100 });

	for (int i = 0; i < maxShape; i++)
	{
		shape[i]->Draw();
	}


	return (0);
}