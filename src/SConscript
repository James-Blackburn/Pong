Program("pong",["main.cpp","playing_state.cpp","playing_state.h",
	"game.h","game.cpp","ball.cpp","ball.h","game_state.cpp",
	"game_state.h","menu_state.cpp","menu_state.h",
	"paddle.cpp","paddle.h","sprite.cpp","sprite.h",
	"utilities.h"], LIBS=["SDL","SDL_ttf","SDL_mixer"])
Command(target = "../pong",
        source = "../build/pong",
        action = Copy("$TARGET", "$SOURCE"))
