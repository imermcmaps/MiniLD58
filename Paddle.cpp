/*
 * File:   Paddle.cpp
 * Author: iMer
 *
 * Created on 21. März 2015, 17:10
 */

#include "Paddle.hpp"
#include "Engine/util/Random.hpp"
#include "Engine/util/misc.hpp"
#include "Engine/Scene.hpp"
#include "Engine/Game.hpp"

Paddle::Paddle(engine::Scene* scene): SpriteNode(scene), m_ai(false), m_rate(5.0) {
}
void Paddle::OnUpdate(sf::Time interval) {
	if (m_ai) {
		UpdateAI(interval);
	} else {
		auto pos = m_scene->GetGame()->GetMousePosition();
		SetPosition(GetPosition().x, engine::util::minmax<float>(0, pos.y , m_scene->GetGame()->GetWindow()->getSize().y));
	}
}
Paddle::~Paddle() {
}
void Paddle::UpdateAI(sf::Time interval) {
	// shitty ai
	auto pos = GetPosition();
	auto balls = m_scene->GetChildByID("balls");
	if (!balls) {
		// hyperventilate
		auto rand = engine::util::RandomFloat(-15,15);
		SetPosition(pos.x, engine::util::minmax<float>(0, pos.y + rand(), m_scene->GetGame()->GetWindow()->getSize().y));
		return;
	}
	// get closest ball
	Node* closest = nullptr;
	float dist = std::numeric_limits<float>::infinity();
	for (auto ball : balls->GetChildren()) {
		auto bpos = ball->GetGlobalPosition();
		auto xvel = ball->GetBody()->GetLinearVelocity().x;
		if (abs((pos.x - bpos.x)/xvel)  < abs(dist)) {
			if ((pos.x - bpos.x) < 0 && xvel < 0
					|| (pos.x - bpos.x) > 0 && xvel > 0){
				closest = ball;
				dist = abs((pos.x - bpos.x)/xvel);
			}
		}
	}
	if (closest) {
		SetPosition(pos.x, pos.y + engine::util::minmax(-m_rate, closest->GetPosition().y - pos.y, m_rate));
	}
}

bool Paddle::initialize(Json::Value& root){
	if (!engine::SpriteNode::initialize(root)){
		return false;
	}
	m_ai = root.get("ai", false).asBool();
	return true;
}