/*
 * File:   LevelScene.cpp
 * Author: iMer
 *
 * Created on 21. März 2015, 20:01
 */

#include "LevelScene.hpp"
#include "Engine/Factory.hpp"
#include "Engine/Text.hpp"
#include <sstream>

LevelScene::LevelScene(engine::Game* game): Scene(game), m_nextSpawn(sf::Time::Zero), m_points{} {
}

LevelScene::~LevelScene() {
}

void LevelScene::OnUpdate(sf::Time interval){
	engine::Scene::OnUpdate(interval);
	m_nextSpawn -= interval;
	if (m_nextSpawn.asSeconds() <= 0) {
		auto balls = GetChildByID("balls");
		if (balls) {
			engine::Factory::CreateChildFromFile("assets/script/ball.json", balls);
		}
		m_nextSpawn = sf::seconds(10);
	}
}
void LevelScene::AddPoint(bool right) {
	m_points[right] += 1;
	std::ostringstream ss;
	ss << m_points[right];
	auto tn = m_ui->GetChildByID(right?"score_r":"score_l");

	if (tn && tn->GetType() == engine::NT_TEXT)
		static_cast<engine::Text*>(tn)->SetText(ss.str());
	else
		std::cerr << std::string(right?"score_r":"score_l") << " doesnt exist :<" << std::endl;
}