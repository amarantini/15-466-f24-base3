#include "Mode.hpp"

#include "Scene.hpp"
#include "Sound.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up, space;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	//background ocean wave sound
	std::shared_ptr< Sound::PlayingSample > ocean_wave_sound;
	
	//camera:
	Scene::Camera *camera = nullptr;

	//dolphin whistle
	bool is_whistling = false;

	//dolphin move
	Scene::Transform *dolphin = nullptr;
	float BOUNDARY = 160.0f;
	glm::vec3 dolphin_rotation_euler;
	float rotation_speed = 50.0f;
	float move_speed = 10.0f;

	//chest
	Scene::Transform *chest = nullptr;
	float angle_range = float(M_PI) / 3.0f;
	float found_distance = 5.0f;
	bool is_chest_found = false;
};
