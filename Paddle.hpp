/*
 * File:   Paddle.h
 * Author: iMer
 *
 * Created on 21. März 2015, 17:10
 */

#ifndef MINILD58_PADDLE_H
#define	MINILD58_PADDLE_H
#include <Engine/SpriteNode.hpp>
class Paddle: public engine::SpriteNode {
protected:
	bool m_ai;
	// max move rate
	float m_rate;
public:
	Paddle(engine::Scene* scene);
	virtual ~Paddle();
	virtual bool initialize(Json::Value& root);
protected:
	void UpdateAI(sf::Time interval);
	virtual void OnUpdate(sf::Time interval);


};

#endif	/* MINILD58_PADDLE_H */

