#pragma once
#include "gm_object.h"

#include <memory>
#include <vector>

#include "../dxlib_ext/dxlib_ext.h"
#include "gm_texture_manager.h"


class ObjBattleStateIcon : public GameObject {
public:

	ObjBattleStateIcon() {}
	~ObjBattleStateIcon(){}

	enum {
		Icon,
		PartsMax
	};

	void Update(float delta_time) override;
	void Render(dxe::Camera* camera) override;

//	static ObjBattleStateIcon* Create(std::vector<std::shared_ptr<dxe::Texture>>& battle_state_icon);
	static std::shared_ptr<ObjBattleStateIcon> Create();
	void SetBattleStateIcon(std::vector<std::shared_ptr<dxe::Texture>>& battle_state_icon) { battle_state_icon_ = battle_state_icon; }
	void SetIconTextute(BattleStateIcon battle_state_icon);
	void SetIsRender(bool flag) { is_render_ = flag; }
	bool GetIsRender() { return is_render_; }

	void SetObjPosToSquarePos(int row, int col);
	
	std::vector<std::shared_ptr<dxe::Texture>>& GetBattleStateIcon() { return battle_state_icon_; }
	//oid SetObjPos(int x, int y);

private:

	bool is_render_ = false;


	std::vector<std::shared_ptr<dxe::Texture>> battle_state_icon_;


};