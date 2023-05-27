#pragma once
#include <iostream>

//memo 
//easing�֐��̏W��N���X


//�X�g���e�W�[�p�^�[���g�p
class EasingFunction {
public:
	
	virtual float Ease(float t) const = 0;

};

class EaseOutExpo : public EasingFunction {
public:

	float Ease(float t) const override {
		return (t == 1.0f) ? 1.0f : 1.0f - std::pow(2, -10 * t);
	}


};


//Not Used!!!!
class EasingFunctions {
public:

	static float EaseOutoExpo(float start, float end, float t) {
	
		return(t == 1.0f) ? end : (end - start) * pow(2, 10 * (t - 1)) + start;
	
	}

	static float EaseOutExpo(float x) {
		return x == 1.0f ? 1.0f : 1.0f - std::pow(2, -10 * x);
	}


};