#pragma once
#include <iostream>

//memo 
//easing関数の集約クラス

class EasingFunctions {
public:

	static float EaseOutoExpo(float start, float end, float t) {
	
		return(t == 1.0f) ? end : (end - start) * pow(2, 10 * (t - 1)) + start;
	
	}


};