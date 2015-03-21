/*
 * File:   LevelScene.h
 * Author: iMer
 *
 * Created on 21. März 2015, 20:01
 */

#ifndef MINILD58_LEVELSCENE_HPP
#define	MINILD58_LEVELSCENE_HPP

#include <Engine/Scene.hpp>


class LevelScene: public engine::Scene {
private:
	sf::Time m_nextSpawn;
	uint32_t m_points[2];
public:
	LevelScene(engine::Game* game);
	virtual ~LevelScene();
	void AddPoint(bool right);
protected:
	virtual void OnUpdate(sf::Time interval);


};

#endif	/* MINILD58_LEVELSCENE_HPP */

