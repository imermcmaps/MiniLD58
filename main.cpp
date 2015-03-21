#include "MiniLD58.hpp"
#include <Engine/Factory.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"
int main() {
	engine::Factory::RegisterType("paddle", engine::Factory::CreateChildNode<Paddle>);
	engine::Factory::RegisterType("ball", engine::Factory::CreateChildNode<Ball>);
	MiniLD58 game;
	game.run();
	return 0;
}

