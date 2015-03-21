/*
 * File:   MiniLD58.cpp
 * Author: iMer
 *
 * Created on 21. März 2015, 16:24
 */

#include "MiniLD58.hpp"
#include "Engine/Factory.hpp"
#include "LevelScene.hpp"
MiniLD58::MiniLD58() {
	m_windowTitle = "MiniLD58 Game by iMer (imer.cc)";
	m_scene = engine::Factory::create<LevelScene>("assets/script/level.json", this);
	m_clearColor = sf::Color::Black;
}

MiniLD58::~MiniLD58() {
}

