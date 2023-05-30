#include "gm_object.h"

void GameObject::Update(float delta_time) {

	for (auto pts : parts_) {
		pts->mesh_->pos_ = pos_ + tnl::Vector3::TransformCoord(pts->ofs_pos_, rot_);
		pts->mesh_->rot_ = pts->ofs_rot_ * rot_;
	}

}

void GameObject::Render(dxe::Camera* camera) {
	
	for (auto pts : parts_) {
		if (!pts->is_render_) continue;
		pts->mesh_->render(camera);
	}

}