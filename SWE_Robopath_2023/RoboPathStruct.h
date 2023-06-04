#pragma once

namespace Projectdata {
	generic<typename T>
	ref struct RoboPathStruct
	{
		T fZeitstempel;
		T fX;
		T fY;
		T fZ;
		T fXx;
		T fXy;
		T fXz;
		T fYx;
		T fYy;
		T fYz;
		T fZx;
		T fZy;
		T fZz;
	};
}