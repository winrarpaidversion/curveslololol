#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		container.push_back(std::make_shared<Ellipse>(Vector3{ 1,1,1 }, 25, 20, 10, "Ellipse", WHITE));
		container.push_back(std::make_shared<Circle>(Vector3{ 1,1,1 }, 25, "Circle"));
	}
	//void ContainerCurves::AddCurve(float x, float y, float z,float a,float step, float b, float corner, float radius, std::string name, Color color)
	//{
	//	for (const auto& curve : container)
	//	{
	//		auto circle = std::make_shared<Circle>(x, y,z, corner, name);
	//		auto ellipse = std::make_shared<Ellipse>(Vector3{x,y,z},radius,a, b, name, color);
	//		auto helix = std::make_shared<Helix>(Vector3{x,y,z}, radius, step, name, color);
	//		if (circle)
	//		{
	//			container.push_back(circle);
	//		}
	//		if (ellipse)
	//		{
	//			container.push_back(ellipse);
	//		}
	//		if (helix)
	//		{
	//			container.push_back(helix);
	//		}
	//	}
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