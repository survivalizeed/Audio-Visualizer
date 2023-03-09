

#include "Hgine/Includes.h"

using namespace sur;
using namespace sur::Manager;


int main() {

	hgineInitialize(Vec2(1000, 1000), Vec2(1000, 1000), "", "");
	wndCreate("Visualizer by survivalizeed", WS_OVERLAPPEDWINDOW);

	Renderer renderer(Color(7, 7, 7), true, 0.f, false);
	renderer.FPS();
	renderer.DebugConsole(false);

	int* visualizer_intensity = new int(1);
	std::ofstream file("bridge", std::ios::trunc);
	file << visualizer_intensity;
	file.close();

	
	int man = 35;
	int min = 30;

	ParticleSettings settings1;
	//for (int i = 0; i < 185; ++i) {
	//	settings1.colors.push_back(Color(255, 70 + i, 70));
	//}
	settings1.colors.push_back(Color(127, 255, 0));
	settings1.emission = 30000;
	settings1.max_noise = man;
	settings1.min_noise = min;
	settings1.emission_point_minimal = { 0, 0 };
	settings1.emission_point_maximal = { 1000, 1000 };
	settings1.min_distance_to_middle = 200.f;
	settings1.max_distance_to_middle = 300.f;
	ParticleSystem ps1(&settings1, "particle");

	ParticleSettings settings2;
	//for (int i = 0; i < 50; ++i) {
	//	settings2.colors.push_back(Color(255, 205 + i, 255));
	//}
	settings2.colors.push_back(Color(238, 130, 238));
	settings2.emission = 5000;
	settings2.max_noise = 20;
	settings2.min_noise = 15;
	settings2.emission_point_minimal = { 0, 0 };
	settings2.emission_point_maximal = { 1000, 1000 };
	settings2.max_distance_to_middle = 50.f;
	ParticleSystem ps2(&settings2, "particle");

	ParticleSettings settings3;
	//for (int i = 0; i < 50; ++i) {
	//	settings3.colors.push_back(Color(205 + i, 205 + i, 100));
	//}
	settings3.colors.push_back(Color(0, 191, 255));
	settings3.emission = 20000;
	settings3.max_noise = man;
	settings3.min_noise = min;
	settings3.emission_point_minimal = { 0, 0 };
	settings3.emission_point_maximal = { 1000, 1000 };
	settings3.min_distance_to_middle = 100.f;
	settings3.max_distance_to_middle = 200.f;
	ParticleSystem ps3(&settings3, "particle");

	ParticleSettings settings4;
	//for (int i = 0; i < 185; ++i) {
	//	settings4.colors.push_back(Color(255, 130, 70 + i));
	//}
	settings4.colors.push_back(Color(255, 255, 0));
	settings4.emission = 40000;
	settings4.max_noise = man;
	settings4.min_noise = min;
	settings4.emission_point_minimal = { 0, 0 };
	settings4.emission_point_maximal = { 1000, 1000 };
	settings4.min_distance_to_middle = 300.f;
	settings4.max_distance_to_middle = 400.f;
	ParticleSystem ps4(&settings4, "particle");

	ParticleSettings settings5;
	//for (int i = 0; i < 155; ++i) {
	//	settings5.colors.push_back(Color(100, 100 + i, 70));
	//}
	settings5.colors.push_back(Color(220, 20, 60));
	settings5.emission = 50000;
	settings5.max_noise = man;
	settings5.min_noise = min;
	settings5.emission_point_minimal = { 0, 0 };
	settings5.emission_point_maximal = { 1000, 1000 };
	settings5.min_distance_to_middle = 400.f;
	settings5.max_distance_to_middle = 500.f;
	ParticleSystem ps5(&settings5, "particle");

	ParticleSettings settings6;
	//for (int i = 0; i < 50; ++i) {
	//	settings2.colors.push_back(Color(255, 205 + i, 255));
	//}
	settings6.colors.push_back(Color(138, 43, 226));
	settings6.emission = 5000;
	settings6.max_noise = 20;
	settings6.min_noise = 15;
	settings6.emission_point_minimal = { 0, 0 };
	settings6.emission_point_maximal = { 1000, 1000 };
	settings6.min_distance_to_middle = 50.f;
	settings6.max_distance_to_middle = 100.f;
	ParticleSystem ps6(&settings6, "particle");

	bool ignoredist = false;
	Input input;

	float fak = 0.0000005f;

	for (;;) {
		renderer.Clear();
		Vec2f pos = { (f32)sur::RandomRange(1, 999), (f32)sur::RandomRange(1,999) };
		ps1.MoveTowards(pos, 0, *visualizer_intensity, *visualizer_intensity);
		pos = { (f32)sur::RandomRange(1, 999), (f32)sur::RandomRange(1,999) };
		ps2.MoveTowards(pos, 0, *visualizer_intensity, *visualizer_intensity);
		pos = { (f32)sur::RandomRange(1, 999), (f32)sur::RandomRange(1,999) };
		ps3.MoveTowards(pos, 0, *visualizer_intensity, *visualizer_intensity);
		pos = { (f32)sur::RandomRange(1, 999), (f32)sur::RandomRange(1,999) };
		ps4.MoveTowards(pos, 0, *visualizer_intensity, *visualizer_intensity);
		pos = { (f32)sur::RandomRange(1, 999), (f32)sur::RandomRange(1,999) };
		ps5.MoveTowards(pos, 0, *visualizer_intensity, *visualizer_intensity);
		pos = { (f32)sur::RandomRange(1, 999), (f32)sur::RandomRange(1,999) };
		ps6.MoveTowards(pos, 0, *visualizer_intensity, *visualizer_intensity);
		int tmp = *visualizer_intensity;
		if (tmp * 0.5f > 255) tmp /= fak;
		_background = Color((int)(fak * pow(tmp,4)), (int)(fak * pow(tmp, 4)), (int)(fak * pow(tmp, 4)));

		ps1.Bind();
		ps2.Bind();
		ps3.Bind();
		ps4.Bind();
		ps5.Bind();
		ps6.Bind();
		renderer.Render();
	}
}

