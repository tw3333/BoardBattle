#pragma once
#include <iostream>

//memo 
//easingŠÖ”‚ÌW–ñƒNƒ‰ƒX

class EasingFunctions {
public:

	static float EaseOutoExpo(float start, float end, float t) {
	
		return(t == 1.0f) ? end : (end - start) * pow(2, 10 * (t - 1)) + start;
	
	}


};