#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		container.push_back(std::make_shared<Ellipse>(Vector3{ 1,1,1 }, 25, 20, 10, "Ellipse", WHITE, 25, 45, 50));
		container.push_back(std::make_shared<Circle>(Vector3{ 1,1,1 }, 25, "Circle", WHITE, 25, 45, 50));
		container.push_back(std::make_shared<Helix>(Vector3{ 1,1,1 }, 25, 5, "Helix", WHITE, 25, 45, 50));
	}

	/*void ContainerCurves::AddCurveCircle(Vector3(float x, float y, float z), float radius, std::string name, Color color, float angleX, float angleY, float angleZ)
	{
		container.push_back(std::make_shared<Circle>(Vector3{ x,y,z }, 25, "Circle", WHITE, 25, 45, 50));
	}
	void ContainerCurves::AddCurveEllipse(std::shared_ptr<Curve> curve)
	{
		container.push_back(curve);
	}
	void ContainerCurves::AddCurveHelix(std::shared_ptr<Curve> curve)
	{
		container.push_back(curve);
	}*/
	void ContainerCurves::AddCurve(std::shared_ptr<Curve> curve)
	{
		container.push_back(curve);
	}
	//void ContainerCurves::AddCurve(std::shared_ptr<Circle> circle)
	//{
	//	container.push_back(std::make_shared<Circle>());

	//}
	//void ContainerCurves::AddCurve(std::shared_ptr<Ellipse> ellipse)
	//{
	//	container.push_back(std::make_shared<Ellipse>());

	//}
	//void ContainerCurves::AddCurve(std::shared_ptr<Helix> helix)
	//{
	//	container.push_back(std::make_shared<Helix>());

	//}
	void ContainerCurves::NextCurve()
	{
		if (CurrentLevel < container.size() - 1)
		{
			CurrentLevel++;
		}
		else if (container.size() > CurrentLevel)
		{
			CurrentLevel = 0;
		};
	}
	void ContainerCurves::PrevCurve()
	{
		if (CurrentLevel > 0)
		{
			CurrentLevel--;
		}
		else
		{
			CurrentLevel = container.size() - 1;
		};

	}
	/*void ContainerCurves::DrawCurrentContainer()
	{
		if (CurrentLevel >= 0 && CurrentLevel < container.size())
		{
			for (auto& fig : container[CurrentLevel])
			{
				fig->Draw();
			}
		}
	}*/
}