/*
 * File:   Ball.hpp
 * Author: iMer
 *
 * Created on 21. März 2015, 18:23
 */

#ifndef MINILD58_BALL_HPP
#define	MINILD58_BALL_HPP

#include <Engine/SpriteNode.hpp>


class Ball: public engine::SpriteNode {
public:
	Ball(engine::Scene* scene);
	virtual ~Ball();
	virtual bool initialize(Json::Value& root);
protected:
	virtual void OnUpdate(sf::Time interval);

};

#endif	/* MINILD58_BALL_HPP */

