#pragma once
#include "DxLib.h"

//memo
//マジックスタティックを用いて作成
//Singleton設計


class FontManager {
public:

	static FontManager& GetInstance() {
		static FontManager instance_;
		return instance_;
	}

	//コピーコンストラクタ削除
	FontManager(const FontManager&) = delete;
	FontManager& operator=(const FontManager&) = delete;
	//ムーブコンストラクタ削除
	FontManager(FontManager&&) = delete;
	FontManager& operator = (FontManager&&) = delete;



	void CreateFontData();

	int GetCardNameFont () const { return card_name_font_; }
	int GetCardCostFont () const { return card_cost_font_; }
	int GetCardExplanationFont () const { return card_explanation_font_; }
	int GetNoticeTargetNumFont () const { return notice_target_num_font_; }

private:

	FontManager() = default;
	~FontManager() = default;

	int card_name_font_;
	int card_cost_font_;
	int card_explanation_font_;
	int notice_target_num_font_;



};


//memo
//宣言	int CreateFontToHandle(char* FontName, int Size, int Thick, int FontType);
//
//概略	新しいフォントデータを作成
//
//引数	char* FontName : 作成するフォント名(NULL にするとデフォルトのフォント)
//int Size : フォントのサイズ(およそドット数 - 1:デフォルトのサイズ)
//int Thick : フォントの太さ(0 ～　9 - 1:デフォルトの太さ)
//int FontType : フォントのタイプ
//(-1　　　　　　　　　　　　　　　　　　　: デフォルトフォント(DX_FONTTYPE_NORMAL と同じ)
//	DX_FONTTYPE_NORMAL　　　　　　 : ノーマルフォント
//	DX_FONTTYPE_EDGE　　　　　　　　 : エッジつきフォント
//	DX_FONTTYPE_ANTIALIASING　　　　 : アンチエイリアスフォント
//	DX_FONTTYPE_ANTIALIASING_4X4　　　 : アンチエイリアスフォント(4x4サンプリング)
//	DX_FONTTYPE_ANTIALIASING_8X8　　　 : アンチエイリアスフォント(8x8サンプリング)
//	DX_FONTTYPE_ANTIALIASING_EDGE_4X4　 : アンチエイリアス＆エッジ付きフォント(4x4サンプリング)
//	DX_FONTTYPE_ANTIALIASING_EDGE_8X8　 : アンチエイリアス＆エッジ付きフォント(8x8サンプリング))