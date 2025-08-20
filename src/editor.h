#include "song.h"

namespace Lev4k
{
	// simpler wrapper class for the editor functionality
	class Editor
	{
	public:
		Editor()
		{
		}

		void beginFrame(const unsigned long time);

		void endFrame(const unsigned long time);

		unsigned long GetDeltaTime();

		void printFrameStatistics(int position);

		double handleTrackEvents(Song* track, double position);
		void handleCameraEvents();

	private:
		unsigned long lastFrameStart;
		unsigned long lastFrameStop;

		static const int windowSize = 10;
		int timeHistory[windowSize] = {};

	public:
		POINT lastCursorPos;

		//float camPosX = -28.635f;
		float camPosX = 2.f;
		//float camPosY = -1.601f;
		float camPosY = 0.f;
		//float camPosZ = -4.168f;
		float camPosZ = -20.0;

		float camFowardX = 0;
		float camFowardY = 0;
		float camFowardZ = 1;

		float camRightX = 1;
		float camRightY = 0;
		float camRightZ = 0;

		//float camRotX = 8.455f;
		float camRotX = 0.f;
		//float camRotY = .152f;
		float camRotY = 0.f;
	};
}
