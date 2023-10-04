#pragma once
#include "gm_ui_component.h"
#include "gm_easingfunctions.h"

//memo
//パネルを表示



class UIPanel : public UIComponent{
public:
	
	UIPanel(){}

	//引数つきコンストラクタ
	//arg1,2...描写したい左上頂点座標
	//arg3,4...指定した座標からの横幅と高さ
	UIPanel(int x, int y, int width, int height){	
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;
		upper_left_x_ = x;
		upper_left_y_ = y;
		lower_right_x_ = x + width;
		lower_right_y_ = y + height;
	}
	~UIPanel(){}


	void Update(float delta_time) override;
	void Render() override;

	//setter
	void setGraphHandle(int graph_handle) { graph_handle_ = graph_handle; }
	void setColor(int color_code) { color_ = color_code; }
	int GetPosX() { return x_; }
	int GetPosY() { return y_; }
	int GetWidth() { return width_; }
	int GetHeight() { return height_; }
	void SetSize(int width, int height) { width_ = width; height_ = height_ = height; }
	void SetPos(int x, int y) { x_ = x; y_ = y; }
	
	int GetUpperLeftX() { return upper_left_x_; }
	int GetUpperLeftY() { return upper_left_y_; }
	int GetLowerRightX() { return lower_right_x_; }
	int GetLowerRightY() { return lower_right_y_; }


	//easing用の関数
	void SetEasingFunction(std::unique_ptr<EasingFunction> easingFunction) { easing_function_ = std::move(easingFunction); };
	void SetStartEasing(int start_x, float delay);
	void DuringAnimationRender();

private:
	
	int graph_handle_ = 0;

	//easing用の変数
	int start_x_; //アニメーション初めの左頂点座標
	int end_x_;	//アニメーション終わり
	int current_x_ = 0; //アニメーション中
	float time_ = 0; //アニメーション用タイマー
	float duration_ = 0.5f; //何秒間かけるか
	float delay_ = 0; //アニメーション開始までのディレイ
	//bool is_moving_ = false;

	std::unique_ptr<EasingFunction> easing_function_; //Starategy用ポインタ

protected:

	int x_;
	int y_;
	int width_;
	int height_;

	int upper_left_x_ = 0;
	int upper_left_y_ = 0;
	int lower_right_x_ = 0;
	int lower_right_y_ = 0;

	bool is_moving_ = false; //アニメーション中は判定をなくす
	
	//Color
	int color_ = -1;
	

};