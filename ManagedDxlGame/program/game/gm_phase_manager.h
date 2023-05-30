#pragma once

//memo
//従来の設計
//BattleシーンのPhaseを管理する

class PhaseManager {
public:

	static PhaseManager* GetInstance(); //インスタンスの取得
	static void Destory(); //インスタンスの削除


private:

	PhaseManager() {};
	~PhaseManager() {};

	static PhaseManager* instance_;


};