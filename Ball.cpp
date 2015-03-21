/*
 * File:   Ball.cpp
 * Author: iMer
 *
 * Created on 21. März 2015, 18:23
 */

#include "Ball.hpp"
#include "Engine/Scene.hpp"
#include "Engine/Game.hpp"
#include "LevelScene.hpp"

Ball::Ball(engine::Scene* scene): SpriteNode(scene) {
}

Ball::~Ball() {
}

void Ball::OnUpdate(sf::Time interval) {
	engine::SpriteNode::OnUpdate(interval);
	auto pos = GetGlobalPosition();
	if (pos.x < 0) {
		((LevelScene*)m_scene)->AddPoint(true);
		Delete();
	}else if (pos.x > GetScene()->GetGame()->GetWindow()->getSize().x) {
		((LevelScene*)m_scene)->AddPoint(false);
		Delete();
	}
}
