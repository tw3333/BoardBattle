#pragma once

//memo
//�}�W�b�N�X�^�e�B�b�N��p���č쐬
//Singleton�݌v


class FontManager {
public:

	static FontManager& GetInstance() {
		static FontManager instance_;
		return instance_;
	}

	//�R�s�[�R���X�g���N�^�폜
	FontManager(const FontManager&) = delete;
	FontManager& operator=(const FontManager&) = delete;
	//���[�u�R���X�g���N�^�폜
	FontManager(FontManager&&) = delete;
	FontManager& operator = (FontManager&&) = delete;



	void CreateFontData();


private:

	FontManager() = default;
	~FontManager() = default;




};


//memo
//�錾	int CreateFontToHandle(char* FontName, int Size, int Thick, int FontType);
//
//�T��	�V�����t�H���g�f�[�^���쐬
//
//����	char* FontName : �쐬����t�H���g��(NULL �ɂ���ƃf�t�H���g�̃t�H���g)
//int Size : �t�H���g�̃T�C�Y(���悻�h�b�g�� - 1:�f�t�H���g�̃T�C�Y)
//int Thick : �t�H���g�̑���(0 �`�@9 - 1:�f�t�H���g�̑���)
//int FontType : �t�H���g�̃^�C�v
//(-1�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@: �f�t�H���g�t�H���g(DX_FONTTYPE_NORMAL �Ɠ���)
//	DX_FONTTYPE_NORMAL�@�@�@�@�@�@ : �m�[�}���t�H���g
//	DX_FONTTYPE_EDGE�@�@�@�@�@�@�@�@ : �G�b�W���t�H���g
//	DX_FONTTYPE_ANTIALIASING�@�@�@�@ : �A���`�G�C���A�X�t�H���g
//	DX_FONTTYPE_ANTIALIASING_4X4�@�@�@ : �A���`�G�C���A�X�t�H���g(4x4�T���v�����O)
//	DX_FONTTYPE_ANTIALIASING_8X8�@�@�@ : �A���`�G�C���A�X�t�H���g(8x8�T���v�����O)
//	DX_FONTTYPE_ANTIALIASING_EDGE_4X4�@ : �A���`�G�C���A�X���G�b�W�t���t�H���g(4x4�T���v�����O)
//	DX_FONTTYPE_ANTIALIASING_EDGE_8X8�@ : �A���`�G�C���A�X���G�b�W�t���t�H���g(8x8�T���v�����O))